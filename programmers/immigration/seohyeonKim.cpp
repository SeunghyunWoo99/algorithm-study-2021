#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1; //최소 시간
    long long right = n * (long long)(*max_element(times.begin(), times.end())); //최대 시간
    answer = right;
    //뒤에서 최솟값을 찾는 과정을 하므로 최댓값으로 설정해준다.

    /* 
    최소의 "시간"을 찾아낸다.
     mid는 답이 될 수 있는 시간(후보)이며
     mid / times[i]는 mid라는 시간동안 i번째 심사관이 몇명을 심사할 수 있는지이다.
     */
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int time : times)
            sum += mid / time; //각 심사관들이 해당 시간(mid)동안 몇명을 심사할 수 있는지

        if (sum >= n) {// 충분히 다 심사할 수 있을 경우
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
             
    }
    return answer;
}
