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
빠른사람, LCA 를 별로 안깊어서 그냥함?
void labeling(int n, int d){ // 부모랑 길이 정함
	depth[n] = d;
	for( auto child : adj[n] ){
		if (depth[child.first] == 0) {
			parent[child.first].first = n;
			parent[child.first].second = child.second;
			labeling(child.first, d+1);
		}
	}
}

int ret = 0;
while (depth[n1] > depth[n2]) { // 깊이 깊은놈 올림
	ret += parent[n1].second;
	n1 = parent[n1].first;
}
while (n1 != n2) { // 더함
	ret += parent[n1].second+parent[n2].second;
	n1 = parent[n1].first; n2 = parent[n2].first;
}
printf("%d\n", ret);
*/

int n, m;
vector<pair<int, int>> arr[1001];
bool visit[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int a, b, c, i = 0; i < n - 1; ++i) {
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}

	for (int a, b, i = 0; i < m; ++i) { // 죄다 dfs
		cin >> a >> b;
		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> que;
		que.push({ a, 0 });
		visit[a] = true;
		while (!que.empty()) {
			int now = que.front().first;
			int dis = que.front().second;
			que.pop();
			if (now == b) {
				cout << dis << '\n';
				break;
			}

			for (int j = 0; j < arr[now].size(); ++j) {
				int next = arr[now][j].first;
				int far = arr[now][j].second;
				if (!visit[next]) {
					visit[next] = true;
					que.push({ next, dis + far });
				}
			}
		}
	}

	return 0;
}