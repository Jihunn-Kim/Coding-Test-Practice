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

/*

*/

int t, n, m;
int arr[51][51];
int psum[51][51]; // 누적합
int dp[51][51][51][51]; // a, b 시작 c, d 끝 의 크기에서 최솟값

int solve(int sx, int sy, int ex, int ey) {

	int& ret = dp[sx][sy][ex][ey];
	if (ret != -1)
		return ret;

	if (sx == ex && sy == ey) // 다 쪼개졌음
		return (ret = 0);

	ret = psum[ex][ey] - psum[sx - 1][ey] - psum[ex][sy - 1] + psum[sx - 1][sy - 1]; // 현재 크기 합
	int tmp = INT_MAX;
	for (int i = sx; i < ex; ++i) { // 가로로
		tmp = min(tmp, solve(sx, sy, i, ey) + solve(i + 1, sy, ex, ey));
	}

	for (int j = sy; j < ey; ++j) { // 세로로 짜름
		tmp = min(tmp, solve(sx, sy, ex, j) + solve(sx, j + 1, ex, ey));
	}

	return (ret += tmp);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {

		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> arr[i][j];
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
			}
		}
		memset(dp, -1, sizeof(dp));

		cout << '#' << tc << ' ' << solve(1, 1, n, m) << '\n';
	}

	return 0;
}