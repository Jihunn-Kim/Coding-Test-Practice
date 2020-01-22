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
설명 - bowbowbow.tistory.com/7
*/

int visit[51][51][4][4]; // row, col, dir, 10 - c2, 01 - c1, 11 - c2c1
int n, m, total;
char arr[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = -1;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;

	memset(visit, -1, sizeof(visit));

	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (arr[i][j] == 'S') { // 시작 네방향 다 넣음
				for (int k = 0; k < 4; k++) {
					q.push(make_tuple(i, j, k, 0));
					visit[i][j][k][0] = 0;
				}

			}
			else if (arr[i][j] == 'C') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					x2 = j;
				}
			}
		}
	}

	while (!q.empty()) {
		int x, y, dir, s;
		tie(x, y, dir, s) = q.front();
		q.pop();

		if (s == 3) {
			ans = visit[x][y][dir][s];
			break;
		}

		for (int k = 0; k < 4; k++) {
			if (dir == k)
				continue;

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (arr[nx][ny] != '#') {

					int ns = s;
					if (arr[nx][ny] == 'C') {

						if (nx == x1 && ny == y1) { // c1
							ns |= 1;
						}
						else { // c2
							ns |= 2;
						}

					}

					if (visit[nx][ny][k][ns] == -1) {
						visit[nx][ny][k][ns] = visit[x][y][dir][s] + 1;
						q.push(make_tuple(nx, ny, k, ns));
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}