import sys

N = int(input())
S = list(input())

if 'o' in S:
    if 'x' in S:
        print('No')
    else:
        print('Yes')
else:
    print('No')
