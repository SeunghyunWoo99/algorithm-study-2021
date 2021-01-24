def solution(answers):
    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]
    
    answer = {1: 0, 2: 0, 3: 0}
    for index, value in enumerate(answers):
        answer[1] += 1 if first[index%len(first)] == value else 0
        answer[2] += 1 if second[index%len(second)] == value else 0
        answer[3] += 1 if third[index%len(third)] == value else 0

    max = 0
    winners = []
    for key, value in answer.items():
        if value > max:
            max = value
            winners.clear()
            winners.append(key)
        elif value == max:
            winners.append(key)

    return winners
