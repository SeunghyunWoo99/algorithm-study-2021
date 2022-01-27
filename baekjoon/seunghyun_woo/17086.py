N, M = map(int, input().split())
matrix = [list(map(int, list(input().split()))) for _ in range(N)]
m = [[0] * M for _ in range(N)]

answers = []

# 인덱스 에러를 핸들링하기 위해 get 함수를 따로 작성
def getMatrix(i, j):
    if i < 0 or j < 0 or i >= N or j >= M:
        return 0
    else:
        return matrix[i][j]


# (i,j)의 안전거리를 bfs로 탐색해서 리턴
def bfs(i, j):
    for d in range(max(N, M)):
        # (i,j)로 부터 거리가 d인 정사각형 테두리의 상어들을 조사한다.
        for n in range(-d, d + 1):
            if 1 in [
                getMatrix(i - d, j + n),
                getMatrix(i + d, j + n),
                getMatrix(i + n, j - d),
                getMatrix(i + n, j + d),
            ]:
                return d


for i in range(N):
    for j in range(M):
        answers.append(bfs(i, j))

print(max(answers))

# https://he11owor1d.tistory.com/78
