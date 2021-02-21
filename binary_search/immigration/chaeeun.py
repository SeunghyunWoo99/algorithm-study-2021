def solution(n, times):
    left, right = 0, max(times) * n

    while left <= right:
        mid = (left + right) // 2
        cnt = 0

        for i in times:
            cnt += (mid // i)
            if cnt >= n:
                break

        if cnt >= n:
            result = mid
            right = mid - 1
        else:
            left = mid + 1

    return result