import sys
input = sys.stdin.readline

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
dp = [[0]*n for _ in range(n)]
dp[0][0] = 1

for y in range(n):
    for x in range(n):
        if board[y][x] == 0:
            continue
        if y+board[y][x] < n:
            dp[y+board[y][x]][x] += dp[y][x]
        if x+board[y][x] < n:
            dp[y][x+board[y][x]] += dp[y][x]

print(dp[n-1][n-1])
