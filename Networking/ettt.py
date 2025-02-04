from scapy.all import *

domain = "ip"
udp_port = 99

def send_encrypted_text(ip, port):
    message_to_send = input("Enter the message to send: ")
    encrypted_msg = encrypted_text("ENT003" + message_to_send)
    packet = IP(dst=ip)/UDP(dport=port)/encrypted_msg
    send(packet)
    print("Message sent:", message_to_send)

    # Wait for response
    response = receive_encrypted_text(ip, port)
    print("Response received:", response)

def receive_encrypted_text(ip, port):
    sniffed_packet = sniff(filter=f"udp and host {ip} and port {port}")
    encrypted_msg = str(sniffed_packet[UDP].payload)
    return encrypted_msg

def encrypted_text(text):
    result = ""
    for i, char in enumerate(text):
        if i % 4 < 2 and char.isalpha():  # Check if the index is in the first half of each pair and if the character is alphabetic
            new_char = chr(((ord(char) - ord('a') - 3) % 26) + ord('a'))
        else:
            new_char = char  # Keep non-alphabetic characters and second half of each pair unchanged
        result += new_char
    return result

# Example usage
send_encrypted_text(domain, udp_port)
