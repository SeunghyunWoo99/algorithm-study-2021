def solution(priorities, location):
    value = priorities[location]
    answer = 0

    while True:
        while max(priorities) > priorities[0]:
            priorities.append(priorities.pop(0))
            if location == 0:
                location = len(priorities) - 1
            else:
                location -= 1
        if max(priorities) == value and location == 0:
            return answer + 1
        
        priorities.pop(0)
        answer += 1
        location -= 1
