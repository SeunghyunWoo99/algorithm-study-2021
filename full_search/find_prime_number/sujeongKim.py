from itertools import permutations

def solution(numbers):
    answer = 0
    
    allNums = []
    for i in range(1, len(numbers) + 1):
        temp = list(permutations(list(numbers), i))
        for i in temp:
            allNums.append(int(''.join(i)))
    
    n = max(allNums)
    eratos = [False,False] + [True] * (n-1)
    primes = []

    for i in range(2, n+1):
        if eratos[i]:
            primes.append(i)
            for j in range(2*i, n+1, i):
                eratos[j] = False
    
    s1 = set(primes)
    s2 = set(allNums)
    
    return len(s1&s2)
