CMSC 626 Principles of Computer Security
Project 2
Exercise 8


1.

a.	Team Information:

	i.	Name: Faisal Rasheed Khan	University Id: VB02734
	ii.	Name: Shrenik PolySetty		University Id: AZ61492

b.	Challenges:

	The first challenge we faced is setting up the SOCKS proxy.
	Resolved it with the following commands:
		ssh -D 0.0.0.0:22222 -f -q -N Faisal@130.85.121.106
		ssh -o ProxyCommand='nc -x 127.0.0.1:22222 %h %p' crsuser@133.228.98.1
	
	Was facing issue in creating SSL certificate.
	Resolved it by refering https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-apache-in-ubuntu-22-04
		
	While running the web page from our laptop, it wasnt authenticating the user and password which we created.
	Resolved it by adding password file to appropriate location and also ensuring .conf has the password file

	Faced issue while updating the ip address and name here C:\Windows\System32\drivers\etc\hosts
	Resolved it by using Administrative privileges.

	Sometimes after modification of the apache2, the changes werent reflecting.
	Resolved it by using: sudo systemctl restart apache2. 

c.	Summary of our learning:

	Understood and implemented the working of a SOCKS tunnel, a circuit-level gateway, that allows clients to access servers through a proxy server.

	TLS (Transport Layer Security) is a protocol used to provide secure communication over the internet, which involves using a public key and a private key to encrypt and decrypt data 	transmitted.

	Learned its use & creation of self-signed certificates such that these certificates will be used to establish a secure connection between the clients and the server.

	From Excercise 7, Applied the learnings of ARP (Address Resolution Protocol) and MITM (Man in The Middle), where an attacker intercepts communication between two parties and can 	eavesdrop or manipulate the communication.

	Learned the differences of using HTTP and HTTPS protocol. From Excercise 8, the attacker eavesdrop the communication by capturing the authentication user and password (i.e. 	credentials) whereas HTTPS the credentials are not captured, neither HTTP Content nor Header information.

	HTTPS (Hypertext Transfer Protocol Secure) is a secure version of HTTP that uses TLS to provide encryption and authentication. We need to use HTTPS-based communication to ensure 	confidentiality between communication.

	Learned how to enable authentication of web pages using Apache Web Server to prevent unauthorized access to sensitive information.

	By attacking the HTTP, encoded the User and Password with Base64.

	Understood the MITM atacking by doing role reversal of our team.



References:

https://learn-us-east-1-prod-fleet01-xythos.content.blackboardcdn.com/blackboard.learn.xythos.prod/5954eb74c7df4/21843774?X-Blackboard-S3-Bucket=blackboard.learn.xythos.prod&X-Blackboard-Expiration=1682845200000&X-Blackboard-Signature=RGA746DF4R3ELuyPBBHsZCheP9pTOiCb7Kocor4fAMw%3D&X-Blackboard-Client-Id=100208&X-Blackboard-S3-Region=us-east-1&response-cache-control=private%2C%20max-age%3D21600&response-content-disposition=inline%3B%20filename%2A%3DUTF-8%27%27L16-CH09-IPS%25281%2529.pdf&response-content-type=application%2Fpdf&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEHwaCXVzLWVhc3QtMSJHMEUCIQDrknicpkRjgKg6F6t518Fm06a%2BrYXU31xxHw%2F26hY56wIgTBkkoARNSbGLnSx1nclZcVnS%2BmDQt2C3cb9EubQgF1UqvAUIhf%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NTY5MDM4NjEzNjEiDAjz%2Fviylk0kf7gzViqQBZZTyQNqpZ8FcRltmQWaovdU%2Fh8sF9A6OqPbU2thzlIjRivinnrixXbKdgil2LymmbBwrzE422sOUAD%2FLO418ZszrqAbvjTgqfGaMKZYz9AyLgMY5AN9VvnVLxCg7aL46mlGgLu%2FtPjwUkIJTsoU3A2d1UE3b67VD%2FVfJB%2BGdT19JFm590fq%2Bco0LtKuIsWN3IIS9MjWRfMMZovBAqCYTnb2A7Bp7HBoANILSllsnUDJbetf8OnhMMqRHBEUFpM9tHwvE5yfzWuxgsUXPKt4CQ9KJk1%2BZVJUF2Hp9dys%2F9eavBhTImYNYEooc1xOGart9IyTOzzEH2osCh9rq%2F6EEM1%2Fe2GAbdMNbd0kEGqeL1kIijrEcW5M1KxQqTXdN0it%2BiRz4CER%2BomwWSu8CV%2Bk9%2B%2B9%2FsU%2BvDkerK8wXvlV6bBSjogp1Um0%2B4%2BsRvGgqs4YjrCyyMZLuVh2lkfd4EVOugWfMsHeh%2BEGKelysN0bv0wvjlAnukzyZmpAEdOPEZu3YiM1TWV%2BgHr5aSM%2BM5TbBhCkmWXSv7a8XuS602FZzwNqr32iIWS%2BVWec%2FAr3PPWjxd51ZA4NHAuXNP5t6brnio06UDXpQeCKs%2BVXiHXTX4YlVdcXzIiZU1br65zfkCFm%2BKQkXOfQGwd7NK13SXBXpqNM7oSj1wTdLC1wvc%2F91rYrVzT1rjIXZxeu6vjfrrRl7UUxojBDzxhgdnR82cgjvOIbVXwDLoVNXaZNeWRSJxCBmEonhielyL4jKofWtBsdl%2BQ4IR0k7sm6wVYJna1uX8Gmat%2FhIP4IbG8%2BZGAlIiNoa6Zgdz%2F7xWYv3Jbe1xCgKCRQIhe6UtCrCR2dVR7Kx9s4n7NoXMk%2Bly%2B8oz1A7%2FOcMPbLt6IGOrEBVtynkEEevoNLgGbGaIfbWpRJ8TleSSuiPs01oTV0gKaKmUIVp4TIlQTTMnLTZgMBtrpX02AwWe%2BcGam9XJHUXx%2FCtDzU3hldY3z4Xdlbpr4XfJl6KNwiCAWEBnYI3LeCK8StWSIlgVwbT4cPOB4ZgVKdVbKCP8kAPgZHWLzCWGGA7gpoiP%2FeCMnLWDgv2a0eDRW8IxmedB85qCyvoXMgXEEd3bjZfleDicP1C3N%2BrGE7&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20230430T030000Z&X-Amz-SignedHeaders=host&X-Amz-Expires=21600&X-Amz-Credential=ASIAYDKQORRYY25THIKG%2F20230430%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=09403c00a0e8adc13586332365c2bc949d8f232ac30ae1634177de540283c792


https://tutorialedge.net/security/arp-spoofing-for-mitm-attack-tutorial/

https://www.digitalocean.com/community/tutorials/how-to-create-a-self-signed-ssl-certificate-for-apache-in-ubuntu-22-04

https://httpd.apache.org/docs/2.4/mod/quickreference.html

https://en.wikipedia.org/wiki/Base64
