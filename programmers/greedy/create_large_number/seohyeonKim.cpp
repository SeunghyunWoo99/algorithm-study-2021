#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (char ch : number) {
        if (answer.length() == 0) { 
            answer += ch;
            continue; 
        }
        while (ch > answer.back() && k > 0 && answer.length() > 0) {
            answer.pop_back();
            k--;
        }
        answer += ch;
    }

    while (k > 0) {
        answer.pop_back();
        k--;
    }


    return answer;
}