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
int arr[9][9];
int tmp[9][9];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int safe = n * m;
	int area = safe;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] != 0)
				--safe;
		}
	}

	// 벽 3개를 세울 위치
	int ans = -1;
	int r1, r2, r3;
	int c1, c2, c3;
	for (int i = 0; i < area; ++i) {
		r1 = i / m;
		c1 = i % m;
		if (arr[r1][c1] != 0)
			continue;
		for (int j = i + 1; j < area; ++j) {
			r2 = j / m;
			c2 = j % m;
			if (arr[r2][c2] != 0)
				continue;
			for (int k = j + 1; k < area; ++k) {
				r3 = k / m;
				c3 = k % m;
				if (arr[r3][c3] != 0)
					continue;

				// 벽 세우고 전파 시작
				queue<pair<int, int>> virus;
				for (int p = 0; p < n; ++p) {
					for (int q = 0; q < m; ++q) {
						tmp[p][q] = arr[p][q];
						if (tmp[p][q] == 2)
							virus.push({ p, q });
					}
				}
				tmp[r1][c1] = tmp[r2][c2] = tmp[r3][c3] = 1;
				int localAns = safe - 3;
				while (!virus.empty()) {
					int cx = virus.front().first;
					int cy = virus.front().second;
					virus.pop();
					for (int p = 0; p < 4; ++p) {
						int nx = cx + dx[p];
						int ny = cy + dy[p];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || tmp[nx][ny] != 0)
							continue;

						tmp[nx][ny] = 2;
						virus.push({ nx, ny });
						--localAns;
					}
				}
				
				//cout << localAns << ' ';
				if (ans < localAns)
					ans = localAns;
			}
		}
	}

	cout << ans;
	return 0;
}