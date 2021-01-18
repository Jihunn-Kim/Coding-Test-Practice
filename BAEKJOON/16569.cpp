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

using namespace std;

typedef tuple<int, int, int> loc; // time, x, y

int M, N, V, X, Y;
int MAP[101][101];
int volcano[101][101];
int visit[101][101];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
const int MAX = int(1e8);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> M >> N >> V >> X >> Y;
	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> MAP[i][j];
			volcano[i][j] = MAX;
			visit[i][j] = MAX;
		}
	}

	// 사람
	queue<loc> que;
	que.push(make_tuple(0, X, Y));
	visit[X][Y] = 0;

	// 화산
	priority_queue<loc, vector<loc>, greater<loc>> pq;
	for (int x, y, t, i = 0; i < V; ++i) {
		cin >> x >> y >> t;
		pq.push(make_tuple(t, x, y));
		volcano[x][y] = t;
		visit[x][y] = -1; // 사람 화산 못밟음
	}
	
	int time_, cx, cy;
	int ans_height = -1, ans_time;

	// 화산 이동
	while (!pq.empty()) {
		tie(time_, cx, cy) = pq.top();
		pq.pop();

		if (volcano[cx][cy] < time_)
			continue;

		for (int k = 0; k < 4; ++k) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx > M || ny < 0 || ny > N || volcano[nx][ny] <= time_ + 1)
				continue;
	
			volcano[nx][ny] = time_ + 1;
			pq.push(make_tuple(time_ + 1, nx, ny));
		}	
	}

	// 사람 이동
	while (!que.empty()) {
		tie(time_, cx, cy) = que.front();
		que.pop();

		if (MAP[cx][cy] > ans_height) {
			ans_height = MAP[cx][cy];
			ans_time = time_;
		}

		for (int k = 0; k < 4; ++k) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx < 0 || nx > M || ny < 0 || ny > N || volcano[nx][ny] <= time_ + 1 || visit[nx][ny] <= time_ + 1)
				continue;
			
			visit[nx][ny] = time_ + 1;
			que.push(make_tuple(time_ + 1, nx, ny));
		}
	}

	cout << ans_height << ' ' << ans_time;

	return 0;
}