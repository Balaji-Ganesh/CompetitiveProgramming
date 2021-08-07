import sys, os
if not os.environ.get("ONLINE_JUDGE"):
    sys.stdin =  open("../in.txt", "r")
    sys.stdout = open("../out.txt", "w")
import time
start_time = time.time()



print("---%s seconds ---" %(time.time() -start_time))