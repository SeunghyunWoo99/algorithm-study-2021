from collections import deque

n, k = map(int, input().split())
dist = [[-1, -1] for _ in range(100001)]

q = deque([n])
dist[n][0] = 0
dist[n][1] = n

while q:
    now = q.popleft()
    if now == k:
        route = [k]
        while now != n:
            now = dist[now][1]
            route.append(now)

        print(dist[k][0]) #최소 시간 출력
        for i in reversed(route): #루트 거꾸로 출력
            print(str(i) + " ", end="")
        break

    for i in (now*2, now-1, now+1):
        if 0 <= i <= 100000 and dist[i][0] == -1:
            dist[i][0] = dist[now][0]+1 #시간이 1만큼 더 든다.
            dist[i][1] = now #이전 노드 저장
            q.append(i)
