def solution(number, k):
    answer = ''
    
    result = [number[0]]
    idx = 1
    while k > 0:
        if idx == (len(number)):
            result = result[:-k]
            break
        while result and number[idx] > result[-1] and k > 0:
            k -= 1
            result.pop()
        result.append(number[idx])
        idx += 1
    
    if k == 0:
        for i in range(idx, len(number)):
            result.append(number[i])

    return "".join(result)