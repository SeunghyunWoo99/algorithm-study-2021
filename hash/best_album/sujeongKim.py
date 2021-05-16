def solution(genres, plays):
    answer = []
    dics = {}
    
    for i, g in enumerate(genres):
        if g not in dics.keys():
            dics[g] = {}
        dics[g][i] = plays[i]
   
    sorted_dic = {}
    for d in dics.items():
    	# value 내림차순, 그 중에선 key로 오름차순 정렬
        sorted_dic[d[0]] = dict(sorted(d[1].items(), key=lambda item: (-item[1], item[0])))
        sorted_dic[d[0]]['sum'] = sum(d[1].values())
    
    # sum 기준으로 내림차순 정렬
    sorted_dic = sorted(sorted_dic.items(), reverse=True, key=lambda item: item[1]['sum'])
    
    for g, d in sorted_dic:
        num = 0
        for i, v in d.items():
            if not i == 'sum':
                answer.append(i)
                num += 1;
                if num == 2:
                    break;
            
    return answer