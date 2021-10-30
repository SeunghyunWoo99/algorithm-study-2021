#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> new_scoville(scoville.begin(), scoville.end());

    /*
    priority_queue<int, vector<int>, greater<int>> new_scoville;
    for (int each_scoville : scoville)
        new_scoville.push(each_scoville);*/

    int size = new_scoville.size();

    while (size > 1 && new_scoville.top() < K) {
        int first_min = new_scoville.top();
        new_scoville.pop();
        int second_min = new_scoville.top();
        new_scoville.pop();

        int mixed = first_min + second_min * 2;
        new_scoville.push(mixed);
        answer++;
        size--;
    }

    if (new_scoville.top() < K)
        return -1;

    return answer;
}