#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers)
{
    string answer = "";
    vector<string> numbersToString;

    for (int n : numbers)
        numbersToString.push_back(to_string(n));

    sort(numbersToString.begin(), numbersToString.end(), compare);

    if (numbersToString[0] == "0")
        return "0";

    for (string n : numbersToString)
        answer += n;

    return answer;
}

int main()
{
    vector<int> numbers = {12, 121};
    cout << solution(numbers) << endl;

    return 0;
}
