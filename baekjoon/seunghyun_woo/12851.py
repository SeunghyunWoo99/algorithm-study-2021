from collections import deque

N, K = map(int, input().split())

q = deque([N])
# [최단 시간, 최단시간으로 방문한 횟수]
visited = [[-1, 0] for _ in range(100001)]
visited[N][0] = 0
visited[N][1] = 1

while q:
    x = q.popleft()
    if visited[K][0] != -1 and visited[x][0] > visited[K][0]:
        break
    for a in [x - 1, x + 1, 2 * x]:
        if 0 <= a <= 100000:
            # 방문한 적 없는 위치일 때
            if visited[a][0] == -1:
                q.append(a)
                visited[a][0] = visited[x][0] + 1
                visited[a][1] = visited[x][1]
            # 방문한 적 있는 위치이고 현재 여기까지 도달한 시간이 최단 시간일 때
            elif visited[x][0] + 1 == visited[a][0]:
                visited[a][1] += visited[x][1]

print(visited[K][0])
print(visited[K][1])

# https://he11owor1d.tistory.com/73
