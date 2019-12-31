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

const int INF = 1000000000;

/* ���� ��� - �������� ���ͽ�Ʈ��, �ش� ������ ���� ū ������
for (const Edge& e : graph[v.to]) {
	if (cost[e.to] > cost[st]) {
		continue;
	}
}

for (int p = 1; p <= n; ++p) {
	ans = min(ans, dist[p][s] + cost[p] + dist[p][t]);
}
*/

int n, m, q;
int dist[501][501];
int dog[501][501];
pair<int, int> delay[501]; // �ð�, �ε���
int attack[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dist[i][j] = (i == j ? 0 : INF);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cin >> attack[i];
		delay[i].first = attack[i];
		delay[i].second = i;
	}

	for (int a, b, d, i = 0; i < m; ++i) {
		cin >> a >> b >> d;
		if (dist[a][b] > d)
			dist[b][a] = dist[a][b] = d;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dog[i][j] = (i == j ? 0 : dist[i][j] + max(attack[i], attack[j]));
		}
	}

	sort(delay + 1, delay + n + 1); // �ð��� ���� ������ �ϸ� delay �ְ� ���� �ٷ� �� �� �ִ�
	// �÷��̵�
	for (int k = 1; k <= n; ++k) {
		int w = delay[k].second;
		int tt = delay[k].first;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][w] + dist[w][j]);
				dog[i][j] = max(dist[i][j] + max(attack[i], attack[j]), min(dog[i][j], dist[i][w] + tt + dist[w][j]));
			}
		}
	}

	for (int s, t, i = 0; i < q; ++i) {
		cin >> s >> t;
		if (dog[s][t] >= INF)
			cout << -1 << '\n';
		else
			cout << dog[s][t] << '\n';
	}
	return 0;
}