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
char arr[51][51];
bool check[51][51][1 << 5];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	queue<pair<pair<int, int>, pair<int, int>>> que;
	int xcount = 0;
	for (int i = 0; i < m; ++i) {
		cin >> arr[i];
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 'S')
				que.push({ { i, j }, {0, 0} });
			else if (arr[i][j] == 'X') {
				++xcount;
				arr[i][j] = '0' + xcount;
			}
		}
	}

	xcount = (1 << xcount) - 1;
	check[0][0][0] = true;
	int ans = -1;
	// 다 찾고 E 라면 종료
	while (!que.empty()) {
		int cx = que.front().first.first;
		int cy = que.front().first.second;
		int dis = que.front().second.first;
		int cnt = que.front().second.second;
		//cout << cx << ' ' << cy << ' ' << cnt << '\n';
		que.pop();

		if (cnt == xcount && arr[cx][cy] == 'E') {
			ans = dis;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || arr[nx][ny] == '#')
				continue;
			
			if ('1' <= arr[nx][ny] && arr[nx][ny] <= '5') {
				int ncnt = (1 << (arr[nx][ny] - '1'));
				if (!check[nx][ny][cnt | ncnt]) {
					que.push({ {nx, ny}, {dis + 1, cnt | ncnt } });
					check[nx][ny][cnt | ncnt] = true;
				}
			}
			else if (!check[nx][ny][cnt]) {
				que.push({ {nx, ny}, {dis + 1, cnt } });
				check[nx][ny][cnt] = true;
			}
		}
	}
	cout << ans;
	return 0;
}