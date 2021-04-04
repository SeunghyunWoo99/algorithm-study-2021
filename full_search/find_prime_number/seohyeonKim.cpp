#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


void powerset(vector<int> data, set<int>& number, vector<bool>& flag, int depth)
{
	if (data.size() == depth) { // ������ ����

		vector<int> per;
		for (int i = 0; i < data.size(); i++) {
			if (flag[i]) { //������ ���
				per.push_back(data[i]);
			}
		}
		if (!per.empty()) {
			string str = "";
			sort(per.begin(), per.end());
			do {
				/*for (int n : per) {
					str += to_string(n);
				}*/
				for (vector<int>::iterator it = per.begin(); it < per.end(); it++) {
					str += to_string(*it);
				}
				number.insert(stoi(str));
				str = "";
			} while (next_permutation(per.begin(), per.end()));
		}
		per.clear();
		return;
	}
	flag[depth] = true; //�����ϴ� ���
	powerset(data, number, flag, depth + 1);
	flag[depth] = false; // �������� �ʴ� ��� ��� ���
	powerset(data, number, flag, depth + 1);
}

bool isPrimeNumber(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<int> numbers_to_int;

	for (char ch : numbers)
		numbers_to_int.push_back(ch - '0'); //numbers�� ���ڷ� �� ���� ����

	vector<bool> flag(numbers_to_int.size(), false); //����, ������ ��Ÿ��
	set<int> number; //�κ������� ���� ���� ���� ����

	powerset(numbers_to_int, number, flag, 0);

	for (int n : number) {
		if (isPrimeNumber(n)) answer++;
	}
	return answer;
}