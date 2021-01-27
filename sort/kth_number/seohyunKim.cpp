#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        vector<int> sort_array;

        for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
            sort_array.push_back(array[j]);

        sort(sort_array.begin(), sort_array.end());
        answer.push_back(sorted_array[commands[i][2] - 1]);
    }

    return answer;
}