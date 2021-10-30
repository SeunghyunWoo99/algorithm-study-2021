#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    long long start = 1;
    long long end = *max_element(times.begin(), times.end()) * n;
    long long mid;
    long long people = 0;

    while (start <= end)
    {
        mid = ((end + start) / 2);

        for (int t : times)
            people += mid / t;

        if (n <= people)
        {
            answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
        people = 0;
    }
    return answer;
}

int main()
{
    int n = 6;
    vector<int> times = {7, 10};

    cout << solution(n, times);
    return 0;
}
