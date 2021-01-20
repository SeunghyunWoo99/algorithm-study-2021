from collections import Counter

def solution(participant, completion):
    count1 = Counter(participant)
    count2 = Counter(completion)

    return list((count2-count1).keys())