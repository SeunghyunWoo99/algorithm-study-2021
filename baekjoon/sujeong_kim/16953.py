import sys
from collections import deque

a, b = map(int, input().split())

q = deque([(a, 1)])

while q:
    src, t = q.popleft()

    if src == b:
        print(t)
        sys.exit()

    case1 = src * 2
    if case1 <= b:
        q.append((case1, t+1))

    case2 = src*10 + 1
    if case2 <= b:
        q.append((case2, t+1))

print(-1)
