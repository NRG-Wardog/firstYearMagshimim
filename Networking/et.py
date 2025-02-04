from scapy.all import *
import re
import hashlib

START_FOR_FLY = "FLY008"
FLY = 8
MAX_LEN = 100
SERVER_IP = "ip"
UDP_PORT = 99
EXTRACTED_TEXT = ""
LETTER_IN_ALPHABET = 26
REMOVE_DATA = "DAT|ERR|FLY|\\*\\*\\*"
DATA_START = "/10:"
FIRST_ALPHA_BIT = 'a'
START_OF_MESSAGE = "location_md5="
CONSTANT_MESSAGE = ",airport=nevada25.84,time=15:52,lane=earth.jup,vehicle=2554,fly"

def respond(pkt):
    """
    func Handles incoming UDP packets, decrypts the payload, and extracts relevant information.
    :param pkt: The incoming packet :type pkt: scapy.packet.Packet
    :return: The decrypted text from the packet :type: str
    """
    global EXTRACTED_TEXT
    if UDP in pkt and pkt[UDP].sport == UDP_PORT and pkt[IP].src == SERVER_IP:
        if Raw in pkt:
            try:
                text = pkt[Raw].load.decode()
                text = re.sub(rf'{REMOVE_DATA}', '', text)

                decrypted_text = decrypt_text(text.strip())

                match = re.search(rf'{DATA_START}', decrypted_text)
                if match and len(EXTRACTED_TEXT) < MAX_LEN:
                    colon_index = decrypted_text.find(':')
                    new_text = decrypted_text[colon_index + 1:].strip()
                    EXTRACTED_TEXT += new_text
                    print(new_text)
                    if len(EXTRACTED_TEXT) == MAX_LEN:
                        print(EXTRACTED_TEXT)
                        port_my = pkt[UDP].dport
                        send_udp_message(EXTRACTED_TEXT[:MAX_LEN], port_my)
                        EXTRACTED_TEXT = EXTRACTED_TEXT[MAX_LEN:]

                return decrypted_text
            except Exception as e:
                print(f"Error decoding packet: {e}")

def decrypt_text(text):
    """
    func Decrypts the given text by shifting letters based on the decryption key.
    :param text: The text to be decrypted :type text: str
    :return: The decrypted text :rtype: str
    """
    result = ""
    decrypt = 3

    if len(text) >= 3 and text[:2] == '00' and text[2].isdigit():
        number = int(text[2])
        if 0 <= number <= 10:
            decrypt = number
        text = text[3:]
    elif len(text) >= 3 and text[0] == '0' and text[1:3].isdigit():
        number = int(text[1:3])
        if 0 <= number <= 10:
            decrypt = number
        text = text[3:]

    for i, char in enumerate(text):
        if i % 2 == 0 and char.isalpha():
            new_char = chr(((ord(char) - ord(FIRST_ALPHA_BIT) - decrypt) % LETTER_IN_ALPHABET) + ord(FIRST_ALPHA_BIT))
        else:
            new_char = char
        result += new_char

    return result

def send_udp_message(text, my_port):
    """
    the func sends a UDP message with an MD5 hash of the extracted text.
    :param text: The text to be hashed and sent :type text: str
    :param my_port: The source port for the UDP packet :type my_port: int
    """
    hash_object = hashlib.md5(text.encode())
    md5_hash = hash_object.hexdigest()

    message = f"{START_OF_MESSAGE}{md5_hash}{CONSTANT_MESSAGE}"
    message = encrypt_text(message, FLY)
    message = START_FOR_FLY + message

    udp_packet = IP(dst=SERVER_IP) / UDP(sport=my_port, dport=UDP_PORT) / Raw(load=message)

    send(udp_packet)

    print(f"Sent: {message}")

def encrypt_text(text, decrypt):
    """
    Encrypts the given text by shifting letters based on the encryption key.

    :param text: The text to be encrypted :type text: str
    :param decrypt: The decryption key (used in reverse for encryption) :type decrypt: int
    :return: The encrypted text :type: str
    """
    result = ""
    for i, char in enumerate(text):
        if i % 2 == 0 and char.isalpha():
            new_char = chr(((ord(char) - ord(FIRST_ALPHA_BIT) + decrypt) % LETTER_IN_ALPHABET) + ord(FIRST_ALPHA_BIT))
        else:
            new_char = char
        result += new_char
    return result

def main():
    sniff(filter=f"udp and port {UDP_PORT}", prn=respond)

if __name__ == "__main__":
    main()
