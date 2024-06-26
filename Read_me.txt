Name: Faisal Rasheed Khan
University ID: VB02734
IP Addresses:
Ubuntu22(Entry point using VPN): 130.85.121.106
Kali Linux: 133.228.98.1
Ubuntu20: 133.228.98.3

Challenges:

By default, the policy of ufw is to deny all incoming traffic and this includes ssh too. Thus, if simply enable ufw without allowing ssh connections, you will not be able to ssh into it anymore.
Resolved this by using this command: sudo ufw allow ssh

Was encountering permisiion denied issues. Handled it by using sudo privileges.

Rules were not working after having inserted. Resolved this by reloading the firewall again.

How to confirm that the firewall is blocking what we are attacking. This resolved by tcpdump and log file of the firewall(/var/log/ufw.log)


Summary of overall learning:

Successfully implemented the knowledge of the Denial of Service attacks and its prevention for ICMP flood & smurf attacks, UDP flood, HTTP Slowloris attack, TCP SYN flood attacks using Uncomplicated Firewall ufw

In order to use ufw for the attacks we have to specify the rules for the attacks except for ICMP. ICMP flood attack is a type of Denial of Service (DoS) attack that involves sending a large number of ICMP packets to the victim.

UDP flood attack has deny and reject. For the ufw denying then no response will be generated and for the reject, ICMP error Port unreachable will be sent to the attacker.

HTTP Slowloris DoS attack floods with http requests, here we have permitted and refused connections accordinh to the criteria. It can be seen in the HTTP_ufw.txt file

We will be removing TCP ACK from TCP 3-way connection such that it doesnt ask for reset. with this we have performed attack and prevention using ufw firewall. The task which handles with the photo took more time compared to other.

References:

https://manpages.ubuntu.com/manpages/jammy/en/man8/ufw.8.html
https://wiki.ubuntu.com/UncomplicatedFirewall
https://www.digitalocean.com/community/tutorials/ufw-essentials-common-firewall-rules-and-commands
https://www.kali.org/tools/hping3/
https://nmap.org/book/man.html