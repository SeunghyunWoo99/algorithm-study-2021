#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> numberOfPEkit(n, 1);

    // 체육복 가져온 애들 체육복 갯수 늘려줌
    for (int i = 0; i < reserve.size(); i++)
        numberOfPEkit[reserve[i] - 1]++;

    // 안가져온 애들 체육복 갯수 빼 줌
    for (int i = 0; i < lost.size(); i++)
        numberOfPEkit[lost[i] - 1]--;

    for (int i = 0; i < n; i++)
    {
        // 체육복 없는 애 있으면
        if (numberOfPEkit[i] == 0)
        {
            // 걔 앞뒤로 2개 있는 애 있으면 뺐어서 준다
            if (numberOfPEkit[i - 1] == 2)
            {
                numberOfPEkit[i - 1]--;
                numberOfPEkit[i]++;
            }
            else if (numberOfPEkit[i + 1] == 2)
            {
                numberOfPEkit[i + 1]--;
                numberOfPEkit[i]++;
            }
        }
    }

    // 학생들 중 체육 수업 들을 수 있는 애 찾음
    for (int s : numberOfPEkit)
        if (s > 0)
            answer++;

    return answer;
}

int main()
{
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {3};
    cout << solution(n, lost, reserve) << endl;

    return 0;
}
