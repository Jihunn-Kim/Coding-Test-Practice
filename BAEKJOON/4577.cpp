#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <cstring>
#include <set>
#include <unordered_set>
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int r, c;
char arr[17][17];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int round = 1;
	while (true) {
		cin >> r >> c;
		if (r == 0 && c == 0)
			break;

		bool box[17][17];
		memset(box, false, sizeof(box));

		int pr, pc, cnt = 0, check = 0; // cnt 박스 수, check + 위에 있는 박스 수
		for (int i = 0; i < r; ++i) {
			cin >> arr[i];
			for (int j = 0; j < c; ++j) {
				if (arr[i][j] == 'w') {
					pr = i;
					pc = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == 'W') {
					pr = i;
					pc = j;
					arr[i][j] = '+';
				}
				else if (arr[i][j] == 'b') {
					box[i][j] = true;
					++cnt;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == 'B') {
					box[i][j] = true;
					++cnt;
					arr[i][j] = '+';
					++check;
				}
			}
		}

		char input[51];
		cin >> input;

		for (int i = 0; input[i]; ++i) {
			char tmp = input[i];

			if (tmp == 'U') {
				if (box[pr - 1][pc] == false && arr[pr - 1][pc] != '#') {
					--pr;
				}
				else if (box[pr - 1][pc] == true && box[pr - 2][pc] == false 
					&& arr[pr - 2][pc] != '#') {

					box[pr - 1][pc] = false;
					if (arr[pr - 1][pc] == '+')
						--check;
	
					box[pr - 2][pc] = true;
					if (arr[pr - 2][pc] == '+')
						++check;
					--pr;
				}
			}
			else if (tmp == 'D') {
				if (box[pr + 1][pc] == false && arr[pr + 1][pc] != '#') {
					++pr;
				}
				else if (box[pr + 1][pc] == true && box[pr + 2][pc] == false
					&& arr[pr + 2][pc] != '#') {

					box[pr + 1][pc] = false;
					if (arr[pr + 1][pc] == '+')
						--check;

					box[pr + 2][pc] = true;
					if (arr[pr + 2][pc] == '+')
						++check;
					++pr;
				}
			}
			else if (tmp == 'L') {
				if (box[pr][pc - 1] == false && arr[pr][pc - 1] != '#') {
					--pc;
				}
				else if (box[pr][pc - 1] == true && box[pr][pc - 2] == false
					&& arr[pr][pc - 2] != '#') {

					box[pr][pc - 1] = false;
					if (arr[pr][pc - 1] == '+')
						--check;

					box[pr][pc - 2] = true;
					if (arr[pr][pc - 2] == '+')
						++check;
					--pc;
				}
			}
			else {
				if (box[pr][pc + 1] == false && arr[pr][pc + 1] != '#') {
					++pc;
				}
				else if (box[pr][pc + 1] == true && box[pr][pc + 2] == false
					&& arr[pr][pc + 2] != '#') {

					box[pr][pc + 1] = false;
					if (arr[pr][pc + 1] == '+')
						--check;

					box[pr][pc + 2] = true;
					if (arr[pr][pc + 2] == '+')
						++check;
					++pc;
				}
			}

			if (cnt == check)
				break;

		}

		if (cnt == check) {
			cout << "Game " << round << ": complete\n";
		}
		else {
			cout << "Game " << round << ": incomplete\n";
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (box[i][j] == true) {
					if (arr[i][j] == '+')
						cout << 'B';
					else
						cout << 'b';
				}
				else if (pr == i && pc == j) {
					if (arr[i][j] == '+')
						cout << 'W';
					else
						cout << 'w';
				}
				else
					cout << arr[i][j];
			}
			cout << '\n';
		}

		++round;
	}

	
	return 0;
}