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
입력 값으로 e /2 만드는 냅색 문제
*/

bool d[200001];
const int inf = 1000000001;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		int n, e;
		cin >> n >> e;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		e = (e + 1) / 2;
		if (e == 0) {
			cout << 0 << '\n';
			continue;
		}

		if (e > 2000 * n) { // 용량 다 바꿔도 안됨
			cout << "FULL" << '\n';
			continue;
		}

		memset(d, false, sizeof(d));
		d[0] = true;

		int ans = inf;
		for (int i = 0; i < n; i++) {
			for (int j = e - 1; j >= 0; j--) {
				if (!d[j]) continue;

				if (j + a[i] < e) {
					d[j + a[i]] = true;
				}
				else {
					ans = min(ans, j + a[i]);
				}
			}
		}

		if (ans == inf) {
			cout << "FULL" << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}

	return 0;
}