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

int n, k, x, y;
int par[100001];
int rnk[100001];
int arr[2001][2001];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int find(int v) {
	if (v == par[v]) return v;
	return par[v] = find(par[v]);
}

bool merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return false;

	if (rnk[u] > rnk[v]) swap(u, v);
	par[u] = v;
	if (rnk[u] == rnk[v]) rnk[v]++;
	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	queue<pair<int, int>> unionQue;
	queue<pair<int, int>> moveQue;
	for (int i = 1; i <= k; ++i) {
		cin >> x >> y;
		arr[x][y] = i;
		unionQue.push({ x, y });

		par[i] = i;
		rnk[i] = 1;
	}

	int ans = 0;
	while (k > 1) {
		// 합치기
		while (!unionQue.empty()) {
			int cx = unionQue.front().first;
			int cy = unionQue.front().second;
			unionQue.pop();
			moveQue.push({ cx, cy });

			for (int j = 0; j < 4; ++j) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (1 > nx || n < nx || 1 > ny || n < ny)
					continue;

				if (arr[nx][ny] && arr[cx][cy] != arr[nx][ny]) {
					if (merge(arr[cx][cy], arr[nx][ny])) {
						--k;
					}
				}
			}
		}

		if (k == 1)
			break;

		// 확장하기
		while (!moveQue.empty()) {
			int cx = moveQue.front().first;
			int cy = moveQue.front().second;
			moveQue.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = cx + dx[j];
				int ny = cy + dy[j];
				if (1 > nx || n < nx || 1 > ny || n < ny)
					continue;

				if (!arr[nx][ny]) {
					arr[nx][ny] = arr[cx][cy];
					unionQue.push({ nx, ny });
				}
				else if (arr[cx][cy] != arr[nx][ny]) {
					if (merge(arr[cx][cy], arr[nx][ny])) {
						--k;
					}
				}
			}
		}

		++ans;
	}
	cout << ans;
	return 0;
}