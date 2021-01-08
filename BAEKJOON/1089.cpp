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
#include <sstream>
#include <deque>
#include <numeric>

using namespace std;

int N;
char inputs[6][40];
string number[5] = {
	"###...#.###.###.#.#.###.###.###.###.###",
	"#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
	"#.#...#.###.###.###.###.###...#.###.###",
	"#.#...#.#.....#...#...#.#.#...#.#.#...#",
	"###...#.###.###...#.###.###...#.###.###"
};

vector<int> possible_number(int x) {
	vector<int> ret;
	for (int i = 0; i < 10; ++i) {
		bool flag = true;

		for (int j = 0; j < 5 && flag; ++j) {
			for (int k = 0; k < 3 && flag; ++k) {
				if (inputs[j][k + x] == '#' && number[j][k + i * 4] == '.')
					flag = false;
			}
		}

		if (flag)
			ret.push_back(i);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < 5; ++i) {
		cin >> inputs[i];
	}

	vector<vector<int>> comb;
	for (int i = 0; i < N; ++i) {
		comb.push_back(possible_number(i * 4));
	}

	// 한 자리라도 안되면 가능한 숫자 없음
	for (int i = 0; i < N; ++i) {
		if (comb[i].size() == 0) {
			cout << -1;
			return 0;
		}
	}

	long long possibleCnt = 1;
	long long ans = 0;
	for (int i = 0; i < N; ++i)
		possibleCnt *= comb[i].size();


	// 첫번째 가능한 숫자의 합 * pow() * 두번째 숫자의 갯수 * 세번째 숫자의 갯수 ...
	// 두번째 가능한 숫자의 합 * pow() * 첫번째 숫자의 갯수 * 세번째 숫자의 갯수 ...
	// ...
	for (int i = 0; i < N; ++i) {
		long long pow_number = pow(10, N - 1 - i);
		long long cnt = possibleCnt / comb[i].size();
		for (int j = 0; j < comb[i].size(); ++j)
			ans += comb[i][j] * pow_number * cnt;
	}

	cout.precision(10);
	cout << fixed;
	cout << (double)ans / possibleCnt;

	return 0;
}