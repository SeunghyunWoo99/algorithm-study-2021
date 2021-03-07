#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> daysLeft;
    queue<int> queue;

    for (int i = 0; i < progresses.size(); i++)
    {
        int count = (100 - progresses[i]) / speeds[i];
        if ((progresses[i] + count * speeds[i]) != 100)
            ++count;
        daysLeft.push_back(count);
    }

    queue.push(daysLeft[0]);

    for (int i = 1; i < daysLeft.size(); i++)
    {
        if (queue.front() >= daysLeft[i])
            queue.push(daysLeft[i]);
        else
        {
            answer.push_back(queue.size());
            while (!queue.empty())
                queue.pop();
            queue.push(daysLeft[i]);
        }
    }

    if (!queue.empty())
        answer.push_back(queue.size());
    return answer;
}

int main()
{
    vector<int> progresses = {7, 4, 5, 6};
    vector<int> speeds = {7, 4, 5, 6};

    solution(progresses, speeds);
    return 0;
}
