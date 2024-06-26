# RC4 key generation

#initialization
key="Computer Security"

def init(S, T):
    keylen = len(key)
    for i in range(256):
        S[i] = i % 256
        T[i] = key[i % keylen]
# ----------------------------

def init_permutation(S, T):
    j = 0
    for i in range(256):
        j = (j + S[i] + ord(T[i])) % 256
        #Swap
        S[i],S[j] = S[j], S[i]
# ----------------------------

def generate_stream_k(S):
    i = j = 0
    while True:
        i = (i + 1) %256
        j = (j + S[i]) % 256
        # swap S[i] and S[j]
        S[i], S[j] = S[j], S[i]
        t = (S[i] + S[j]) % 256
        k = S[t]
        yield k
#-----------------------------
        
# main code
S = [None] * 256
T = [None] * 256
init(S, T)
#print(S, T)
init_permutation(S, T)
print(S)

# generate first 10 random numbers
for i in range(10):
    k = next(generate_stream_k(S))
    print(k)
