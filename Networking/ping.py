from scapy.all import *
from datetime import datetime, timedelta

TIMES = 3
MILE = 1000
"""
func print 3 pings with avg
:param domain  :type: string
"""
def main(domain):
    avg_time = 0
    for i in range(TIMES):
        start_time = datetime.now()
        fullmsg = IP(dst=domain)/ICMP()
        ans = sr1(fullmsg, timeout=1, verbose=0)
        if ans:
            elapsed_time = datetime.now() - start_time
            time_takes = int(elapsed_time.total_seconds() * MILE)
            avg_time += time_takes
            print(f"Reply from {ans.src}: time={time_takes}ms")
        else:
            print("Request timed out.")
    if avg_time > 0:
        avg_time /= TIMES
        avg_time = int(avg_time)
        print(f"Summary: Average={avg_time} ms")



if __name__ == "__main__":
    domain = input("Insert domain name: ")
    try:
        main(domain)
    except Exception as e:
        print(f"Error : {e}")
