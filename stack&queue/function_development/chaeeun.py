import math
def solution(progresses, speeds):
    stack = []
    for i in range(len(progresses) - 1, -1, -1):
        stack.append(math.ceil((100 - progresses[i]) / speeds[i]))

    cnt = 0
    max = stack[len(progresses)-1]
    result=[]
    while stack:
        day = stack.pop()
        if max < day:
            max = day
            result.append(cnt)
            cnt =0
        cnt += 1
    result.append(cnt)
    return result