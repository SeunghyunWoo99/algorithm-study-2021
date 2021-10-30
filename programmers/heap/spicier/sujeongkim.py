import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while(scoville[0] < K):
        if(len(scoville) < 2):
            return -1
        first = heapq.heappop(scoville)
        second = heapq.heappop(scoville)
        heapq.heappush(scoville, first + second * 2)
        answer += 1
    
    return answer

print(solution([1, 2, 4, 6], 100))
