#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations)
{
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i)
        for (int h = citations[i]; h > citations[i + 1]; --h)
            if (i + 1 >= h)
                return h;
    return 0;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};

    cout << solution(citations) << endl;
    return 0;
}
