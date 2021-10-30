from queue import PriorityQueue
import copy

q = PriorityQueue()

T = int(input())

for t in range(T):
    R, C = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(R)]
    ans = copy.deepcopy(grid)
    
    for i in range(R):
        for j in range(C):
            q.put((2000000 - grid[i][j], (i,j)))

    while not q.empty():
        node = q.get()[1]

        directions = [[0, -1], [0, 1], [1, 0], [-1, 0]]
        for d in directions:
            r, c = node[0] + d[0], node[1] + d[1]
            if not (0 <= r < R and 0 <= c < C): continue
            if ans[node[0]][node[1]] - ans[r][c] > 1:
                ans[r][c] = ans[node[0]][node[1]] - 1
                q.put((2000000 - ans[r][c], (r,c)))

    count = 0    
    for i in range(R):
        for j in range(C):
            count += ans[i][j] - grid[i][j]
    
    print("CASE #" + str(t+1) + ": " + str(count))
