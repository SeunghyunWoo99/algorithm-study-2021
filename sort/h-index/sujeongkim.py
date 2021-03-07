def solution(citations):
    Hindex = len(citations)
    citations.sort()
    
    for i in range(len(citations)):
        if citations[i] <= (len(citations) - i - 1):
            Hindex = (len(citations) - i - 1)
        else:
            return Hindex
    
    return Hindex
