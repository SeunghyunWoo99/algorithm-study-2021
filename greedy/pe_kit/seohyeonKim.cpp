#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++) {
        vector<int>::iterator it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            reserve.erase(it);
            lost[i] = 0;
            answer++;
        }

    }

    for (int i = 0; i < lost.size(); i++) {
        vector<int>::iterator it = find(reserve.begin(), reserve.end(), lost[i] - 1);
        if (it != reserve.end()) {
            cout << "find it!!" << endl;
            reserve.erase(it);
            answer++;
            continue;
        }
       /* it = find(reserve.begin(), reserve.end(), lost[i]);
        if (it != reserve.end()) {
            cout << "find it!!" << endl;
            reserve.erase(it);
            answer++;
            continue;
        }*/
        it = find(reserve.begin(), reserve.end(), lost[i] + 1);
        if (it != reserve.end()) {
            cout << "find it!!" << endl;
            reserve.erase(it);
            answer++;
            continue;
        }

    }


    return answer;
}