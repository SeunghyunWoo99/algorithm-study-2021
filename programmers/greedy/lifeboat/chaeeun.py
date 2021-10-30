def solution(people, limit):
    cnt = 0
    people.sort(reverse=True)
    # 최소값의 index
    j = len(people)-1

    for i in range(len(people)):
        # 한 명 밖에 못 타는 경우
        if people[i]+people[j] > limit:
            cnt+=1
        # 2명 타는 경우
        else:
            cnt+=1
            j-=1
        if i >= j:
            break
    return cnt