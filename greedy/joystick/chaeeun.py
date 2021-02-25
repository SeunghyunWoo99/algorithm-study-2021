def check_all_visited(dic):
    for k in dic:
        if dic[k] == 0:  # 방문 안한 경우
            return True
    return False


def find_sum_dist(dic, list):
    updown_cnt = 0
    # dic에는 'A'가 아닌 문자의 index 값이 key로 들어있음
    # list는 원본 문자열(dic key값이 index이므로 원소값을 확인하기 위해서 인자를 줌)
    for i in dic:
        if list[i] == 'Z':
            updown_cnt += 1
            continue
        else:
            updown_cnt += find_alp_dist(list[i])
    return updown_cnt


def find_alp_dist(alp):
    dist_to_A = ord(alp) - ord('A')
    # 여기에 1을 더해줘야하는 것을 까먹음(A에서 Z로 이동하는 것 1번)
    dist_to_Z = ord('Z') - ord(alp) + 1
    return min(dist_to_A, dist_to_Z)


def solution(name):
    l = len(name)
    cnt = 0
    # 'A'를 제외한 문자의 index를 key로 갖음(value=0으로 초기화, 미방문을 뜻함)
    visited = {}
    for index in range(l):
        if name[index] != 'A':
            visited[index] = 0

    # A가 존재하지 않는 경우
    if name.count("A") == 0:
        return find_sum_dist(visited, name) + l - 1

    # A가 존재하는 경우
    i = 0  # 시작점
    # up, down 이동의 최솟값
    cnt += find_sum_dist(visited, name)
    visited[0] = 1
    while (check_all_visited(visited)):
        right_cnt = 0
        left_cnt = 0

        # 오른쪽(한바퀴 안에 탐색이 가능하므로 l-1까지로 설정)
        for j in range(1, l):
            right_cnt += 1
            if name[(i + j) % l] != 'A' and visited[(i + j) % l] == 0:
                right_point = (i + j) % l
                break

        # 왼쪽
        for j in range(1, l):
            left_cnt += 1
            if name[(i - j)] != 'A':
                left_point = i - j
                if left_point < 0:
                    left_point = l + left_point
                if visited[left_point] == 0:
                    break

        # default는 오른쪽 방향
        if left_cnt < right_cnt:
            i = left_point
            cnt += left_cnt
        else:
            i = right_point
            cnt += right_cnt
        visited[i] = 1
    return cnt