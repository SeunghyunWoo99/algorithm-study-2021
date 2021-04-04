#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> count_by_type;
    for (int i = 0; i < clothes.size(); i++) {
        if (count_by_type.find(clothes[i][1]) == count_by_type.end())
            count_by_type.insert(make_pair(clothes[i][1], 1));
        else
            count_by_type[clothes[i][1]]++;
    }

    int multiply = 1;
    for (auto each_type : count_by_type) 
        multiply *= (each_type.second + 1);
    

    answer += multiply;

    return --answer;
}