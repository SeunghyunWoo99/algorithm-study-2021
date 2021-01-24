#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> first_student = { 1, 2, 3, 4, 5 };
    vector<int> second_student = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> third_student = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    vector<int> count_correct(3, 0);

    /*for (int i = 0, j = 0, k = 0, l = 0; i < answers.size(); i++, j++, k++, l++) {
        if (j >= first_student.size()) j = 0;
        if (k >= second_student.size()) k = 0;
        if (l >= third_student.size()) l = 0;

        if (answers[i] == first_student[j]) count_correct[0]++;
        if (answers[i] == second_student[k]) count_correct[1]++;
        if (answers[i] == third_student[l]) count_correct[2]++;
    }*/

    for (int i = 0; i < answers.size(); i++) {

        if (answers[i] == first_student[i % first_student.size()]) count_correct[0]++;
        if (answers[i] == second_student[i % second_student.size()]) count_correct[1]++;
        if (answers[i] == third_student[i % third_student.size()]) count_correct[2]++;
    }


    int max = *max_element(count_correct.begin(), count_correct.end());
    for (int i = 0; i < count_correct.size(); i++)
        if (count_correct[i] == max) answer.push_back(i + 1);
    

    return answer;
}
