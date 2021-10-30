#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int> > queue;

    for (int i = 0; i < priorities.size(); i++)
        queue.push(make_pair(i, priorities[i]));

    sort(priorities.begin(), priorities.end(), greater<int>());

    while (!queue.empty())
    {
        if (queue.front().second == priorities[answer])
        {
            if (queue.front().first == location)
                return ++answer;
            queue.pop();
            ++answer;
        }
        else
        {
            queue.push(queue.front());
            queue.pop();
        }
    }

    return answer;
}
