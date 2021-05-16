import heapq

def solution(jobs):
    jobLen = len(jobs)
    curTime = 0
    total = 0
    waitingJobs = []
    heapq.heapify(waitingJobs)
    
    while True:
        for job in jobs[:]:           
            if job[0] <= curTime:
                heapq.heappush(waitingJobs, job[1])
                total -= job[0]
                jobs.remove(job)
        
        if len(waitingJobs) <= 0:
            if len(jobs) > 0:
                curTime += 1
                continue;
            else:
                return total//jobLen
        
        curTime += heapq.heappop(waitingJobs)
        total += curTime