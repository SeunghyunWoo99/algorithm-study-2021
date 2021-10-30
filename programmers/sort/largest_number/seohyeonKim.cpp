#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool CompareString(int number1, int number2) {
    string first_number = to_string(number1) + to_string(number2);
    string second_number = to_string(number2) + to_string(number1);

    int compare_number = first_number.compare(second_number);
    if (compare_number > 0) //first_number < second_number
        return true;
    else
        return false;
}




string solution(vector<int> numbers) {
    string answer;
    sort(numbers.begin(), numbers.end(), CompareString);
    for (int number : numbers) {

        if (answer == "0" && number == 0)
            continue;
        if (answer == "" && number == 0) {
            answer = "0";
            continue;
        }
        answer += to_string(number);
    }

    return answer;
}
