#!/usr/bin/env python3
import sys, socket
socket.setdefaulttimeout(0.1) # set timeout to 100ms
<<<<<<< .mine
host = ".adelaide.edu.au"

with open('dnsmap.txt', 'r') as Lines:
		for line in Lines
			try:
			    line = line.rstrip("\n")
			    test = line + host
			    ip = socket.gethostbyname(host)
			    print(f"{test} resolves to {ip}")
			except:
			    pass # ignore error||||||| .r796
host = "www.adelaide.edu.au"
try:
    ip = socket.gethostbyname(host)
    print(ip)
    print(f"{host} resolves to {ip}")
except:
    pass # ignore error
=======

file1 = open('dnsmap.txt', 'r')
Lines = file1.readlines()
host = ".adelaide.edu.au"

try:
    for line in Lines:
        line = line.rstrip("\n")
        test = line + host
        print(test)
        ip = socket.gethostbyname(test)
        print(f"{test} resolves to {ip}")
        # ip = socket.gethostbyname(line.strip())
        # print(ip)
        # print(f"{host} resolves to {ip}")
except:
    pass # ignore error
>>>>>>> .r823
