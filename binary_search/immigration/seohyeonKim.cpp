#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 1; //�ּ� �ð�
    long long right = n * (long long)(*max_element(times.begin(), times.end())); //�ִ� �ð�
    answer = right;
    //�ڿ��� �ּڰ��� ã�� ������ �ϹǷ� �ִ����� �������ش�.

    /* 
    �ּ��� "�ð�"�� ã�Ƴ���.
     mid�� ���� �� �� �ִ� �ð�(�ĺ�)�̸�
     mid / times[i]�� mid��� �ð����� i��° �ɻ���� ����� �ɻ��� �� �ִ����̴�.
     */
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int time : times)
            sum += mid / time; //�� �ɻ������ �ش� �ð�(mid)���� ����� �ɻ��� �� �ִ���

        if (sum >= n) {// ����� �� �ɻ��� �� ���� ���
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
             
    }
    return answer;
}
