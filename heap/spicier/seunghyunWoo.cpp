#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > prices_heap;

    for (int i = 0; i < scoville.size(); i++)
        prices_heap.push(scoville[i]);

    while (prices_heap.top() < K)
    {
        if (prices_heap.size() == 1)
            return -1;
        answer++;
        int first = prices_heap.top();
        prices_heap.pop();
        int second = prices_heap.top();
        prices_heap.pop();
        prices_heap.push(first + 2 * second);
    }

    return answer;
}

int main()
{
    vector<int> scoville = {0, 0, 0, 0, 0, 0, 0};
    cout << solution(scoville, 7) << endl;

    return 0;
}
