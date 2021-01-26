#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    map<string, int> isCompleted;

    for (string p : participant)
    {
        ++isCompleted[p];
    }

    for (string c : completion)
    {
        --isCompleted[c];
    }

    for (auto item : isCompleted)
    {
        if (item.second > 0)
        {
            return item.first;
        }
    }
}

int main()
{
    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};
    vector<string> completion = {"mislav", "stanko", "ana"};
    cout << solution(participant, completion) << endl;

    return 0;
}
