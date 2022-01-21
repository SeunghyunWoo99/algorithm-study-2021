from collections import deque

n, k = map(int, input().split())

dist = [[-1, 0] for _ in range(100001)] #0: 최단시간, 1: 방법의 수
dist[n][0] = 0
dist[n][1] = 1

q = deque([n])

while q:
    now = q.popleft()
    if now == k:
        print(dist[now][0])
        print(dist[now][1])
        break

    for i in (now*2, now+1, now-1):
        if 0 <= i <= 100000:
            if dist[i][0] == -1:
                dist[i][0] = dist[now][0]+1
                dist[i][1] = dist[now][1]
                q.append(i)
            elif dist[i][0] == dist[now][0]+1:
                dist[i][1] += dist[now][1]
