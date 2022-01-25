import sys
from collections import deque
MAX = 100001

n, k = map(int, input().split())
queue = deque([n])
dist = [-1]*MAX
dist[n] = 0

while queue:
    i = queue.popleft()

    if i == k:
       print(dist[i])
       break

    if i*2 < MAX and dist[i*2] == -1:
        queue.appendleft(i*2)
        dist[i*2] = dist[i]
    if i-1>=0 and dist[i-1] == -1:
        queue.append(i-1)
        dist[i-1] = dist[i] + 1
    if i+1< MAX and dist[i+1] == -1:
        queue.append(i + 1)
        dist[i+1] = dist[i] + 1