from collections import deque

S = int(input())
# (이모티콘 갯수, 클립보드)
q = deque([(1, -1)])
# (이모티콘 갯수, 클립보드: 최단 시간)
visited = {(1, -1): 0}

while q:
    x, clipboard = q.popleft()

    if x == S:
        print(visited[(x, clipboard)])
        break

    # 복사
    if x != clipboard and visited.get((x, x), 0) == 0:
        visited[(x, x)] = visited[(x, clipboard)] + 1
        q.append((x, x))
    # 붙여넣기
    if clipboard != -1 and visited.get((x + clipboard, clipboard), 0) == 0:
        visited[(x + clipboard, clipboard)] = visited[(x, clipboard)] + 1
        q.append((x + clipboard, clipboard))
    # 삭제
    if 0 < x - 1 and visited.get((x - 1, clipboard), 0) == 0:
        visited[(x - 1, clipboard)] = visited[(x, clipboard)] + 1
        q.append((x - 1, clipboard))

# https://he11owor1d.tistory.com/77
