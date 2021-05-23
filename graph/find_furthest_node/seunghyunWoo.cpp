#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void print_vector(vector<int> vec)
{
    for (int v : vec)
        cout << v << " ";
    cout << endl;
}

int solution(int n, vector<vector<int> > edge)
{
    int answer = 0;
    vector<int> graph[n + 1];
    queue<int> q;
    vector<bool> visited(20001, false);
    vector<int> distance(20001);

    for (auto e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        for (int n : graph[node])
            if (!visited[n])
            {
                visited[n] = true;
                distance[n] = distance[node] + 1;
                q.push(n);
            }
        q.pop();
    }

    sort(distance.begin(), distance.end(), greater<int>());

    for (int d : distance)
        if (d == distance[0])
            ++answer;

    return answer;
}

int main()
{
    vector<vector<int> > edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};
    cout << solution(6, edge);
    return 0;
}