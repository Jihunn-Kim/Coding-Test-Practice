#pragma warning (disable: 4996)
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
#include <numeric>
#include <typeinfo>
#include <tuple>

using namespace std;

int N, M;
int MAP[301][301];
int diff_MAP[301][301];
bool visit[301][301];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> MAP[i][j];
		}
	}

	int ans = 0;
	bool is_end = false;
	while (true) {

		// ºù»ê µÎµ¢¾î¸® È®ÀÎ
		bool two_chunk = false;
		bool no_ans = true;
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < N; ++i) {
			if (is_end)
				break;
			for (int j = 0; j < M; ++j) {
				if (MAP[i][j] && !visit[i][j]) {
					no_ans = false;
					if (two_chunk) {
						is_end = true;
						break;
					}
					two_chunk = true;

					queue<pair<int, int>> que;
					que.push({ i, j });
					visit[i][j] = true;
					while (!que.empty()) {
						int cx = que.front().first;
						int cy = que.front().second;
						que.pop();

						int diff = 0;
						for (int k = 0; k < 4; ++k) {
							int nx = cx + dx[k];
							int ny = cy + dy[k];

							if (MAP[nx][ny] && !visit[nx][ny]) {
								que.push({ nx, ny });
								visit[nx][ny] = true;
							}
							if (MAP[nx][ny] == 0)
								--diff;
						}
						diff_MAP[cx][cy] = diff;
					}
				}
			}
		}

		if (no_ans) {
			ans = 0;
			break;
		}

		if (is_end)
			break;

		// ºù»ê ³·Ãß±â
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (MAP[i][j]) {
					MAP[i][j] += diff_MAP[i][j];
					if (MAP[i][j] < 0)
						MAP[i][j] = 0;
				}
			}
		}

		++ans;
	}

	cout << ans;

	return 0;
}