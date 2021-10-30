def solution(answers):
    l = len(answers)
    result=[]
    cnt=[0]*3
    st1 = [1,2,3,4,5]
    st2 = [2,1,2,3,2,4,2,5]
    st3 = [3,3,1,1,2,2,4,4,5,5]
    for i in range(l):
        if answers[i]==st1[i%5]:
            cnt[0]+=1
        if answers[i] == st2[i%8]:
            cnt[1] += 1
        if answers[i]==st3[i%10]:
            cnt[2]+=1
    max_score = max(cnt)
    for i in range(3):
        if max_score==cnt[i]:
            result.append(i+1)
    return result

answer = [1,3,2,4,2]
a =solution(answer)
print(a)