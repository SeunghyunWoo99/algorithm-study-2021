A, B = map(int, input().split())
counts = []


def dfs(current, count):
    if current == B:
        counts.append(count)
        return
    elif current > B:
        return
    else:
        dfs(current * 10 + 1, count + 1)
        dfs(current * 2, count + 1)


dfs(A, 1)

if counts:
    print(min(counts))
else:
    print(-1)

# https://he11owor1d.tistory.com/72
