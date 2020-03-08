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
#include <math.h>

using namespace std;

// 코드 - js1jj2sk3.tistory.com/28

int n, m;
char arr[51][51];
int key_num[51][51];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int key_cnt;
vector<pair<int, pair<int, int>>> edge; // dis, x, y
int parent[251];

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

int bfs(int x, int y) {
	bool check[51][51] = { false, };
	int dis[51][51] = { 0, };
	queue<pair<int, int>> que;
	que.push({x, y});
	check[x][y] = true;

	int ret = 0;
	while (!que.empty()) {
		int cx = que.front().first;
		int cy = que.front().second;
		que.pop();

		for (int k = 0; k < 4; ++k) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (arr[nx][ny] == '1' || check[nx][ny])
				continue;

			dis[nx][ny] = dis[cx][cy] + 1;
			if (arr[nx][ny] == 'K') {
				++ret;
				edge.push_back({ dis[nx][ny], {key_num[x][y], key_num[nx][ny]} });
			}

			que.push({ nx, ny });
			check[nx][ny] = true;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<pair<int, int>> key_loc;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 'S') {
				arr[i][j] = 'K';
			}
			else if (arr[i][j] == 'K') {
				++key_cnt;
				key_num[i][j] = key_cnt;
				key_loc.push_back({ i, j });
			}
		}
	}
	// 한 key 에서 나머지 key 갈 수 있어야 함
	for (int i = 0; i < key_cnt; ++i) {
		if (bfs(key_loc[i].first, key_loc[i].second) != key_cnt) {
			cout << -1;
			return 0;
		}
	}
	// 스패닝 트리 시작
	sort(edge.begin(), edge.end());

	// union find 초기화
	for (int i = 0; i <= key_cnt; ++i)
		parent[i] = i;

	int edge_cnt = 0;
	int ans = 0;
	for (int i = 0; edge_cnt != key_cnt; ++i) {
		int cx = find(edge[i].second.first);
		int cy = find(edge[i].second.second);

		if (cx != cy) {
			merge(cx, cy);
			ans += edge[i].first;
			++edge_cnt;
		}
	}

	cout << ans;

	return 0;
}