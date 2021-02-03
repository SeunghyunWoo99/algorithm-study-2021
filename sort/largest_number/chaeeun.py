def solution(numbers):
    numbers = [str(i) for i in numbers[:]]
    numbers.sort(key=lambda x:x*3,reverse=True)
    result = ''.join(numbers)
    result_len = len(result)
    if result=='0'*result_len:
        return '0'
    return result