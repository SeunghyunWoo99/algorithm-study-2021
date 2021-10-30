def solution(brown, yellow):
    mul = brown + yellow
    for c in range(1,mul+1):
        if mul%c==0:
            r = mul/c
            if r+c ==(0.5)*brown + 2:
                return [r,c]