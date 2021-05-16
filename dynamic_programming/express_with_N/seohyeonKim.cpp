#include <string>
#include <vector>

using namespace std;

int make_nn(int i, int n) {
    int nn = n;
    for (int cnt = 0; cnt < i - 1; cnt++) {
        nn = nn * 10 + n;
    }
    return nn;
}

int solution(int N, int number) {
    int answer = 0;
    vector<vector<int>> numbers(9);

    for (int i = 1; i <= 8; i++) {
        vector<int> made_number;
        if (N == number) return i;
        if (i == 1) {
            made_number.push_back(N);
            numbers[i] = made_number;
            continue;
        }
        int nn = make_nn(i, N);
        if (nn == number) return i;
        made_number.push_back(nn);
        for (int j = 1; j <= i / 2; j++) {
            for (int k = 0; k < numbers[i - j].size(); k++) {
                // °ö¼À
                for (int l = 0; l < numbers[j].size(); l++) {
                    int big = numbers[i - j][k] > numbers[j][l] ? numbers[i - j][k] : numbers[j][l];
                    int small = numbers[i - j][k] < numbers[j][l] ? numbers[i - j][k] : numbers[j][l];
                    int n1, n2, n3, n4, n5;
                    n1 = big * small;
                    if(small!=0)
                        n2 = big / small;
                    n3 = big + small;
                    n4 = big - small;
                    if (n1 == number || n3 == number || n4 == number) return i;
                    if (small != 0 && n2 == number) return i;
                    made_number.push_back(n1);
                    if(small !=0)
                        made_number.push_back(n2);
                    made_number.push_back(n3);
                    made_number.push_back(n4);

                }
            }
        }            
        numbers[i] = made_number;
    }


    return -1;
}