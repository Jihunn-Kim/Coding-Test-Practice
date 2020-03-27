#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <math.h>

using namespace std;

/* �������
���ͽ�Ʈ�� �ϱ� ���� �ִ� �Ÿ��� ������ �ִ� ������ ã�´�.
ó�� �ִܰŸ��� ���� �� ��θ� ����ص�
	int tmp=n;
	while(tmp!=1){
		edge.push_back(node{tmp,pre[tmp]});
		tmp=pre[tmp];
	}

	for(auto& x:edge){
		a=x.num; b=x.d;
		chk[a]=chk[b]=1;
		int k=Dijkstra();
		chk[b]=chk[a]=0; ...

	Dijkstra() { ...
		if(chk[cur]&&chk[next.num]) continue;

*/

int N, M;
vector<pair<int, int>> city[1001];
pair<int, int> road[5001];
int dis[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int a, b, t, i = 1; i <= M; ++i) {
		cin >> a >> b >> t;
		city[a].push_back({ t, b });
		city[b].push_back({ t, a });
		road[i] = { a, b };
	}

	// ó�� ���� ���� ���� �� �ִܰŸ�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	que.push({ 0, 1 });
	int original_dis = -1;
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	while (!que.empty()) {
		int _dis = que.top().first;
		int _now = que.top().second;
		que.pop();
		//cout << _dis << ' ' << _now << '\n';

		if (_now == N) {
			original_dis = _dis;
			break;
		}

		for (int i = 0; i < city[_now].size(); ++i) {
			int _next = city[_now][i].second;
			if (dis[_next] == -1 || dis[_next] > _dis + city[_now][i].first) {
				dis[_next] = _dis + city[_now][i].first;
				que.push({ _dis + city[_now][i].first, _next });
			}
		}
	}

	// ���� �ϳ��� �����ϸ鼭 �ִܰŸ� ã��
	int ans = 0;
	for (int idx = 1; idx <= M; ++idx) {
		memset(dis, -1, sizeof(dis));

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
		que.push({ 0, 1 });
		int dis_end = -1;
		while (!que.empty()) {
			int _dis = que.top().first;
			int _now = que.top().second;
			que.pop();

			if (_now == N) {
				dis_end = _dis;
				break;
			}

			for (int i = 0; i < city[_now].size(); ++i) {
				int _next = city[_now][i].second;
				if (road[idx].first == _now && road[idx].second == _next)
					continue;
				if (road[idx].second == _now && road[idx].first == _next)
					continue;
				if (dis[_next] == -1 || dis[_next] > _dis + city[_now][i].first) {
					dis[_next] = _dis + city[_now][i].first;
					que.push({ _dis + city[_now][i].first, _next });
				}
			}
		}

		if (dis_end == -1) {
			ans = -1;
			break;
		}
		else {
			if (dis_end - original_dis > ans) {
				ans = dis_end - original_dis;
			}
		}
	}
	cout << ans;
	return 0;
}