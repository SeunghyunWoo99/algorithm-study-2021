#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    for (int h = 3;; ++h)
        if (((brown + 4) / 2 - h) * h == brown + yellow)
        {
            answer.push_back((brown + yellow) / h);
            answer.push_back(h);
            return answer;
        }
}
