from scapy.all import *


"""
func print  tracert the way
:param domain:type:strin
"""
def main(domain):
    max_hops = 30
    ttl = 1
    for ttl in range(1, max_hops + 1):
        fullmsg = IP(dst=domain, ttl=ttl) / ICMP()
        ans = sr1(fullmsg, verbose=0, timeout=2)
        if ans is not None and ans.type == 0:
            print("Trace complete.")
            break
        elif ans is not None:
            print(f"{ttl}: {ans.src}")



if __name__ == "__main__":
    domain = input("Insert domain name: ")
    try:
        main(domain)
    except Exception as e:
        print(f"Error : {e}")
