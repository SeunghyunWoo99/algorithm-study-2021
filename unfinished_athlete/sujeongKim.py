def solution(participant, completion):
    hashTable = {}
    
    for name in participant:
        if name in hashTable:
            hashTable[name] += 1
        else :
            hashTable[name] = 1

    for name in completion:
        hashTable[name] -= 1
        
    for key in hashTable:
        if hashTable[key] != 0:
            return key