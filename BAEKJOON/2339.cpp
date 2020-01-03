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

// beginthread.tistory.com/18

int B[21][21][2];

int available(int start[2], int end[2]) {
	int cnt[3] = { 0, };
	for (int i = start[0]; i <= end[0]; ++i)
		for (int j = start[1]; j <= end[1]; ++j)
			++cnt[B[i][j][0]];

	if (cnt[2] == 0)return 0; // 보석 없음
	if (cnt[2] == 1) {
		if (cnt[1] == 0)return 1;
		else return 0; // 보석 <= 불순물 -> 잘라진 두 석판 중 하나는 보석이 없다
	}
	if (cnt[1] == 0)return 0; // 불순물 없음 -> 자를 수 없다
	return 2;
}

int cut(int start[2], int end[2], bool d) {
	int k = available(start, end);
	if (k == 0) return 0;
	if (k == 1) return 1;

	int ret = 0;
	for (int u = start[!d] + 1; u < end[!d]; ++u) { // 잘라진 석판은 반드시 두 개의 석판, 행 혹은 열 끝 무시
		bool possible = false;
		for (int v = start[d]; v <= end[d]; ++v) {
			if (B[u][v][!d] == 2) {
				possible = false;
				break;
			}
			if (B[u][v][!d] == 1)possible = true;
		}
		if (!possible)continue;

		int tmp1[2][2] = { {end[0],u - 1},{u - 1,end[1]} };
		int tmp2[2][2] = { {start[0],u + 1},{u + 1,start[1]} };

		int first = cut(start, tmp1[d], !d);
		if (first == 0)continue;

		int second = cut(tmp2[d], end, !d);
		if (second == 0)continue;

		ret += (first * second);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> B[i][j][0];
			B[j][i][1] = B[i][j][0];
		}
	}

	int start[] = { 0, 0 }, end[] = { n - 1, n - 1 };
	int result = cut(start, end, 1) + cut(start, end, 0);

	if (result == 0) cout << -1;
	else cout << result;

	return 0;
}