#include <vector>
#include <array>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    array<int, 3> scores = {
        0,
    };

    array<int, 5> pattern1 = {1, 2, 3, 4, 5};
    array<int, 8> pattern2 = {2, 1, 2, 3, 2, 4, 2, 5};
    array<int, 10> pattern3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int *first = &answers[0];
    for (int i = 0; i < answers.size(); i++)
    {
        if (pattern1[i % 5] == *(first + i))
            scores[0]++;
        if (pattern2[i % 8] == *(first + i))
            scores[1]++;
        if (pattern3[i % 10] == *(first + i))
            scores[2]++;
    }

    int maxScore = max(max(scores[0], scores[1]), scores[2]);
    for (int i = 0; i < 3; i++)
        if (scores[i] == maxScore)
            answer.push_back(i + 1);

    return answer;
}

int main()
{
    vector<int> answers = {1, 2, 3, 4, 5};
    solution(answers);

    return 0;
}
