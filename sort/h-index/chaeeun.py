def solution(citations):
    citations.sort(reverse=True)

    for h in range(len(citations), 0, -1):
        cnt = 0
        for i in citations:
            if h <= i:
                cnt += 1
            else:
                break
        if h <= cnt:
            return h
    return 0