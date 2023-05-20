import sys
import numpy as np

N = int(input())
# data = [[int(c) for c in l.strip()] for l in sys.stdin.readline()]

A_tmp = list([input().split() for _ in range(N)])
B_tmp = list([input().split() for _ in range(N)])

A = A_tmp
B = B_tmp
for n in range(N):
    A[n] = list(map(int, A_tmp[n]))
    B[n] = list(map(int, B_tmp[n]))
    n=n+1

# print(A)
# print(B)

Apy = np.array(A)
Bpy = np.array(B)

flag = 0
for k in range(4):
    Apy_rot = np.rot90(Apy, k=k)
    AB_t = Apy_rot+Bpy
    if np.count_nonzero(Apy==1) == np.count_nonzero(AB_t==2):
        flag=1
        break

if flag:
    print('Yes')
else:
    print('No')



