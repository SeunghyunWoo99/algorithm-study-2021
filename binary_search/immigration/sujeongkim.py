def solution(n, times):
    start = 0
    answer = 0
    end = max(times) * n

    while end >= start:
        time = (end + start) // 2
        curN = 0
        
        for i in times:
            curN += time // i
            if curN > n: break
        
        if curN >= n:
            answer = time
            end = time - 1
        elif curN < n:
            start = time + 1
        
    return answer