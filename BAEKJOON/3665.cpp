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
위상정렬, 코드 - js1jj2sk3.tistory.com/101

다른 사람
int rank[501];
for (int i = 0; i < n; ++i) rank[readInt()] = i + 1;

int ans[501];
memcpy(ans, rank, sizeof(ans));

int m = readInt();

for (int i = 0; i < m; ++i) {
	int a = readInt(), b = readInt();

	if (rank[a] > rank[b]) --ans[a], ++ans[b]; // 뒤바뀌면 등수가 바뀐다?
	else ++ans[a], --ans[b];
}

int order[501]{};
for (int i = 1; i <= n; ++i) {
	int t = ans[i];
	if (order[t]) {
		puts("IMPOSSIBLE"); // 같은 등수면 에러?
		return;
	}
	order[t] = i;
}
*/

int t, n, m, a, b;
int mat[501][501], order[501], in[501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		memset(mat, 0, sizeof(mat));
		memset(in, 0, sizeof(in));

		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> order[i];

		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				mat[order[i]][order[j]] = 1; // 뒤짚어도 나머지는 유지를 위해
				in[order[j]]++;
			}
		}

		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			if (mat[a][b]) {
				mat[a][b] = 0;
				mat[b][a] = 1;
				in[b]--, in[a]++;
			}
			else {
				mat[b][a] = 0;
				mat[a][b] = 1;
				in[a]--, in[b]++;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; ++i)
			if (!in[i])
				q.push(i);

		bool certain = true;
		vector<int> ans;
		while (!q.empty()) {
			if (q.size() > 1) { // indegree 0 인 노드가 여러개라 순위가 애매함
				certain = false;
				break;
			}

			int cur = q.front();
			q.pop();
			ans.push_back(cur);

			for (int next = 1; next <= n; ++next) {
				if (mat[cur][next]) {
					in[next]--;
					if (!in[next])
						q.push(next);
				}
			}
		}

		if (!certain)
			cout << "?\n";
		else if (ans.size() == n) {
			for (int i = 0; i < n; ++i)
				cout << ans[i] << ' ';
			cout << '\n';
		}
		else
			cout << "IMPOSSIBLE\n";
	}

	return 0;
}