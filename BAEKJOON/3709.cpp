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

int T, N, R;
bool MAP[52][52];
bool visit[52][52][4];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N >> R;

		memset(MAP, false, sizeof(MAP));
		memset(visit, false, sizeof(visit));
		int y, x;
		for (int i = 0; i < R; ++i) {
			cin >> y >> x;
			MAP[x][y] = true;
		}

		cin >> y >> x;
		int dir;
		if (x == 0)
			dir = 1;
		else if (x == N + 1)
			dir = 3;
		else if (y == 0)
			dir = 2;
		else
			dir = 0;

		int cx = x + dx[dir];
		int cy = y + dy[dir];
		visit[cx][cy][dir] = true;
		while (true) {
			if (MAP[cx][cy])
				dir = (dir + 1) % 4;
			
			cx += dx[dir];
			cy += dy[dir];
			if (visit[cx][cy][dir]) {
				cx = 0;
				cy = 0;
				break;
			}
			if (cx < 1 || cx > N || cy < 1 || cy > N) {
				break;
			}
			visit[cx][cy][dir] = true;
		}

		cout << cy << ' ' << cx << '\n';
	}

	return 0;
}