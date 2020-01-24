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
빠른 사람
int go(int cur) {
	int &ret = dp[cur];
	if (ret != -1) return ret;
	if (cur == S) return ret = 0;

	ret = 0;
	for (auto &nxt : adj[cur])
		ret = max(ret, go(nxt.Y.X) + nxt.Y.Y);

	return ret;
}
int rego(int cur, int val) {
	int ret = 0;
	if (cur == S) return 0;

	for (auto &nxt : adj[cur]) if (!visit[nxt.X])
		if (val - nxt.Y.Y == go(nxt.Y.X)) {
			visit[nxt.X] = 1;
			ret += rego(nxt.Y.X, val - nxt.Y.Y) + 1;
		}

	return ret;
}
*/

int n, m, st, en;
vector<pair<int, int>> arr[10001];
vector<pair<int, int>> parent[10001];
bool check[10001];
int dis[10001];

void dfs(int now) {

	for (unsigned int i = 0; i < arr[now].size(); ++i) {
		int next = arr[now][i].first;
		int t = arr[now][i].second;

		if (dis[next] < dis[now] + t) { // 더 먼 경로
			dis[next] = dis[now] + t;
			dfs(next);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int from, to, t, i = 0; i < m; ++i) {
		cin >> from >> to >> t;
		arr[from].push_back({ to, t });
		parent[to].push_back({ from, t });
	}
	cin >> st >> en;

	dfs(st);
	cout << dis[en] << '\n';

	int cnt = 0;
	queue<int> par;
	par.push(en);
	while (!par.empty()) {
		int now = par.front();
		par.pop();

		for (unsigned int i = 0; i < parent[now].size(); ++i) {
			int next = parent[now][i].first;
			int t = parent[now][i].second;

			if (dis[next] == dis[now] - t) {
				if (!check[next]) // 중복 방지
					par.push(next);

				check[next] = true;
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}