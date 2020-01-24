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
코드 - jaimemin.tistory.com/1243?category=988050
pq 안쓴 사람
queue<_d> q[2];
	q[c = 0].push(src);
	dp[src.y][src.x] = 0;
	while (!q[0].empty() || !q[1].empty()) {
		if (q[c].empty()) {
			d++;
			c = !c;
		}
		_d u = q[c].front(); q[c].pop();
		for (i = 0; i < 4; i++) {
			int ty = u.y + dy[i], tx = u.x + dx[i];
			if (0 <= ty && ty <= N + 1 && 0 <= tx && tx <= M + 1 && board[ty][tx] != '*' && dp[ty][tx] == -1) {
				dp[ty][tx] = d;
				q[(board[ty][tx] == '#' ? !c : c)].push({ ty,tx });
			}
		}
	}
*/

typedef pair<int, pair<int, int>> piii;

int t, h, w;
char arr[102][102];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> h >> w;

		vector<pair<int, int>> prisoner;
		prisoner.push_back({ 0, 0 }); // 상근이
		for (int i = 1; i <= h; ++i) {
			cin >> (arr[i] + 1);
			for (int j = 1; j <= w; ++j) {
				if (arr[i][j] == '$')
					prisoner.push_back({ i, j });
			}
		}

		int distance[3][102][102];
		for (int i = 0; i < 3; i++) {
			// {거리, {죄수 좌표}}
			priority_queue<piii, vector<piii>, greater<piii>> pq;
			pq.push({ 0,{ prisoner[i] } });

			distance[i][prisoner[i].first][prisoner[i].second] = 0;

			bool visited[102][102] = { false, };
			while (!pq.empty()) {
				int y = pq.top().second.first;
				int x = pq.top().second.second;
				pq.pop();

				for (int j = 0; j < 4; j++) {
					int nextY = y + dx[j];
					int nextX = x + dy[j];

					if (0 <= nextY && nextY <= h + 1 && 0 <= nextX && nextX <= w + 1) {
						if (visited[nextY][nextX] || arr[nextY][nextX] == '*')
							continue;

						int nextDistance = distance[i][y][x];
						if (arr[nextY][nextX] == '#')
							nextDistance++;

						distance[i][nextY][nextX] = nextDistance;
						visited[nextY][nextX] = true;
						pq.push({ nextDistance,{ nextY, nextX } });
					}
				}
			}
		}

		int result = 987654321;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (arr[i][j] != '*') {
					int total = 0;
					for (int k = 0; k < 3; k++) {
						total += distance[k][i][j];
					}

					/*
					단 한번만 문을 열면 되지만
					세번 연다고 계산이 되어 있으므로
					-2를 해준다
					*/
					total -= 2 * (arr[i][j] == '#');
					result = min(result, total);
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}