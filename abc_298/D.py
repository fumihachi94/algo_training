import sys
import numpy as np

BASE = 998244353
Q = int(input())

S = '1'

for q in range(Q):
    query = list([int(i) for i in input().split()])
    if query[0] == 1:
        S = S+str(query[1])
        # print(S)
    elif query[0] == 2:
        S = S.lstrip(S[0])
        # print(S)
    else:
        n=0
        while(len(S)-9>0):
            S = str(int(S[n:n+9])%BASE)+S[n+9:]
            n=n+1
            # print(n,S)
        # print("OK")
        print(int(S)%BASE)

