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
vector<int> dduck[1001];
bool visit[1001][1001];
int ans[1001];
bool is_end = false;

void solve(int day, int prev_dduck) {
	if (visit[day][prev_dduck])
		return;

	if (is_end)
		return;

	if (day == N) {
		for (int i = 0; i < N; ++i) {
			cout << ans[i] << '\n';
		}
		is_end = true;
		return;
	}

	visit[day][prev_dduck] = true;

	for (int i = 0; i < dduck[day].size(); ++i) {
		int now_dduck = dduck[day][i];
		if (now_dduck == prev_dduck)
			continue;

		ans[day] = now_dduck;
		solve(day + 1, now_dduck);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int m, i = 0; i < N; ++i) {
		cin >> m;
		for (int a, j = 0; j < m; ++j) {
			cin >> a;
			dduck[i].push_back(a);
		}
	}

	solve(0, -1);
	if (!is_end)
		cout << -1;

	return 0;
}