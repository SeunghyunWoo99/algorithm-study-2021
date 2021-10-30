# 완전 탐색을 이용하는 경우

def solution(numbers, target):
    result = [0]
    for i in numbers:
        option = [i,-i]
        m = []
        for j in result:
            plus = j+option[0]
            minus = j+option[1]
            m.append(plus)
            m.append(minus)
        result = m[:]

    return result.count(target)


n=[1,1,1,1,1]
t = 3
print(solution(n,t))
