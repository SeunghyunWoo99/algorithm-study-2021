import sys
input = sys.stdin.readline

n = int(input())
time, pay = [], []
for _ in range(n):
    a, b = map(int, input().split())
    time.append(a)
    pay.append(b)

dp = [0]*(n+1)

for i in range(n):
    if time[i]+i <= n:
        dp[i+time[i]] = max(dp[i+time[i]], dp[i]+pay[i]) #여태 한 상담 결과값 중 가장 큰 값 저장
    dp[i+1] = max(dp[i], dp[i+1]) #i번째까지 상담한 최대 이익은 i+1번째에 결정됨

print(max(dp))
