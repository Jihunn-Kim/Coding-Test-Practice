#pragma warning (disable: 4996)
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
#include <typeinfo>

using namespace std;

int N, M;
vector<pair<int, int>> graph[50001];
int dist[50001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int a, b, c, i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	for (int i = 1; i <= N; ++i) {
		dist[i] = INT_MAX;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int now_length = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if (dist[now] < now_length)
			continue;

		for (int k = 0; k < graph[now].size(); ++k) {
			int next = graph[now][k].first;
			int next_length = graph[now][k].second + now_length;
			if (dist[next] <= next_length)
				continue;

			pq.push({ next_length, next });
			dist[next] = next_length;
		}
	}

	cout << dist[N];

	return 0;
}