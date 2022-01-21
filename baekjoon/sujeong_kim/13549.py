from collections import deque

a, b = map(int, input().split())

dist = [-1]*100001
q = deque()
q.append(a)
dist[a] = 0

while q:
    now = q.popleft()
    if now == b:
        print(dist[b])
        break
    if now*2 < 100001 and dist[now*2] == -1:
        q.appendleft(now*2) # 추가 시간이 발생하지 않으므로 큐에 먼저 넣어야함
        dist[now*2] = dist[now]
    if now+1 < 100001 and dist[now+1] == -1:
        q.append(now+1)
        dist[now+1] = dist[now]+1
    if now-1 >= 0 and dist[now-1] == -1:
        q.append(now-1)
        dist[now-1] = dist[now] + 1
