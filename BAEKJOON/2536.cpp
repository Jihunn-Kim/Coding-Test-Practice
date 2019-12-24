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

/*	bool isCross(Seg &r) {
		return !(s.x > r.e.x || s.y > r.e.y || r.s.x > e.x || r.s.y > e.y);
	}
    입력이 수직, 수평만 주어지기에 이렇게만 확인한 빠른 사람의 풀이가 있음
*/  

int m, n, k, B, sx, sy, dx, dy;
pair<pair<int, int>, pair<int, int>> bus[5001];
int visit[5001];

// 선분 교차 판별
// 참고 : jason9319.tistory.com/358

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	long long op = (long long)a.first*b.second + (long long)b.first*c.second + (long long)c.first*a.second;
	op -= ((long long)a.second*b.first + (long long)b.second*c.first + (long long)c.second*a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
	pair<int, int> a = x.first;
	pair<int, int> b = x.second;
	pair<int, int> c = y.first;
	pair<int, int> d = y.second;
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		//if (a > b)swap(a, b);
		//if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> B;
		cin >> bus[B].first.first >> bus[B].first.second >> bus[B].second.first >> bus[B].second.second;
		if (bus[B].first.second > bus[B].second.second) swap(bus[B].first.second, bus[B].second.second);
		if (bus[B].first.first > bus[B].second.first) swap(bus[B].first.first, bus[B].second.first);
	}
	cin >> sx >> sy >> dx >> dy;

	// 시작 지점에서 탈 수 있는 버스 넣고 bfs
	queue<int> que;
	for (int i = 1; i <= k; ++i) {
		if (bus[i].first.second <= sy && sy <= bus[i].second.second &&
			bus[i].first.first <= sx && sx <= bus[i].second.first) {
			que.push(i);
			visit[i] = 1;
		}
	}

	while (!que.empty()) {
		int curBus = que.front();
		que.pop();

		//cout << curBus << '\n';
		if (bus[curBus].first.second <= dy && dy <= bus[curBus].second.second &&
			bus[curBus].first.first <= dx && dx <= bus[curBus].second.first) {
			cout << visit[curBus];
			break;
		}

		for (int i = 1; i <= k; ++i) {
			if (!visit[i] && isIntersect(bus[curBus], bus[i])) {
				que.push(i);
				visit[i] = visit[curBus] + 1;
			}
		}
	}

	return 0;
}