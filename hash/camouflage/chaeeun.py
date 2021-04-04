def solution(clothes):
    dic={}
    for i in range(len(clothes)):
        if clothes[i][1] not in dic:
            dic[clothes[i][1]] = 0
        if clothes[i][1] in dic:
            dic[clothes[i][1]]+=1

    cnt=1
    for v in dic.values():
        cnt*=(v+1)
    return (cnt-1)