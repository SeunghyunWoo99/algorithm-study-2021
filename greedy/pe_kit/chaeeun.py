def solution(n, lost, reserve):
    cnt = 0
    # 5번 제한사항
    for i in reserve[:]:
        if i in lost:
            lost.remove(i)
            reserve.remove(i)
    print(lost,reserve)

    for i in lost:
         if (cnt == len(reserve)): break
         if (i+1) == reserve[cnt]:
             cnt += 1
         elif (i-1) == reserve[cnt]:
             cnt += 1

    return (n-len(lost)+cnt)


n =10
lost = [1,2,3,10]
reserve = [3,5,9]
# [1,2,4]/[3,7]

a = solution(n, lost, reserve)
print(a)