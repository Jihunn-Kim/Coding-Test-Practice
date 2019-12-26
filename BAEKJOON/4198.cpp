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

// aerocode.net/268 - 기준으로 LIS, LDS 를 구한다


int n, weight;
int arr[2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> weight;
		arr[i] = weight;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int fix = arr[i];
		
		vector<int> asc, des;
		for (int j = i + 1; j < n; j++)
		{
			int now = arr[j];
			if (fix < now) {
				// now 보다 같거나 큰 곳을 가르킨다
				int idx = lower_bound(asc.begin(), asc.end(), now) - asc.begin();

				if (idx == asc.size())
					asc.push_back(now);
				else
					asc[idx] = now;
			}
			if (fix > now) {
				int idx = lower_bound(des.begin(), des.end(), now, greater<>()) - des.begin();

				if (idx == des.size())
					des.push_back(now);
				else
					des[idx] = now;
			}
		}
		ans = max(ans, int(asc.size() + des.size()) + 1);
	}

	cout << ans;
	return 0;
}