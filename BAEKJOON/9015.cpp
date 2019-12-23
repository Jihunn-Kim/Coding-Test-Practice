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

int t;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	// set 대신 배열을 사용하여 다른 두 좌표를 빠르게 찾는 다른 사람의 풀이
	// (x,y) -> point[x+10000] 에 y원소가 있다
	// vector< vector<int> > point(22222);

	while (t--) {
		int n, x, y;
		cin >> n;
		set<pair<int, int>> check;
		vector<pair<int, int>> point(n);
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			check.emplace(x, y);
			point[i] = { x, y };
		}

		int ans = 0;
		int x1, y1, x2, y2; // 선택할 두 좌표
		int x3, y3, x4, y4; // 선택된 두 좌표로 부터 계산되어 나온 좌표
		int diffX, diffY;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				x1 = point[i].first;
				y1 = point[i].second;
				x2 = point[j].first;
				y2 = point[j].second;
				diffX = x1 - x2;
				diffY = y1 - y2;

				x3 = x1 + diffY;
				y3 = y1 - diffX;
				x4 = x2 + diffY;
				y4 = y2 - diffX;

				if (check.count({ x3, y3 }) && check.count({ x4, y4 }))
					ans = max(ans, diffX * diffX + diffY * diffY);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}