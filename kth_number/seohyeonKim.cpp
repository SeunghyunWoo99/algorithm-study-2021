#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(3);
    // 원본을 보존해야하기 때문에 새로운 vector를 만들어야 하나?
    vector<int> sorted_array;
    for (int i = 0; i < 3; i++) {
        vector<int> sorted_array(array);
        int start_index = commands[i][0] - 1;
        int end_index = commands[i][1] - 1;
        int k = commands[i][2];

        if (end_index + 1 >= array.size()) end_index = array.size() - 2;

        sort(&sorted_array[start_index], &sorted_array[end_index + 1]);

        answer[i] = sorted_array[start_index + k - 1];
        //answer.push_back(sorted_array[start_index + k - 1]);
    }


    cout << "[";
    for (int i = 0; i < answer.size() - 1; i++)
        cout << answer[i] << ", ";
    cout << answer[answer.size() - 1];
    cout << "]";

    return answer;
}

void main() {

    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };
    solution(array, commands);
}