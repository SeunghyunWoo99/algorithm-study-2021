#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int days = 0;

    for (int i = 0; i < progresses.size();days++) {
        if (progresses[i] + days * speeds[i] >= 100) {
            int cnt = 1;
            int j;
            for (j = i + 1; j < progresses.size(); j++) {
                if (progresses[j] + days * speeds[j] >= 100)
                    cnt++;
                else break;
            }
            answer.push_back(cnt);
            i = j;
        }
        
    }


    return answer;
}
