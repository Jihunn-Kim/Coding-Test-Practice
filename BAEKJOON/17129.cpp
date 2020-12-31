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
#include <sstream>
#include <deque>

using namespace std;

int N, M;
char arr[3001][3001];
bool visit[3001][3001];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int sx, sy;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == '2') {
				sx = i;
				sy = j;
			}
		}
	}

	queue<pair<int, int>> que;
	que.push({ sx, sy });
	visit[sx][sy] = true;
	string ans = "NIE";
	int cnt = 0;
	while (!que.empty()) {
		int que_size = que.size();
		for (int qs = 0; qs < que_size; ++qs) {
			int cx = que.front().first;
			int cy = que.front().second;
			que.pop();
			if (arr[cx][cy] == '3' || arr[cx][cy] == '4' || arr[cx][cy] == '5') {
				ans = "TAK";
				break;
			}

			for (int k = 0; k < 4; ++k) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] || arr[nx][ny] == '1')
					continue;

				que.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}

		if (ans == "TAK")
			break;
		++cnt;
	}

	if (ans == "TAK")
		cout << ans << '\n' << cnt;
	else
		cout << ans;

	return 0;
}