from scapy.all import *
server_ip = "ip"
udp_port = 99


def encrypt_text(text):
    result = ""
    for i, char in enumerate(text):
        if i % 2 == 0 and char.isalpha():
            new_char = chr(((ord(char) - ord('a') + 8) % 26) + ord('a'))
        else:
            new_char = char
        result += new_char
    return result

message = "location_md5=0f3744f41e7ce90d39e0b5a6e6241608,airport=nevada25.84,time=15:52,lane=earth.jup,vehicle=2554,fly"
message = encrypt_text(message)
message ="FLY008"+message


#message = "FLY008tokabiwn_ml5=0f3744f41e7ce90d39e0b5a6e6241608,iizpwrb=vedala25.84,biue=15:52,linm=maztp.rux,depiklm=2554,fty"

udp_packet = IP(dst=server_ip)/UDP(dport=udp_port)/Raw(load=message)

# Send the packet
send(udp_packet)

print(f"Sent message: {message} to {server_ip}:{udp_port}")
