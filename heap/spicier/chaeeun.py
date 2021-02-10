import heapq

def solution(s, k):
	h=[]
	for i in s:
		heapq.heappush(h,i)
	cnt=0

	while(True):
		if h[0]>=k:
			return cnt
		if len(h)==1 and h[0]<k:
			return -1
		m1 = heapq.heappop(h)
		m2 = heapq.heappop(h)
		mix = m1+m2*2
		heapq.heappush(h,mix)
		cnt += 1

# print(solution([0, 0, 3, 9, 10, 12], 0), 0)
# print(solution([0, 0], 0), 0)
# print(solution([0, 0], 1), -1)
# print(solution([1, 0], 1), 1)
# print(solution([1, 1, 1], 4), 2)
# print(solution([10, 10, 10, 10, 10], 100), 4)
# print(solution([1, 2, 3, 9, 10, 12], 7), 2)
# print(solution([0, 2, 3, 9, 10, 12], 7), 2)
# print(solution([0, 0, 3, 9, 10, 12], 7), 3)
# print(solution([0, 0, 0, 0], 7), -1)
# print(solution([0, 0, 3, 9, 10, 12], 7000), -1)
# print(solution([0, 0, 3, 9, 10, 12], 1), 2)
# print(solution([0, 0], 1), -1)
# print(solution([1, 0], 1), 1)