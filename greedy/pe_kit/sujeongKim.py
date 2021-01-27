def solution(n, lost, reserve):
    answer = n
    
    lost_ = set(lost) - set(reserve)
    reserve_ = set(reserve) - set(lost)
    
    for i in lost_:
        if i - 1 in reserve_:
            reserve_.remove(i - 1)
        elif i + 1 in reserve_:
            reserve_.remove(i + 1)
        else:
            answer -= 1
            
    return answer