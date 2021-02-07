def solution(prices):
    answer = [-1 for i in range(prices)]
    stack = []
    
    stack.append(0)
    for i in range(1, len(prices)):
        if prices[i] > prices[stack[-1]]:
            stack.append(i)
        else:
            for j in range(len(stack) - 1 ,-1, -1):
                if prices[stack[j]] > prices[i]:
                    answer[stack[j]] = stack.pop()
                    j -= 1
                else:
                    stack.append(i)
                    break
    
    return answer