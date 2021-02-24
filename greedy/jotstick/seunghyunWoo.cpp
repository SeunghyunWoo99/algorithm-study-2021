#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int length = name.length();
    string word(name.length(), 'A');
    for (int i = 0; word != name;)
    {
        word[i] = name[i];
        answer += min(name[i] - 'A', 'Z' + 1 - name[i]);
        for (int move = 1; move < length; move++)
        {
            int goRightIndex = (i + move) % length;
            int goLeftIndex = (i + length - move) % length;
            if (name[goRightIndex] != word[goRightIndex])
            {
                i = goRightIndex;
                answer += move;
                break;
            }
            else if (name[goLeftIndex] != word[goLeftIndex])
            {
                i = goLeftIndex;
                answer += move;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    string name = "ABAAAAAAAAAAAAAAABABABB";

    cout << solution(name);
    return 0;
}
