#include <string>
#include <vector>

using namespace std;

int chooseUpOrDown(char ch) {
    int up = ch - 'A';
    int down = 'Z' - ch + 1;
    return up > down ? down : up;
}



int solution(string name) {
    int answer = 0;
    string str(name.length(), 'A');

    for (int i = 0; name != str;) {
        str[i] = name[i];
        answer += chooseUpOrDown(str[i]);

        //���ؾ� �Ǵ� ���� �ٸ��� ������ ������ �̵��Ѵ�.
        for (int move = 1; move < name.length(); move++) {
            //������ ������ �������� ������
            int right = (move + i) % name.length();
            int left = (i - move + name.length()) % name.length();
            if (str[right] != name[right]) {
                i = right;
                answer += move;
                break;
            }
            else if (str[left] != name[left]) {
                i = left;
                answer += move;
                break;
            }
        }
    }



    return answer;
}
