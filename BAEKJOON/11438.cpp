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

int n, m;
vector<int> tree[100001];
int parent[100001][21];
int depth[100001];
bool check[100001];

int LCA(int a, int b) {

	if (depth[a] < depth[b])
		swap(a, b);

	int diff = depth[a] - depth[b];
	for (int j = 0; diff; j++) {
		if (diff & 1)
			a = parent[a][j];
		diff >>= 1;
	}

	if (a != b) {
		for (int j = 20; j >= 0; j--) {
			if (parent[a][j] != parent[b][j]) {
				a = parent[a][j];
				b = parent[b][j];
			}
		}
		a = parent[a][0];
	}
	return a;
}

void makeTree(int now) {
	check[now] = true;
	for (int i = 0; i < tree[now].size(); ++i) {
		int next = tree[now][i];
		if (check[next])
			continue;

		parent[next][0] = now;
		depth[next] = depth[now] + 1;
		makeTree(next);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int a, b, i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	makeTree(1);

	// LCA 
	for (int j = 0; j < 19; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j + 1] = parent[parent[i][j]][j];

	cin >> m;
	for (int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}