#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> NUMBERS;
int TARGET;
int ANSWER = 0;

void recursive(int index, int total)
{
    if (index == NUMBERS.size())
    {
        if (total == TARGET)
            ++ANSWER;
        return;
    }
    recursive(index + 1, total + NUMBERS[index]);
    recursive(index + 1, total - NUMBERS[index]);
}

int solution(vector<int> numbers, int target)
{
    NUMBERS = numbers;
    TARGET = target;

    recursive(0, 0);

    return ANSWER;
}

int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;

    cout << solution(numbers, target);
    return 0;
}
