#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> docs; //중요도순 문서 idx
    queue<int> q;

    for (int i = 0;i < priorities.size();i++)
        q.push(i);

    while (!q.empty()) {
        int front_idx = q.front();
        int max = *max_element(priorities.begin(), priorities.end());
        
        q.pop();
        if (priorities[front_idx] < max) {  //나보다 더 큰 것 존재시 맨 뒤에 삽입(enQueue)
            q.push(front_idx);
        }
        else { //내가 제일 중요할시 꺼냄
            docs.push_back(front_idx);
            priorities[front_idx] = 0; //중요도 0
        }
    }

    answer = find(docs.begin(), docs.end(), location) - docs.begin() + 1;

    return answer;
}