#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        int count = 0;
        for (int j = i + 1; j < prices.size(); ++j)
        {
            count++;
            if (prices[i] > prices[j])
                break;
        }
        answer.push_back(count);
    }

    return answer;
}

int main()
{
    int n = 5;
    vector<int> prices = {1, 2, 3, 2, 3};
    solution(prices);

    return 0;
}
