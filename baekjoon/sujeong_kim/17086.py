from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dist = [list(map(int, input().split())) for _ in range(n)]

dir = [(1, -1), (-1, 1), (1, 0), (0, 1), (1, 1), (-1, -1), (-1, 0), (0, -1)]
q = deque([])

def bfs():
    while q:
        i, j = q.popleft()

        for d in dir:
            if not ((0 <= i+d[0] < n) and (0 <= j+d[1] < m)): #보드 밖으로 나가지 않게
                continue
            if not dist[i+d[0]][j+d[1]]:
                dist[i+d[0]][j+d[1]] = dist[i][j]+1
                q.append((i+d[0], j+d[1]))

for i in range(n):
    for j in range(m):
        if dist[i][j] == 1:
            q.append((i, j))

bfs()
print(max(max(dist))-1)
