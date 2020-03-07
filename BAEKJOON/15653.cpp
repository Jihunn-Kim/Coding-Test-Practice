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
char arr[11][11];
bool check[11][11][11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int red_x, red_y;
	int blue_x, blue_y;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < m; ++j) {
			if (arr[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			else if (arr[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
		}
	}

	queue<tuple<int, int, int, int>> que;
	que.push(make_tuple(red_x, red_y, blue_x, blue_y));
	check[red_x][red_y][blue_x][blue_y] = true;
	int ans = 1;
	while (!que.empty()) {
		int q_size = que.size();
		for (int cnt = 0; cnt < q_size; ++cnt) {
			tie(red_x, red_y, blue_x, blue_y) = que.front();
			que.pop();
			//cout << red_x << ' ' << red_y << '\n';
			for (int k = 0; k < 4; ++k) {
				bool blue_out = false;
				bool red_out = false;

				int n_red_x = red_x, n_red_y = red_y;
				int n_blue_x = blue_x, n_blue_y = blue_y;
				// red ±¼·¯°¨
				while (!red_out && arr[n_red_x + dx[k]][n_red_y + dy[k]] != '#') {
					if (arr[n_red_x + dx[k]][n_red_y + dy[k]] == 'O') {
						red_out = true;
					}
					else if (!blue_out && n_red_x + dx[k] == n_blue_x && n_red_y + dy[k] == n_blue_y) {
						if (arr[n_blue_x + dx[k]][n_blue_y + dy[k]] == '#') // blue ¿¡ ÀÇÇØ ¸·Èû
							break;

						n_blue_x += dx[k];
						n_blue_y += dy[k];
						if (arr[n_blue_x][n_blue_y] == 'O') {
							blue_out = true;
						}
					}
					n_red_x += dx[k];
					n_red_y += dy[k];
				}

				// blue ±¼·¯°¨
				while (!blue_out && arr[n_blue_x + dx[k]][n_blue_y + dy[k]] != '#') {
					if (arr[n_blue_x + dx[k]][n_blue_y + dy[k]] == 'O') {
						blue_out = true;
					}
					else if (!red_out && n_blue_x + dx[k] == n_red_x && n_blue_y + dy[k] == n_red_y) {
						if (arr[n_red_x + dx[k]][n_red_y + dy[k]] == '#') // red ¿¡ ÀÇÇØ ¸·Èû
							break;

						n_red_x += dx[k];
						n_red_y += dy[k];
						if (arr[n_red_x][n_red_y] == 'O') {
							blue_out = true;
						}
					}
					n_blue_x += dx[k];
					n_blue_y += dy[k];
				}

				if (blue_out) // blue ºüÁü
					continue;

				if (red_out) {
					cout << ans;
					return 0;
				}

				if (!check[n_red_x][n_red_y][n_blue_x][n_blue_y]) {
					que.push(make_tuple(n_red_x, n_red_y, n_blue_x, n_blue_y));
					check[n_red_x][n_red_y][n_blue_x][n_blue_y] = true;
				}
			}
		}
		++ans;
	}

	cout << -1;
	return 0;
}