T = int(input())

for i in range(T):
    N, K = map(int, input().split())
    string = input()
    good = 0
    for j in range(int(N/2)):
        if(string[j] != string[N-1-j]):
            good += 1
    print("CASE #" + str(i+1) + ":", abs(K - good))
