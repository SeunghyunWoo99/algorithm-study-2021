import math

def solution(N, number):
    numbers = [ set() for _ in range(9)]
    
    for i in range(1, 9):
        numbers[i].add(int(str(N) * i))
        for j in range(1, i):
            for x in numbers[i-j]:
                for y in numbers[j]:
                    numbers[i].add(x*y)
                    if y != 0: numbers[i].add(x//y)
                    numbers[i].add(x+y)
                    numbers[i].add(x-y)
    
    for i in range(1, 9):
        if number in numbers[i]:
            return i
    return -1