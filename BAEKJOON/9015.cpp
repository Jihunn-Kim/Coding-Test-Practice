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

	// set ��� �迭�� ����Ͽ� �ٸ� �� ��ǥ�� ������ ã�� �ٸ� ����� Ǯ��
	// (x,y) -> point[x+10000] �� y���Ұ� �ִ�
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
		int x1, y1, x2, y2; // ������ �� ��ǥ
		int x3, y3, x4, y4; // ���õ� �� ��ǥ�� ���� ���Ǿ� ���� ��ǥ
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