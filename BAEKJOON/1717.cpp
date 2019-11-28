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
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int n, m;
int parent[1000001];
int depth[1000001];
//int dx[] = {0, 1, 0, -1};
//int dy[] = {1, 0, -1, 0};

int find(int u) {
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	
	if (u == v)
		return;

	if (depth[u] > depth[v])
		swap(u, v);

	parent[u] = v;
	if (depth[u] == depth[v])
		++depth[v];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
	}

	int op, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> op >> a >> b;
		if (op) {
			if (find(a) == find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else {
			merge(a, b);
		}
	}
	return 0;
}