#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    priority_queue<pair<int, int>> executable;

    for (int time = 0;;) 
    {
        if (jobs.size() == 0 && executable.size() == 0) break;
        // executable 갱신
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= time) {
                executable.push(make_pair(jobs[i][0], jobs[i][1]));
                jobs.erase(jobs.begin() + i);
                i--;
            }
            // 현재 바로 실행할 수 있는 job을 받음
        }

        if (executable.size() != 0) {
            // 현재 실행할 수 있는 것 중 실행 시간이 가장 짧은 것 찾기 위해 정렬
            pair<int, int> top = executable.top();
            answer += top.second + (time - top.first);
            time += top.second;
            executable.pop();
        }
        else time++;
    }

    return answer / n;
}
 
//////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}


int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    vector<pair<int, int>> executable;

    for (int time = 0;;)
    {
        if (jobs.size() == 0 && executable.size() == 0) break;
        // executable 갱신
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= time) {
                executable.push_back(make_pair(jobs[i][0], jobs[i][1]));
                jobs.erase(jobs.begin() + i);
                i--;
            }
            // 현재 바로 실행할 수 있는 job을 받음
        }


        if (executable.size() != 0) {
            sort(executable.begin(), executable.end(), cmp);
            // 현재 실행할 수 있는 것 중 실행 시간이 가장 짧은 것 찾기 위해 정렬
            answer += executable[0].second + (time - executable[0].first);
            //printf("%d ", answer);
            time += executable[0].second;
            executable.erase(executable.begin());
        }
        else time++;
    }

    return answer / n;
}