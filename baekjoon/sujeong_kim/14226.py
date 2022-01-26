from collections import deque

s = int(input())

dp = [[-1]*(1001) for _ in range(1001)]
dp[1][0] = 0

#화면의 이모티콘, 클립보드 이모티콘
q = deque([(1, 0)])

while q:
    sc, clip = q.popleft()
    if sc == s:
        print(dp[s][clip])
        break

    if dp[sc][sc] == -1:
        dp[sc][sc] = dp[sc][clip]+1
        q.append((sc, sc))

    if 2 <= sc+clip <= 1000 and dp[sc+clip][clip] == -1:
        dp[sc+clip][clip] = dp[sc][clip]+1
        q.append((sc+clip, clip))

    if 2 <= sc-1 <= 1000 and dp[sc-1][clip] == -1:
        dp[sc-1][clip] = dp[sc][clip]+1
        q.append((sc-1, clip))
