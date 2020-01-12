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

int n, d;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d;

	long long ans = LLONG_MIN, tmp;
	deque<pair<long long, int>> dq; // value, index // 범위 내 가장 큰 수 저장
	dq.push_back({ 0, 0 }); // 처음 에러 방지
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;

		while (!dq.empty()) {
			if (i - dq.front().second > d)
				dq.pop_front();
			else
				break;
		}

		tmp = max(tmp, tmp + dq.front().first);

		while (!dq.empty()) {
			if (dq.back().first <= tmp)
				dq.pop_back();
			else
				break;
		}

		dq.push_back({ tmp, i });

		ans = max(ans, tmp);
	}

	cout << ans;
	return 0;
}