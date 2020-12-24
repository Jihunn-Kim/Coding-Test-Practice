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

using namespace std;

int n, m;
int arr[1001][1001];
int ans[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	char tmp[1001];
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < m; ++j) {
			arr[i][j] = tmp[j] - '0';
		}
	}

	// 영역 나누기
	int area = 2;
	map<int, int> area_cnt;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 0) {
				// bfs
				queue<pair<int, int>> que;
				que.push({ i, j });
				arr[i][j] = area;
				int cnt = 1;
				while (!que.empty()) {
					int cx = que.front().first;
					int cy = que.front().second;
					que.pop();

					for (int k = 0; k < 4; ++k) {
						int nx = cx + dx[k];
						int ny = cy + dy[k];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;

						if (arr[nx][ny] == 0) {
							arr[nx][ny] = area;
							que.push({ nx, ny });
							++cnt;
						}
					}
				}
				area_cnt[area] = cnt;
				++area;
			}
		}
	}

	// 주변 영역 더하기
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 1) {
				ans[i][j] = 1;
				set<int> check;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;

					if (arr[nx][ny] > 1) {
						if (!check.count(arr[nx][ny])) {
							check.insert(arr[nx][ny]);
							ans[i][j] += area_cnt[arr[nx][ny]];
						}
					}
				}

			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j] % 10;
		}
		cout << '\n';
	}

	return 0;
}