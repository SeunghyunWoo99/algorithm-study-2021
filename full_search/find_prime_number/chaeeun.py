from itertools import permutations
from math import sqrt

def check_sosu(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    for i in range(2, int(sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True


def solution(numbers):
    l = len(numbers)
    answer = set()
    result = []
    for i in range(1, l + 1):
        # i 자릿수의 순열들을 int로 변환한 집합
        answer |= set(map(int, map(''.join, permutations(list(numbers), i))))

    for i in answer:
        if check_sosu(i):
            result.append(i)

    return len(result)