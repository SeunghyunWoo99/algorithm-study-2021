#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> mynumbers;
int mytarget;

void DFS(int start, vector<bool>& visited) {
	if (start >= visited.size()) { //순회 끝, 계산 고
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
		DFS(start + 1, visited); //다음 원소를 향해
		visited[start] = false;
		DFS(start + 1, visited);
		// 방문 하거나, 안하거나 두 가지 경우의 수
	}
}

int solution(vector<int> numbers, int target) {
	vector<bool> visited(numbers.size(), false);
	mynumbers = numbers;
	mytarget = target;
	DFS(0, visited);
	return answer;
}