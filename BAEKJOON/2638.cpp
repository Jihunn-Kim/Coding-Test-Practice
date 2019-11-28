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

int n, m;
int arr[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	set<pair<int, int>> cheese;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				cheese.insert({ i, j });
		}
	}
	// 외부 공기
	queue<pair<int, int>> air;
	air.push({ 0, 0 });
	arr[0][0] = -1;
	while (!air.empty()) {
		int cx = air.front().first;
		int cy = air.front().second;
		air.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != 0)
				continue;

			air.push({ nx, ny });
			arr[nx][ny] = -1;
		}
	}
	
	int ans = 0;
	while (!cheese.empty()) {
		for (auto it = cheese.begin(); it != cheese.end(); ++it) {
			int cx = (*it).first;
			int cy = (*it).second;

			int check = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];

				if (arr[nx][ny] == -1)
					++check;
			}
			if (check > 1) {
				air.push({ cx, cy });
			}
		}

		while (!air.empty()) {
			int cx = air.front().first;
			int cy = air.front().second;
			air.pop();
			arr[cx][cy] = -1;
			cheese.erase({ cx, cy });

			for (int i = 0; i < 4; ++i) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != 0)
					continue;

				air.push({ nx, ny });
				arr[nx][ny] = -1;
			}
		}

		++ans;
	}

	cout << ans;
	return 0;
}