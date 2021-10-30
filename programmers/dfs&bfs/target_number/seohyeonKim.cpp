#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> mynumbers;
int mytarget;

void DFS(int start, vector<bool>& visited) {
	if (start >= visited.size()) { //��ȸ ��, ��� ��
		int sum = 0;
		for (int i = 0; i <visited.size(); i++) {
			if (visited[i] == true) sum += mynumbers[i];
			else sum -= mynumbers[i];
		}
		if (sum == mytarget) {
			answer++;
		}
	}
	else {
		visited[start] = true;
		DFS(start + 1, visited); //���� ���Ҹ� ����
		visited[start] = false;
		DFS(start + 1, visited);
		// �湮 �ϰų�, ���ϰų� �� ���� ����� ��
	}
}

int solution(vector<int> numbers, int target) {
	vector<bool> visited(numbers.size(), false);
	mynumbers = numbers;
	mytarget = target;
	DFS(0, visited);
	return answer;
}