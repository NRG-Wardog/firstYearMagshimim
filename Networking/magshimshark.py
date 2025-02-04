from scapy.all import *
WEDDER_IP = "ip"
WEDDER_PORT = 77
HTTP_PORT = 80
OK_MES = b"200"
GET_MES = b"GET"

"""
function filter DNS RESPONSE
:param packet:type:str
"""
def filter_DNS_RESPONSE(packet):
    return DNSRR in packet
"""
function filter WEDDER RESPONSE
:param packet:type:str
"""
def filter_WEDDER_RESPONSE(packet):
    return TCP in packet and packet[TCP].sport == WEDDER_PORT and Raw in packet and OK_MES in packet[Raw].load
"""
function filter HTTP GET
:param packet:type:str
"""
def filter_HTTP_GET(packet):
    return TCP in packet and packet[TCP].dport == HTTP_PORT and Raw in packet and GET_MES in packet[Raw].load
"""
function print DNS RESPONSE
:param packet:type:str
"""
def print_HTTP_GET(packet):
    raw_load = packet[Raw].load.decode()
    get_line = raw_load.split('\r\n')[0]
    url = get_line.split(' ')[1]
    print(f"{url}")

"""
function print WEDDER
:param packet:type:str
"""
def print_wedder(packet):
    print(f"{packet[Raw].load.decode()}")

"""
function print DNS RESPON
:param packet:type:str
"""
def print_address_and_domain(packet):
    ip = packet[DNSRR].rdata
    domain = packet[DNSRR].rrname.decode()
    print(f"{domain} ==> {ip}")
"""
function sniffer mode
:param choice:type:int
"""
def sniffer_mode(choice):
    try:
        if choice == 1:
            sniff(lfilter=filter_DNS_RESPONSE, prn=print_address_and_domain)
        elif choice == 2:
            sniff(lfilter=filter_WEDDER_RESPONSE, prn=print_wedder)
        elif choice == 3:
            sniff(lfilter=filter_HTTP_GET, prn=print_HTTP_GET)
        elif choice == 4:
            print("E-mails sniffing is not implemented yet.")
    except Exception as e:
        print(f"Sniffing error: {e}")

def main():
    print("Welcome to Magshishark!")
    while True:
        print("Please select sniffing state:")
        print("1. DNS")
        print("2. Forecast")
        print("3. HTTP")
        print("4. E-mails")
        print("Or select 0 to Exit:")

        try:
            choice = int(input())
            if choice == 0:
                print("Exiting... Goodbye!")
                break
            elif choice in [1, 2, 3, 4]:
                sniffer_mode(choice)
            else:
                print("Invalid choice, please try again.")
        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()
