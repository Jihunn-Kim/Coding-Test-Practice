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

/* 

*/

int N, M;
char type[1001];
vector<pair<int, pair<int, int>>> connect;
int parent[1001];
int _rank[1001];

int _find(int one) {
	if (parent[one] == one)
		return one;
	return parent[one] = _find(parent[one]);
}

bool _merge(int one_para, int other_para) {
	int one = _find(one_para);
	int other = _find(other_para);
	if (one == other)
		return false;

	if (_rank[one] < _rank[other])
		swap(one, other);

	parent[other] = one;
	if (_rank[one] == _rank[other])
		++_rank[one];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> type[i];
	}
	
	for (int u, v, d, i = 1; i <= M; ++i) {
		cin >> u >> v >> d;
		if (type[u] == type[v])
			continue;
		connect.push_back({ d, {u, v} });
	}
	sort(connect.begin(), connect.end());

	for (int i = 1; i < 1001; ++i) {
		parent[i] = i;
		_rank[i] = 1;
	}

	int cnt = 0, idx = 0, ans = 0;
	while (cnt != N - 1 && idx < connect.size()) {
		int dis = connect[idx].first;
		int one = connect[idx].second.first;
		int other = connect[idx].second.second;

		if (_merge(one, other)) {
			ans += dis;
			++cnt;
		}
		++idx;
	}

	if (cnt != N - 1)
		cout << -1;
	else
		cout << ans;

	return 0;
}