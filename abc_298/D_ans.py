from collections import deque

MOD = 998244353
Q = int(input())
S = deque()
S.append(1)
ans = 1

for _ in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        ans = (ans*10+query[1])%MOD
        S.append(query[1])
    elif query[0] == 2:
        ans = (ans-S[0]*pow(10,len(S)-1, MOD))%MOD
        S.popleft()
    else:
        print(ans)



# ==========================================
# 以下だと実行時間が3308msでタイムアウトしてしまう
# ==========================================

# import sys
# from collections import deque

# MOD = 998244353
# Q = int(input())
# S = deque()
# S.append(1)
# ans = 1

# for _ in range(Q):
#     query = list([int(i) for i in input().split()])
#     if query[0] == 1:
#         ans = (ans*10+query[1])%MOD
#         S.append(query[1])
#     elif query[0] == 2:
#         ans = (ans-S[0]*pow(10,len(S)-1))%MOD
#         S.popleft()
#     else:
#         print(ans)

