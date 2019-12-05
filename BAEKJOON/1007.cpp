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

int t, n;
long long pointX[21];
long long pointY[21];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(7);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> pointX[i] >> pointY[i];
		}

		long long ans = LLONG_MAX;
		vector<int> mask(n);						// AB + CD = (B - A) + (D - C), + 가 될 n / 2 좌표 선택
		fill(mask.begin() + n / 2, mask.end(), 1); // 0 0 0 ... 1 1 1 시작
		do {
			long long tmpX = 0;
			long long tmpY = 0;
			for (int i = 0; i < n; i++) {
				if (mask[i]) {
					tmpX += pointX[i];
					tmpY += pointY[i];
				}
				else {
					tmpX -= pointX[i];
					tmpY -= pointY[i];
				}
			}
			ans = min(ans, tmpX * tmpX + tmpY * tmpY);
		} while (next_permutation(mask.begin(), mask.end())); /// 1 1 1 ... 0 0 0 종료
		cout << sqrt(ans) << '\n';
	}
	return 0;
}