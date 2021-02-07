#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] <= prices[j]) answer[i]++;
            else {
                answer[i]++;
                break;
            }
        }
    }
    return answer;
}