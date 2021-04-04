def solution(clothes):
    clothes_count = {}
    for c in clothes:
        if not c[1] in clothes_count:
            clothes_count[c[1]] = 0
        clothes_count[c[1]] += 1
    
    answer = 0
    for k, v in clothes_count.items():
        if answer == 0:
            answer = v + 1
        else:
            answer *= (v + 1)
    
    return answer - 1
