#include <vector>
#include <iostream>

using namespace std;

void countLShapedPlots(int a, int b, long long &answer)
{
    for (int x = 2; x <= a && x * 2 <= b; ++x)
        answer++;
    for (int x = 2; x <= b && x * 2 <= a; ++x)
        answer++;
}

long long solution(vector<vector<int> > m)
{
    long long answer = 0;
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] == 1)
            {
                int up(0), down(0), left(0), right(0);
                for (int n = i; n >= 0 && m[n][j] == 1; --n)
                    ++up;
                for (int n = i; n < m.size() && m[n][j] == 1; ++n)
                    ++down;
                for (int n = j; n >= 0 && m[i][n] == 1; --n)
                    ++left;
                for (int n = j; n < m[i].size() && m[i][n] == 1; ++n)
                    ++right;
                countLShapedPlots(up, right, answer);
                countLShapedPlots(up, left, answer);
                countLShapedPlots(down, right, answer);
                countLShapedPlots(down, left, answer);
            }
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    vector<long long> answers;

    for (int test = 0; test < t; test++)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > m(r, vector<int>(c, 0));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> m[i][j];
        answers.push_back(solution(m));
    }
    for (int i = 0; i < t; i++)
        cout << "Case #" << i + 1 << ": " << answers[i] << endl;

    return 0;
}

/*
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0

1
4 3
1 0 0
1 0 1
1 0 0
1 1 0

*/