CMSC 626 Principles of Computer Security
Project
Exercise 4
Faisal Rasheed Khan								Shrenik PolySetty
VB02734									AZ61492
vb02734@umbc.edu								
1.
a. Team Information:

i. Name: Faisal Rasheed Khan
       University Id: VB02734
ii. Name: Shrenik PolySetty
       University Id: AZ61492
       
b. Prime Number, P = 1065601
Primitive root, ? = 7
Xa = 139278
Xb = 111689
Key = 159571

c. nc -l 12345
nc 130.85.220.34 12345
python3 diffehellman.py  | nc 130.85.220.34 12345
python3 diffehellman.py <vm1pipe | nc 130.85.220.34 12345 >vm1pipe
nc -l 12345 <vm2pipe | python diffehellman.py >vm2pipe
mkfifo vm1pipe
nc -l 12345 | python3 diffehellman.py
python3 diffehellman.py
cat tcpdumpcapture.cap
nano diffehellman.py
ls
ifconfig -a  
tcpdump -D 
tcpdump -n -i ens160 -w tcpdumpcapture.cap host 130.85.121.106 and port 12345
tcpdump -n -i ens160 -w tcpdumpcapture.cap host 130.85.220.34 and port 12345
tcpdump -n -i ens160 -w tcpdumpcapture.cap host 130.85.121.106 and port 12345
tcpdump -r capture.pcap
tcpdump -n -i ens160 -w vm1capture2.pcap host 130.85.220.34  



d. The challenges faced were:
* While encrypting and decrypting the key, faced issue because key was of int type text
Resolved this issue with the help of converting the int to str ,encoding and decoding with ‘utf-8’
* Faced issue while connecting to the other Virtual Machine to send the encrypted plain text using netcat command
Resolved the issue by passing the command of netcat to subprocess.Popen()
* While encrypting and decrypting the pain text and cipher text, faced issue of unable to decode with ‘utf-8’ as it was in other format
       Resolved by removing unnecessary encoding.
* Faced challenges while using wireshark, tshark as access to install that was not there
Resolved using tcpdump command
* The tcpdump command was capturing every data incoming
       Resolve by applying proper filters
* For tcpdump command, which interface to use to capture the data was a problem
Resolved by using this command, tcpdump -D

e. Successfully implemented the Diffe-Hellman Key Exchange Algorithm to encrypt and decrypt the text over the communicating channels between two virtual machines while calculating the shared key with their respective private keys, where keys are generated using prime number, primitive root and private key. Learnt different ways of sending the data via command line arguments or incorporating everything in the python file. Successfully implemented the tcpdump/wireshark capture to capture the real time packets sent/received. Can store tcpdump/wireshark capture using .pcap or .cap extension.

f. References:
CH02-CompSec4e_accessible_L03 (blackboardcdn.com)
How To Use Netcat to Establish and Test TCP and UDP Connections | DigitalOcean
	L07-CH21-CompSec4e_accessible (blackboardcdn.com)
       Primitive Root - Algorithms for Competitive Programming (cp-algorithms.com)
       tcp_client.py
       tcp_server.py
       RC4-KeyGeneration(1).py
       subprocess — Subprocess management — Python 3.11.2 documentation
       Tcpdump Command in Linux | Linuxize
       
       
       

       
       
       
       

