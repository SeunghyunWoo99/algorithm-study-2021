#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> getGrid(int row, int col) {
	vector<vector<int>> grid(row + 1);
	for (int i = 1; i <= row; i++) {
		vector<int> temp(col + 1);
		for (int j = 1; j <= col; j++) {
			int input;
			cin >> input;
			temp[j] = input;
		}
		grid[i] = temp;
	}
	return grid;
}

vector<vector<int>> getEmptyGrid(int row, int col) {
	/*	can also use "assign"	*/
	vector<vector<int>> grid(row + 2);
	for (int i = 0; i <= row + 1; i++) {
		vector<int> temp(col + 2, 0);
		grid[i] = temp;
	}
	return grid;
}

int countLShaped(int a, int b) {

	/*	If a is length of the longer segment,
	*	the number of L Shaped is
	*	min(a/2, b) - 1
	*	
	*	+) If the point is not a vertex,
	*	if you follow that formula, it returns -1
	*
	*	Therefor, if the point is not a vertex, returns 0
	*/

	return min(a / 2 - 1, max(0, b - 1));
}

int main() {
	int testcase = 0;
	cin >> testcase;
	int row, col;
	for (int i = 0; i < testcase; i++) {
		cin >> row >> col;
		vector<vector<int>> grid = getGrid(row, col);
		
		vector<vector<int>> check_l_to_r = getEmptyGrid(row, col);
		vector<vector<int>> check_r_to_l = getEmptyGrid(row, col);
		vector<vector<int>> check_u_to_d = getEmptyGrid(row, col);
		vector<vector<int>> check_d_to_u = getEmptyGrid(row, col);

		// check horizontal (row)
		for (int r = 1; r <= row; r++) {

			// check left to right
			for (int c = 1; c <= col; c++) {
				if (grid[r][c] == 1) {
					// check continuity
					check_l_to_r[r][c] = check_l_to_r[r][c - 1] + 1;
				}
			}

			// check right to left
			for (int c = col; c >= 1; c--) {
				if (grid[r][c] == 1) {
					// check continuity
					check_r_to_l[r][c] = check_r_to_l[r][c + 1] + 1;
				}
			}
		}

		// check vertical (col)
		for (int c = 1; c <= col; c++) {

			//check up to down
			for (int r = 1; r <= row; r++) {
				if (grid[r][c] == 1) {
					//check continuity
					check_u_to_d[r][c] = check_u_to_d[r - 1][c] + 1;
				}
			}

			//check down to up
			for (int r = row; r >= 1; r--) {
				if (grid[r][c] == 1) {
					//check continuity
					check_d_to_u[r][c] = check_d_to_u[r + 1][c] + 1;
				}
			}
		}

		int answer = 0;
		for (int r = 1; r <= row; r++) {
			for (int c = 1; c <= col; c++) {
				/*	Segments must have length at least 2.
				*	The length of the longer segment is twice the length of the shorter segment.
				*	Therefore, the length of the longer segemet must be at least 4.
				*/
				if (check_l_to_r[r][c] >= 4) {
					int up = countLShaped(check_l_to_r[r][c], check_d_to_u[r][c]);
					int down = countLShaped(check_l_to_r[r][c], check_u_to_d[r][c]);
					answer += up;
					answer += down;
				}
				if (check_r_to_l[r][c] >= 4) {
					int up = countLShaped(check_r_to_l[r][c], check_d_to_u[r][c]);
					int down = countLShaped(check_r_to_l[r][c], check_u_to_d[r][c]);
					answer += up;
					answer += down;
				}
				if (check_u_to_d[r][c] >= 4) {
					int right = countLShaped(check_u_to_d[r][c], check_l_to_r[r][c]);
					int left = countLShaped(check_u_to_d[r][c], check_r_to_l[r][c]);
					answer += right;
					answer += left;
				}
				if (check_d_to_u[r][c] >= 4) {
					int right = countLShaped(check_d_to_u[r][c], check_l_to_r[r][c]);
					int left = countLShaped(check_d_to_u[r][c], check_r_to_l[r][c]);
					answer += right;
					answer += left;
				}
			}
		}

		cout << "Case #" << i + 1 << ": " << answer << endl;



	}



}