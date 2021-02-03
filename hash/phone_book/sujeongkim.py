def solution(phone_book):
    answer = True
    phone_book = sorted(phone_book)
    
    for i in range(0, len(phone_book) - 1):
        if phone_book[i + 1].find(phone_book[i]) == 0:
            answer = False
            return answer
            
    return answer