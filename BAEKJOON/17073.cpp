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

/* 빠른사람
for (int i = 0; i < N - 1; i++) {
	int x, y;
	x = fio::readInt();
	y = fio::readInt();
	x --;
	y --;
	G[x] ++;
	G[y] ++;
}
int cnt = 0;
for (int i = 1; i < N; i ++) // 루트 제외, 간선 하나만 있으면 리프
	cnt += (G[i] == 1);
*/

int n, ans;
double w;
vector<int> arr[500001];
bool check[500001];

void dfs(int now) {
	check[now] = true;
	int cnt = 0;
	for (int i = 0; i < arr[now].size(); ++i) {
		int next = arr[now][i];
		if (check[next])
			continue;
		
		++cnt;
		dfs(next);
	}
	if (cnt == 0)
		++ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> w;
	for (int u, v, i = 1; i < n; ++i) {
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	dfs(1);

	w /= ans;
	cout.precision(10);
	cout << fixed << w;

	return 0;
}