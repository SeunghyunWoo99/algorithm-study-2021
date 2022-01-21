from collections import deque

N, K = map(int, input().split())

q = deque([N])
visited = [[-1, -1] for _ in range(100001)]
visited[N][0] = 0
path = []

while q:
    x = q.popleft()
    if x == K:
        print(visited[x][0])
        while x != -1:
            path.append(x)
            x = visited[x][1]
        print(*path[::-1])

    for a in [x - 1, x + 1, 2 * x]:
        if 0 <= a <= 100000:
            if visited[a][0] == -1:
                visited[a][0] = visited[x][0] + 1
                visited[a][1] = x
                q.append(a)

# https://he11owor1d.tistory.com/76
