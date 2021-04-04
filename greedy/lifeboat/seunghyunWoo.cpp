#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());
    int answer = 0;
    for (int i = 0; i < people.size();)
    {
        int weight = people.back();
        people.pop_back();
        if (people[i] + weight <= limit)
            i++;
        answer++;
    }
    return answer;
}

int main()
{
    vector<int> people = {50, 70, 80, 50};
    cout << solution(people, 100) << endl;
}