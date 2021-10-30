def solution(brown, yellow):    
    for height in range(1, brown + yellow + 1):
        if (brown + yellow) % height == 0:
            width = int((brown + yellow) / height)
            if yellow == (height - 2) * (width - 2):
                return [width, height]
