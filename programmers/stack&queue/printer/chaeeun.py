from collections import deque

def solution(priorities, location):
    dq = deque([(v, i) for i, v in enumerate(priorities)])
    max_p = max(dq)[0]
    cur_index = 0

    while len(dq):
        p = dq.popleft()
        if p[0] != max_p:
            dq.append(p)
        else:
            cur_index+=1
            if p[1] == location:
                break
        max_p = max(dq)[0]

    return cur_index