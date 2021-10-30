def solution(people, limit):
    answer = 0
    first = 0
    last = len(people) - 1
    
    people.sort()
    while first <= last:
        if people[first] + people[last] <= limit:
            first += 1
        last -= 1
        answer += 1
        
    return answer
