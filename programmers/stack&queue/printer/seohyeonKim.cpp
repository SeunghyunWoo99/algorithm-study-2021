#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> docs; //�߿䵵�� ���� idx
    queue<int> q;

    for (int i = 0;i < priorities.size();i++)
        q.push(i);

    while (!q.empty()) {
        int front_idx = q.front();
        int max = *max_element(priorities.begin(), priorities.end());
        
        q.pop();
        if (priorities[front_idx] < max) {  //������ �� ū �� ����� �� �ڿ� ����(enQueue)
            q.push(front_idx);
        }
        else { //���� ���� �߿��ҽ� ����
            docs.push_back(front_idx);
            priorities[front_idx] = 0; //�߿䵵 0
        }
    }

    answer = find(docs.begin(), docs.end(), location) - docs.begin() + 1;

    return answer;
}