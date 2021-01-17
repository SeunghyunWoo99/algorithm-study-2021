#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> sorted_array(array);
        int start_index = commands[i][0] - 1;
        int end_index = commands[i][1] - 1;
        int k = commands[i][2];

        if (end_index + 1 >= array.size()) end_index = array.size() - 2;

        sort(&sorted_array[start_index], &sorted_array[end_index + 1]);

        answer.push_back(sorted_array[start_index + k - 1]);
    }

    return answer;
}