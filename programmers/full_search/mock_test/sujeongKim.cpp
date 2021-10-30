#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> winners;
    vector<int> correct{0, 0, 0};
    int arrayFor2[4] = {1, 3, 4, 5};
    int arrayFor3[5] = {3, 1, 2, 4, 5};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == (i) % 5 + 1) {
           correct[0] ++;
        }
        
        if ((i % 2 == 0) && answers[i] == 2) {
           correct[1] ++;
        }
        if ((i % 2 == 1) && arrayFor2[(i / 2) % 4] == answers[i]) {
           correct[1] ++;
        }
        
        if (answers[i] == arrayFor3[(i % 10) / 2]) {
           correct[2] ++;
        }
    }
    
    int max = 0;
    for (int i = 0; i < 3; i++) {
        if (max == correct[i]) {
            winners.push_back(i + 1);
        }
        if (max < correct[i]) {
            winners.clear();
            max = correct[i];
            winners.push_back(i + 1);
        }
    }
    
    return winners;
}