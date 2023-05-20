import sys
import numpy as np

N = int(input())
Q = int(input())

BOX = {}
NUM = {}

for q in range(Q):
    query = list([int(i) for i in input().split()])
    # print(query)
    if query[0] == 1:
        if str(query[1]) in NUM:
            if not query[2] in NUM[str(query[1])]:
                NUM[str(query[1])].append(query[2])
        else:
            NUM[str(query[1])] = [query[2]]
        if str(query[2]) in BOX:
            BOX[str(query[2])].append(query[1])
        else:
            BOX[str(query[2])] = [query[1]]
    elif query[0] == 2:
        if str(query[1]) in BOX:
            BOX[str(query[1])].sort()
            print(*BOX[str(query[1])])
    else:
        if str(query[1]) in NUM:
            NUM[str(query[1])].sort()
            print(*NUM[str(query[1])])


# print(NUM)
