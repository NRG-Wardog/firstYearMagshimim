from scapy.all import *


"""
func print ip address of the domain
:param domain:type: string
"""
def main(domain):
    fullmsg = Ether() / IP(dst=domain) / ICMP()
    ans = srp1(fullmsg, verbose=0)
    print(ans[IP].src)



if __name__ == '__main__':
    domain = input("Insert domain name: ")
    try:
        main(domain)
    except Exception as e:
        print(f"Error : {e}")
