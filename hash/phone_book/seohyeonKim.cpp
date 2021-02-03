#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for (int i = 0; i < phone_book.size();i++) {
        string number = phone_book[i];
        for (int j = 0; j < phone_book.size(); j++) {
            if (i == j) continue;
            string find_number = phone_book[j];
            int index = find_number.find(number);
            if (string::npos != index && index == 0) {
                return false;
            }
        }
    }

    return answer;
}