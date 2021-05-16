#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
};

void printVector(vector<int> v)
{
    cout << "[" << v[0] << ", " << v[1] << "]" << endl;
}

void printVector2(vector<vector<int> > v)
{
    for (vector<int> n : v)
    {
        printVector(n);
    }
    cout << endl;
}

int solution(vector<vector<int> > jobs)
{
    int answer = 0;
    int time = 0;
    int i = 0;
    priority_queue<vector<int>, vector<vector<int> >, compare> pq;

    sort(jobs.begin(), jobs.end());

    while (i < jobs.size() || !pq.empty())
    {
        if (i < jobs.size() && jobs[i][0] <= time)
        {
            pq.push(jobs[i++]);
            continue;
        }

        if (!pq.empty())
        {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[i][0];
    }

    return answer / jobs.size();
}

int main()
{
    vector<vector<int> > jobs;
    jobs.push_back({1, 9});
    jobs.push_back({0, 3});
    jobs.push_back({2, 6});
    cout << solution(jobs) << endl;

    return 0;
}