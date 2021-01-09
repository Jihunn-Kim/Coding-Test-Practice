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

int N, M;
int visual[100001];
vector<pair<int, int>> graph[100001];
long long dist[100001];
const long long INF = (1LL << 60);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> visual[i];
		dist[i] = INF;
	}
	visual[N - 1] = 0;
	for (int a, b, t, i = 0; i < M; ++i) {
		cin >> a >> b >> t;
		if (visual[a] || visual[b])
			continue;
		graph[a].push_back({ b, t });
		graph[b].push_back({ a, t });
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({ 0, 0 });
	dist[0] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		long long dis = pq.top().first;
		pq.pop();
		if (dist[now] < dis)
			continue;

		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first;
			long long next_dis = dis + graph[now][i].second;
			if (dist[next] <= next_dis)
				continue;

			pq.push({ next_dis, next });
			dist[next] = next_dis;
		}
	}

	if (dist[N - 1] == INF)
		dist[N - 1] = -1;
	cout << dist[N - 1];

	return 0;
}