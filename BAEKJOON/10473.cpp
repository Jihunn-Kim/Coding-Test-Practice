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

double sx, sy, ex, ey;
int n;
double cannon_x[103];
double cannon_y[103];
double time5[103];
double dx, dy, tmp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> sx >> sy >> ex >> ey;
	cin >> n;

	priority_queue<pair<double, int>> pq;

	cannon_x[n] = ex;
	cannon_y[n] = ey;
	dx = ex - sx;
	dy = ey - sy;
	tmp = sqrt(dx * dx + dy * dy) / 5.0;
	time5[n] = tmp;
	for (int i = 0; i < n; ++i) {
		cin >> cannon_x[i] >> cannon_y[i];
		dx = sx - cannon_x[i];
		dy = sy - cannon_y[i];
		tmp = sqrt(dx * dx + dy * dy) / 5.0;
		time5[i] = tmp;
		pq.push({ tmp, i });
	}

	while (!pq.empty()) {
		double t = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (abs(time5[now] - t) > 1e-6)
			continue;

		for (int i = 0; i <= n; ++i) {
			if (i == now)
				continue;

			dx = cannon_x[now] - cannon_x[i];
			dy = cannon_y[now] - cannon_y[i];
			tmp = sqrt(dx * dx + dy * dy); // �ɾ
			tmp = min(tmp / 5.0, abs(tmp - 50.0) / 5.0 + 2.0);

			if (time5[i] > t + tmp) {
				time5[i] = t + tmp;
				if (i != n)
					pq.push({ t + tmp, i });
			}
		}

	}
	cout.precision(6);
	cout << time5[n];
	return 0;
}