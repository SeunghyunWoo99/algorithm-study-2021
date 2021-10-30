def solution(name):
    change = [min(ord(name[i]) - ord('A'), ord('Z') - ord(name[i]) + 1) for i in range(len(name))]
    idx = 0
    answer = 0
    
    while True:
        answer += change[idx]
        change[idx] = 0
        if sum(change) == 0:
            break
        
        left, right = 1, 1
        while change[idx - left] == 0:
            left += 1
        while change[idx + right] == 0:
            right += 1
        
        answer += left if left < right else right
        idx += -left if left < right else right
    
    return answer