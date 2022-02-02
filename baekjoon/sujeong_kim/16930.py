from collections import deque
input = __import__('sys').stdin.readline

n, m, k = map(int, input().split())
gym = [list(input()) for _ in range(n)]
time = [[-1]*(m) for _ in range(n)]
sx, sy, ex, ey = map(int, input().split())
sx -= 1; sy -= 1; ex -= 1; ey -= 1

dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]

time[sx][sy] = 0
q = deque([(sx, sy)])

while q:
    x, y = q.popleft()

    for d in dir:
        for i in range(1, k+1):
            dx = x + d[0]*i
            dy = y + d[1]*i

            if dx < 0 or dx >= n or dy < 0 or dy >= m:
                break
            if gym[dx][dy] == '#':
                break
            if time[dx][dy] != -1 and time[dx][dy] <= time[x][y]:
                break
            if time[dx][dy] == -1:
                time[dx][dy] = time[x][y]+1
                q.append((dx, dy))

print(time[ex][ey])
