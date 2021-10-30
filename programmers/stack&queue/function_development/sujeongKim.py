import math

def solution(progresses, speeds):
    answer = []
    
    maxValue = math.ceil((100 - progresses[0]) / speeds[0])
    count = 1

    for i in range(1, len(progresses)):
        if maxValue < math.ceil((100 - progresses[i]) / speeds[i]):
            maxValue = math.ceil((100 - progresses[i]) / speeds[i])
            answer.append(count)
            count = 1
        else:
            count += 1
    answer.append(count)
        
    return answer
