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


int n, m, p;
queue<pair<int, int>> loc[10];
int sp[10];
char arr[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ans[10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> p;

	for (int i = 1; i <= p; ++i) {
		cin >> sp[i];
	}

	int dotcnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < m; ++j) {
			if ('1' <= arr[i][j] && arr[i][j] <= '9') {
				int idx = arr[i][j] - '0';
				ans[idx]++;
				loc[idx].push({ i, j });
			}
			else if (arr[i][j] == '.') {
				dotcnt++;
			}
		}
	}

	while (dotcnt) {
		bool is_end = true;
		for (int i = 1; i <= p; ++i) { // 플레이어 마다
			for (int j = 1; j <= sp[i]; ++j) { // 넓히는 횟수 마다
				int size = loc[i].size();
				if (size == 0)
					break;
				
				is_end = false;
				for (int k = 0; k < size; ++k) {  // 확장할 성 마다
					int cx = loc[i].front().first;
					int cy = loc[i].front().second;
					loc[i].pop();
					for (int p = 0; p < 4; ++p) {
						int nx = cx + dx[p];
						int ny = cy + dy[p];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] != '.')
							continue;

						arr[nx][ny] = arr[cx][cy];
						ans[arr[cx][cy] - '0']++;
						dotcnt--;
						loc[i].push({ nx, ny });
					}
				}
			}
		}
		if (is_end)
			break;
	}

	for (int i = 1; i <= p; ++i) {
		cout << ans[i] << ' ';
	}
	return 0;
}