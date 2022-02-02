import sys
input = sys.stdin.readline

n = int(input())
case = [int(input()) for _ in range(n)]
dp = [1] * 10001

for i in range(2, 10001):
    dp[i] += dp[i-2]

for i in range(3, 10001):
    dp[i] += dp[i-3]

for c in case:
    print(dp[c])
