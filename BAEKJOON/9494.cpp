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
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int n;
string inputs[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> n;
		cin.ignore(2, '\n');
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i) {
			getline(cin, inputs[i]);
		}

		int lineNum = 0, col = 0;
		while (lineNum < n) {
			while (col < inputs[lineNum].size() && inputs[lineNum][col] != ' ') {
				++col;
			}
			++lineNum;
		}
		cout << col + 1 << '\n';
	}
	return 0;
}