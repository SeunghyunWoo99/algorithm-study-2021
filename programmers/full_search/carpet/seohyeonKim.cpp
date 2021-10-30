#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    for (int i = sqrt(total); i >= 0; i--) {
        if (total % i == 0) {
            if ((total / i - 2) * (i - 2) == yellow) {
                answer.push_back(total / i);
                answer.push_back(i);
                break;
            }
        }
    }

    return answer;
}