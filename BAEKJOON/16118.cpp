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

typedef pair<long long, pair<long long, int>> piii;
typedef pair<long long, long long> pii;

int n, m;
vector<pair<long long, long long>> arr[4001];
long long dis_fox[4001];
long long dis_wolf[4001][2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (long long a, b, d, i = 0; i < m; ++i) {
		cin >> a >> b >> d;
		arr[a].push_back({ d * 2, b });
		arr[b].push_back({ d * 2, a });
	}
	for (int i = 1; i <= n; i++) {
		dis_fox[i] = dis_wolf[i][0] = dis_wolf[i][1] = 2e9;
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq; // 여우 최단거리
	pq.push({ 0, 1 });
	dis_fox[1] = 0;
	while (!pq.empty()) {
		long long t = pq.top().first;
		long long now = pq.top().second;
		pq.pop();
		if (dis_fox[now] != t)
			continue;

		for (int i = 0; i < arr[now].size(); ++i) {
			long long tt = arr[now][i].first;
			long long next = arr[now][i].second;

			if (dis_fox[next] == -1 || dis_fox[next] > t + tt) {
				dis_fox[next] = t + tt;
				pq.push({ t + tt, next });
			}
		}
	}
	
	priority_queue<piii, vector<piii>, greater<piii>> pqq;
	pqq.push({ 0, {1, 0} });
	dis_wolf[1][0] = 0;
	while (!pqq.empty()) {
		long long t = pqq.top().first;
		long long now = pqq.top().second.first;
		int type = pqq.top().second.second;
		pqq.pop();
		if (dis_wolf[now][type] != t)
			continue;

		for (int i = 0; i < arr[now].size(); ++i) {
			long long tt = arr[now][i].first;
			long long next = arr[now][i].second;
			
			if (type == 0) // 홀수면 절반
				tt >>= 1;
			else
				tt <<= 1;

			int ntype = type ^ 1;
			if (dis_wolf[next][ntype] == -1 || dis_wolf[next][ntype] > t + tt) {
				dis_wolf[next][ntype] = t + tt;
				pqq.push({ t + tt, {next, ntype} });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (dis_fox[i] < min(dis_wolf[i][0], dis_wolf[i][1]))
			++ans;
		//cout << dis_fox[i] << ' ' << min(dis_wolf[i][0], dis_wolf[i][1]) << '\n';
	}
	cout << ans;
	return 0;
}