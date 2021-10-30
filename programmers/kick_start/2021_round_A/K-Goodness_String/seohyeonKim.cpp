#include <iostream>
#include <vector>

using namespace std;

int countGoodnessScore(string str, int length) {
	int count = 0;
	for (int i = 0; i < length/2; i++) {
		if (str[i] != str[length - 1 - i])
			count++;
	}
	return count;
}

int main() {
	int testcase = 0;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int length, k;
		string str;
		cin >> length >> k;
		cin >> str;
		int goodness_score = countGoodnessScore(str, length);
		int operation = k - goodness_score;
		if (operation < 0) operation *= (-1);
		cout << "Case #" << i + 1 << ": " << operation << endl;
	}


}