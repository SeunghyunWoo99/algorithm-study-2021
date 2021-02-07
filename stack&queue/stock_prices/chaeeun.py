from collections import deque

def solution(prices):
    my_dequeue = deque(prices)
    result=[]
    # queue 사용
    for i in range(len(prices)):
        cnt=0
        k = my_dequeue.popleft()
        for j in my_dequeue:
            if k<=j:
                cnt+=1
            else:
                cnt+=1
                break
        result.append(cnt)
    return result