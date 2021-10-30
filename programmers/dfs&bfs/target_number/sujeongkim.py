
def solution(numbers, target):
    global new_numbers
    new_numbers = numbers
    global total
    total = 0
    global new_target
    new_target = target
    
    dfs(0, 0)
    
    return total

def dfs(index, sum):
    global total
    if index == len(new_numbers):
        if sum == new_target:
            total += 1
        return
    
    dfs(index + 1, sum + new_numbers[index])
    dfs(index + 1, sum - new_numbers[index])
    
    return
    