def solution(number, k):
    result=[]
    for i,v in enumerate(number):
        if not result:
            result.append(v)
            continue
        # i가 이전의 숫자보다 큰 경우, 작은 숫자 모두 삭제
        while result and int(v) > int(result[-1]):
            result.pop()
            k-=1
            if k==0:
                result += number[i:]
                return "".join(result)

        result.append(v)
    # 원래부터 내림차순이라면?
    return "".join(result[:len(number)-k])