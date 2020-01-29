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

/* 빠른 사람
t != dis[next], 
if(t.va != dist[t.vb]) continue;

경로 찾기
printf("%d\n",n-1);
for(int i=1;i<n;i++){
	printf("%d %d\n",i+1,bck[i]+1);
}
*/

int n, m;
vector<pair<int, int>> arr[1001];
int dis[1001];
bool visit[1001];
int parent[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int a, b, c, i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
		dis[a] = dis[b] = 1000000;
	}

	// 1에서 최단 경로
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	dis[1] = 0;
	while (!pq.empty()) {
		int t = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (visit[now])
			continue;

		visit[now] = true;
		for (int i = 0; i < arr[now].size(); ++i) {
			int next = arr[now][i].first;

			if (dis[next] > dis[now] + arr[now][i].second) {
				dis[next] = dis[now] + arr[now][i].second;
				parent[next] = now;
				pq.push({ dis[next], next });
			}
		}
	}

	// 최단 경로 찾기
	vector<pair<int, int>> ans;
	queue<int> que;
	que.push(1);
	while (!que.empty()) {
		int now = que.front();
		que.pop();

		for (int i = 0; i < arr[now].size(); ++i) {
			int next = arr[now][i].first;

			if (parent[next] == now) {
				ans.push_back({ now, next });
				que.push(next);
			}
		}
	}

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}