CMSC 626 Principles of Computer Security
Project 3
Exercise 9


1.

a.	Name: Faisal Rasheed Khan	University Id: VB02734


b.	The buffer size bx[] as per my UMBC Id is 736, as nearest multiple of 16 for 734 is 736.


c.	The computation of return address in debugger(gdb) is done by checking the $rbp (return base pointer) and $rsp(return stack pointer) adresses. The addresses are also analyzed by 	using x/2 , x/2wx, x/wx in the gdb. Based upon the program function calls analyzing what addresses are to be returned. For more detail understanding purpose of return address 	analyzed from the example given by professor Ram Rastogi in the question.

d.
Used buffer size of 128 because to match the size of char(in main() of stack3.c) while reading both the files in the program or else error will occur.
buf[76] to buf[79] contains value 1
The values to be used are 0x7FFFFFFFE3d0 values from buf[112] to buf[119] i.e. shown below
  buf[112] = 0xd0;
  buf[113] = 0xE3;
  buf[114] = 0xFF;
  buf[115] = 0xFF;
  buf[116] = 0xFF;
  buf[117] = 0x7F;
  buf[118] = 0x00;
  buf[119] = 0x00;
and 0x7FFFFFFFE3d0 values from buf[120] to buf[127]
  buf[120] = 0x40;
  buf[121] = 0xe3;
  buf[122] = 0x55;
  buf[123] = 0x55;
  buf[124] = 0x55;
  buf[125] = 0x55;
  buf[126] = 0x00;
  buf[127] = 0x00;



e.
gcc -g -o stack2 -z execstack -fno-stack-protector stack2.c
touch stack2.c
nano stack2.c
gcc -o stack2 stack2.c
./stack2
gcc -g -o stack2 -z execstack -fno-stack-protector stack2.c
gdb stack2
(gdb) b faisal
(gdb) b khan
(gdb)	run


Breakpoint 1, faisal (str=0x7fffffffe340 "ABCDEFGHIJKLMNOPQRSTUVWXYZ") at stack2.c:17
17        int n = 1;
(gdb) p $rbp
$1 = (void *) 0x7fffffffe330
(gdb) p $rsp
$2 = (void *) 0x7fffffffe030
(gdb) x/2 0x7fffffffe330
0x7fffffffe330: -7216   32767
(gdb) x/2wx 0x7fffffffe330
0x7fffffffe330: 0xffffe3d0      0x00007fff
(gdb) x/2wx 0x7fffffffe338
0x7fffffffe338: 0x555552c3      0x00005555
(gdb) c
Continuing.

Breakpoint 2, khan (str=0x7fffffffe340 "ABCDEFGHIJKLMNOPQRSTUVWXYZ") at stack2.c:8
8         int n = 2;
(gdb) p $rbp
$3 = (void *) 0x7fffffffe020
(gdb) p $rsp
$4 = (void *) 0x7fffffffdd20
(gdb) x/2 0x7fffffffe020
0x7fffffffe020: 0xffffe330      0x00007fff
(gdb) x/2 0x7fffffffe028
0x7fffffffe028: 0x555551df      0x00005555
(gdb) set *0x7fffffffe020=0x5555555552c3
(gdb) set *0x7fffffffe020=0x7fffffffe3d0
(gdb) set *0x7fffffffe028=0x5555555552c3
(gdb) c
Continuing.
khan
Improper return
[Inferior 1 (process 6468) exited normally]
(gdb) q


(gdb) set *0x7FFFFFFFE01C=0x00000001	// for setting value=1


touch stack3.c
nano stack3.c
gcc -o stack3 stack3.c
./stack3
gcc -g -o stack3 -z execstack -fno-stack-protector stack3.c
gdb stack3

touch genbadfile.c
nano genbadfile.c
gcc -o genbadfile genbadfile.c
./genbadfile

touch stack4.c
nano stack4.c
gcc -o stack4 stack4.c
./stack4

sudo sysctl -w kernel.randomize_va_space=0


f.
Challenges:

what addresses to set for the stack pointers were challenging 
Resolved by rbp and rsp and references given in the question.

Hard to find what stack pointer is causing the coredumped.
Resolved it by analyzing the stack frame.

Challenge regarding reading input more than the length
Resolved it by debugging it.

Challenge in generating malicious file
Resolved by applying the given instructions which included what addresses to use

Finding memory addresses were problematic
Resolved by setting breakpoints and debuging it with proper references


g.
Summary of learnings:

In this project, I got hands-on experience with stack smashing attacks using buffer overflow and gdb.
Understood how the stack manages the addresses and return call, based on this attacking the stack.
buffer overflow: learnt about the buffer overflow vulnerability and how it can be used corrupt the stack.
Stack memory management: Learnt about stack memory management, including the layout of stack frames, the role of the stack pointer (rsp), base pointer (rbp), and return addresses.
gdb for debugging: used gdb to set breakpoints, examine memory, and modify values on the stack during runtime.
Understood how to construct malicious inputs that can trigger stack smashing and alter the control flow of a program.


h.

References:

https://dev.to/yjdoc2/series/8954

https://linux.die.net/man/8/tcpdump

https://linux.die.net/man/1/gdb

https://developers.redhat.com/blog/2021/04/30/the-gdb-developers-gnu-debugger-tutorial-part-1-getting-started-with-the-debugger#compiler_options

https://developers.redhat.com/articles/2022/11/08/introduction-debug-events-learn-how-use-breakpoints#next_up

https://linux.die.net/man/1/od

https://learn-us-east-1-prod-fleet01-xythos.content.blackboardcdn.com/blackboard.learn.xythos.prod/5954eb74c7df4/22262378?X-Blackboard-S3-Bucket=blackboard.learn.xythos.prod&X-Blackboard-Expiration=1684011600000&X-Blackboard-Signature=nTZC5Cnn9CJnSduir8myon1CaQqT6P9Lan9Dn%2BpU9mM%3D&X-Blackboard-Client-Id=100208&X-Blackboard-S3-Region=us-east-1&response-cache-control=private%2C%20max-age%3D21600&response-content-disposition=inline%3B%20filename%2A%3DUTF-8%27%27stack2.c&response-content-type=text%2Fx-c&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEMD%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCXVzLWVhc3QtMSJHMEUCIQC%2FeejI7hhB0Knvwmu91X2k%2BzW7aR1D9whnPcXcJFE2IgIgQrHCYFllfxa9sFhw%2BavSQUjj%2FYEHvGQS0zB%2BOBzBH2sqvAUI2f%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NTY5MDM4NjEzNjEiDEBuIO8mTOzcACe9TSqQBTfN0z3%2FUz7zgd7K3wYeaVCNZJbSCxuXWLFJ0x2CuJyl%2Fb3nYBaY09H023Tgd7Jv%2Bkps3vsfHjUwge7aOYcUh0J8tlRrep5GD6bsjq%2BEyIT9usuic94%2BjyR4D%2BGxZEJq9%2B7TaUeUwPSovmfSQI5KAsQ0vdD%2BZ0jdOeNlFR1m1qwN%2FF47tr51%2BiWrgX3BRmFdDkWtvUZ2GWIAiAl1BumtO6at5HscYsYNlIe9YSMgYYs5YXXrd05TRrt%2BY2AegNayoTOTduOitqPK5bDuABMHpfe7KIElVBSSaQ%2F8bd8MPneepWw%2BXCdb72YTThc2Ko3gKMOMxH%2FcpWF0HxIgc5h%2BHVPKouF6f2XH5DqqV7kXbKd%2B8eUIcWBKRTbXiW7gfpfA6itTxgPBqSMkv%2FykwNtdtTkVEsOYpRtbTwzvL6%2BjcP0mwe%2FDIluDqQxCMJ56tcUJluOWkmIP0ZZo%2F5lIsANX9jCys%2F0RcoIhqJiwEcBFiXlCq4XhEltI0v7h65SP37Tb5ZP1ztOdVgOlOmTJwa%2F22sz8U9oTVzUIVzHDKwHSPdhvAtgMTaSfoMxoTfqiKsfQ0yE746nh6T%2F2k0vdNs2NIEsCr%2BcUxhplfeHua%2F634IeyhOSzdrfEVqQuaXCNUADQNkZd4DqqHGRU7QmBW9sW1N7mei5lSp%2FI9xdM4uPkyWqqjj8rd%2BLpF1O2U75dUsU0PIKfO%2FnEL4TWCHUqxZVkJ8OC4wd98h%2BfIo7oBVjJKTLXLFCXjFQcP1E1zIvUmDQTgSgukLeCn75fLprGnAMa1CksY5BT5JgXn4IJ3leAn3lN6b%2F3B4xQNGenS1YQQZGuI%2B1fIV5xCRLeHRk8oC49%2BY9T6lktZneckkiLNRI1nyl0MPXY%2FqIGOrEBb6FZ5FkDhtNNg3xN2Xix1%2B9xdO3lGUL6jRi4FmjfBaucmpOdUukzDQoUDVs61%2B3Bg5w7FhbQ7CdptM%2BdmAHKjXPuVLfPOtr9DhlqWWyJP1T8FZRbciIb8vR4dTC01ImuuJta1uG37RtrEe7C5j4WW1YJxbX%2FhVZwTFWyXpEZy3Ezr9i25cKy1Zj0kHv7GlTqWD1BlHVugtJpTWY5ek9UssgTKhPk7Q0xdT9IQvWsPfxV&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20230513T150000Z&X-Amz-SignedHeaders=host&X-Amz-Expires=21600&X-Amz-Credential=ASIAYDKQORRYRDMJU6OU%2F20230513%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=e3167b0999d098396c1243e39aa4c34c894d87501fb69c9093d5181d8cc0dac3



https://learn-us-east-1-prod-fleet01-xythos.content.blackboardcdn.com/blackboard.learn.xythos.prod/5954eb74c7df4/22262379?X-Blackboard-S3-Bucket=blackboard.learn.xythos.prod&X-Blackboard-Expiration=1684011600000&X-Blackboard-Signature=%2FT1pFaqc8i6TXVNigJmckcJttdiFIb53LtwPEqyXg0o%3D&X-Blackboard-Client-Id=100208&X-Blackboard-S3-Region=us-east-1&response-cache-control=private%2C%20max-age%3D21600&response-content-disposition=inline%3B%20filename%2A%3DUTF-8%27%27stack3.c&response-content-type=text%2Fx-c&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEMH%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCXVzLWVhc3QtMSJIMEYCIQDFrZVEfdk%2FjYdBf%2BLuubnWTzbpkb%2FVz1GxHhnpTAncJgIhAK8ZgnDKpGAXUQOAy1EI%2FlZXPEqpzkg3adUDThvi133ZKrwFCNn%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEQABoMNTU2OTAzODYxMzYxIgx1WwQRi3vnqWYagSUqkAUy0dKYb9UbKpn%2FuRsVT%2BQ85O7nNSWQkA6ENNKhgCs70comwBDBJrdRmMPGBXr3cVBc1lpWxl3yZTeMV3wbNrE%2BTjs6kBNr%2B%2FfYhIBEmwfWTZU1lqweM2MTubMBJmjPLgZdxXNA3P5%2FMy2%2BTrr%2F4znxLyREXma1xx6YI41KA%2BUaVusKysRRDHIRUsHzpXRl2mPjmFFJjyY9unCC9xawh%2BjFcy9%2BFgrAPT30H7WJVHteShyG61JNYxW8SBmTM1uVAfG5sFxQFmJ2v0gTR2rbWQnBwgjjLqnsiBlkjJLh6NLv0aP9h%2B3ZbQNgdJq%2FEorEdoJwp%2BBuP3j4DVtdAjXSlNY%2BjtB41kDhZoy%2BUICgj%2FYnSj1rrNPUKU8VZ2UjX8xtqbeNZko3YXXOw7KQzLNW146vFGgja7rnrU9jbC3yDiIy7G5OS0%2BECINgDH5yfjtLLqNEbBTqLk4jVCkJCnURPl%2Bqki6TVzSm6s31eybdk5iHVt%2F7E5H4tMRvVlTuqojhmDNHOOPrmNEIJN1mdt%2FYA0tg%2BcQ9Qjl7YgVWcpyXTGONhncbR2OQwqvRWD2smfEyopIAC4T0NUJBS5tEVnvhg1jE2m6bYgj9yWYJjsUAEe41W87Aap%2BrgZogYyvpwhUPNAiyRTPodVTvGo264lGL22iqFGuxo0s8TRcR%2BkyjwXdZec%2ByqobGdY0cndh5GGZNSdd9Cqgs68F3qy%2By%2FHo8lgK8O%2FxKqO9Jo%2FZKDWunlexzzJ1sTGA2bYWk38iwu9cA7tTcBdZRVZ3TlD0BUCK1NEuZrl4%2Fs5SR1Ex3RJBKTPvgMIV9ijLli0JrFOGwU%2BtWQVGjvRQok9pSPjJLtsmU%2FHEI27PHAKCfkNSKfVwTm4FcjjD86%2F6iBjqwAWdZ1yajfTtbTICNokUyGpcOaJ38s2OsX9v1JuylSpFCKlbx9mB6EdcCRU9E%2Fp7gALkeA0F9fciDp4k69t2RjvDK%2F7awEHipBFrFivm97rIFJFeI6HxK0l3qqmk4jSnSNY2bVixu6mXkTwjo3kX0f6djOtSkLYI56zbKr37kb2JMIMthDSn7Ow4%2BkH4P1CVPgLQmjojhH8fkIitfAlxfV2PhgcwWo7UTxL3mn38HJVts&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20230513T150000Z&X-Amz-SignedHeaders=host&X-Amz-Expires=21600&X-Amz-Credential=ASIAYDKQORRY5TW7TZFE%2F20230513%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=64818eb7c4c6b2caa8cb797c67ae510f9e067f870e95e541f0fa5a1c407d222e



https://learn-us-east-1-prod-fleet01-xythos.content.blackboardcdn.com/blackboard.learn.xythos.prod/5954eb74c7df4/22262377?X-Blackboard-S3-Bucket=blackboard.learn.xythos.prod&X-Blackboard-Expiration=1684011600000&X-Blackboard-Signature=pUA7Z7wamjIkDEzsLE8TTAYdsEapWXHAtl8vO1GTd4A%3D&X-Blackboard-Client-Id=100208&X-Blackboard-S3-Region=us-east-1&response-cache-control=private%2C%20max-age%3D21600&response-content-disposition=inline%3B%20filename%2A%3DUTF-8%27%27genbadfile.c&response-content-type=text%2Fx-c&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEMD%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCXVzLWVhc3QtMSJHMEUCIQDDa4MHyQS0aEJnwAEzW7Y5tAj3PfVXWNs%2FZrLR34kLbwIgXMQ4arWn1a5H2iioptiZMvVcz5hMVG0w5zO1%2FtlJ21sqvAUI2f%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FARAAGgw1NTY5MDM4NjEzNjEiDEKx1Icgcut5HvE1NCqQBbtm4BmoE0Wc7BWjhyfSa07LsDmvDCDNaETPA10Qd6H1adFB590HnfEn39kgWaS4dK%2FMcumB6SQwF9Ii0sSMzH2SzjllNjKYq%2BRpYBFD4YJbuQFaGaq2M%2BiUNV7F6%2FeC3eapm7NgNGFvLIaIW%2Br1SnQZ%2BVUmSGHwlGNkhbrH84FPIlFJzxjiPs7oIsU%2B%2B8t9iLg%2BmPEmtJ6I2NT%2FTVl3v1KjnHa0miRT0ZR%2FoFqPteDI6gu03Z9bVP2UdYdqIPCYI27yeifNSSnM9UiHteu7Wfq2QCNmxyzcGad1kDFuQO2VlKTjKYfiwKA%2B3U%2BC%2BmB79LHqIdkJ5L7G1U3ZV1R6N6cYH0VPVmcXoQ6gLR8Vf9McbdILfPpywRpQelGCaCP%2Bfjg7IF2utNm8d9nEaWQYfJj8xdWSkD27pADkPm8G7s0AfyuROmLPFLz0VHzV28vQZoAZXQLxUnqSiVSK4cP2oC%2Fb1an%2FODncIfeHWl8KPdLaM2yY5kdPyb%2F%2FBuyN6keXGaBBQx8FKMYi4nUDyi3Hh8r4ZD6%2B3fnNwVmVJUGqSPXE88D6PBqfCPYDL5Efnpkvakb%2F%2FCX9LJQQyq%2B3BFdvNwnmJZQTJ2M9nv0kTM38BYfIl7lhiowjj0cmz2zwvTyu2LDbZc6rbtRB3K1Ej5eSwnTiodPFVhOJIXihiOZAlaUloTip%2FDBWthZybQfZ7ODP4b6ZafL17g95xQ%2BWA6qkG9%2BwFyDzjLNQk2sswdOAJS2gD8NA5e2DQnQPR1UaycuxdHlK4jQweyr09KZAKOM3pa4ghV6%2FaIHk6yxDwkM6DtQtqzhfz4wD%2FPINk12Ar19kivoGsi8Iz%2F3b%2FbEPUxLEtSXA5cFHDIUkwDXMTFfwA%2FgYMObi%2FqIGOrEBNCXMVpmE329%2FlzKNaaaAL7hyBpFXZ6GmsBwYub3CG0QwLtCOZTXJj7LzuoHoqq4bDHXjybGmTcwsMg%2F1QJena5ao94DlFrMXLwcV4lLj9i%2BSR12Go27euNgmNGqFVW%2B9tKH7fyT5d%2FieA2NKYaE4dYJxvzzTyTZ7RHKaVzzpZBFgbkIyIHHNhVA%2BjHsLKxGU2yXSFlgJJ6dB5hzPrnXr6i5gaa8z8B1xOeMIqlvdA%2Foq&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20230513T150000Z&X-Amz-SignedHeaders=host&X-Amz-Expires=21600&X-Amz-Credential=ASIAYDKQORRYUOCW7U2S%2F20230513%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=5b61f65a523594c164d5d4cc37ef42e53d5b6e2149fc8b6caab4e9fbc446ea84



2.	stack2.c

3.	stack3.c

4.	genbadfile.c, badfile

5.	output_images.pdf