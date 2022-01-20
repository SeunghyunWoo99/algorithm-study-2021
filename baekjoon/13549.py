from collections import deque

N, K = map(int, input().split())

visited = [-1] * 100001
visited[N] = 0
q = deque([N])

while q:
    x = q.popleft()
    if x == K:
        print(visited[x])
    for a in [2 * x, x - 1, x + 1]:
        if 0 <= a <= 100000:
            if visited[a] == -1:
                visited[a] = visited[x] if a == 2 * x else visited[x] + 1
                q.append(a)
            else:
                visited[a] = min(
                    visited[a], visited[x] if a == 2 * x else visited[x] + 1
                )

# https://he11owor1d.tistory.com/74
