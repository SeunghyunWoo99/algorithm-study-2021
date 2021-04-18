#include <string>
#include <iostream>

using namespace std;

int solution(int n, int k, string s)
{
    int answer = 0;
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - i - 1])
            ++answer;
    return abs(k - answer);
}

int main()
{
    int num, n, k;
    string s;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        cin >> n >> k >> s;
        cout << "Case #" << i + 1 << ": " << solution(n, k, s) << endl;
    }

    return 0;
}