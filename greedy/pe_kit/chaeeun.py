def solution(n, lost, reserve):
    # 5번 제한사항
    for i in reserve[:]:
        if i in lost:
            lost.remove(i)
            reserve.remove(i)

    for i in reserve[:]:
        if (i-1) in lost:
            lost.remove(i-1)
        elif (i+1) in lost:
            lost.remove(i+1)

    return (n-len(lost))