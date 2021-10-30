#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<>());

    for(int max = 10000; max >= 0; max--) {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (citations[i] >= max) cnt++;
        if (cnt >= max && n - cnt <= max) {
            return max;
        }
    }

    return answer;
}
