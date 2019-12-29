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

/* 속도 올린 사람의 풀이
if(height[v] == height[u]) continue;
if(height[v] < height[u]) swap(u, v);
adj[u].emplace_back(v, d);
*/

int n, m, d, e;
int height[100001];
vector<pair<int, int>> route[100001];
bool visit[100001];
long long disStart[100001];
long long disEnd[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> d >> e;
	for (int i = 1; i <= n; ++i) {
		cin >> height[i];
		disStart[i] = LLONG_MAX;
		disEnd[i] = LLONG_MAX;
	}

	for (int a, b, c, i = 0; i < m; ++i) {
		cin >> a >> b >> c;

		route[a].push_back({ c, b });
		route[b].push_back({ c, a });
	}

	// 집에서 모든 목표 최단거리
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // 거리, 위치
	pq.push({ 0, 1 });
	disStart[1] = 0;
	while (!pq.empty()) {
		int cur;
		long long dis;
		// if (downward_visited[q_u] == true) continue; 도 가능
		do {
			dis = pq.top().first;
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur])
			break;
		visit[cur] = true;

		for (unsigned int i = 0; i < route[cur].size(); ++i) {
			long long far = route[cur][i].first + dis;
			int next = route[cur][i].second;

			if (height[cur] < height[next] && disStart[next] > far) {
				disStart[next] = far;
				pq.push({ far, next });
			}
		}
	}

	pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>();
	// 학교에서 목표까지 최단거리
	memset(visit, false, sizeof(visit));
	pq.push({ 0, n });
	disEnd[n] = 0;
	while (!pq.empty()) {
		int cur;
		long long dis;

		do {
			dis = pq.top().first;
			cur = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visit[cur]);
		if (visit[cur])
			break;
		visit[cur] = true;

		for (unsigned int i = 0; i < route[cur].size(); ++i) {
			long long far = route[cur][i].first + dis;
			int next = route[cur][i].second;

			if (height[cur] < height[next] && disEnd[next] > far) {
				disEnd[next] = far;
				pq.push({ far, next });
			}
		}
	}

	long long ans = LLONG_MIN;
	for (int i = 2; i < n; ++i) {
		if (disStart[i] != LLONG_MAX && disEnd[i] != LLONG_MAX) {
			long long tmp = (height[i] * e) - (disStart[i] + disEnd[i]) * d;
			ans = max(ans, tmp);
		}
	}
	
	if (ans == LLONG_MIN)
		cout << "Impossible";
	else
		cout << ans;
	return 0;
}