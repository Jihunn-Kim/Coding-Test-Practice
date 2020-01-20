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

long long tree[500002];
long long arr[500002];
int n, q;

void update(int i, long long diff) {
	while (i <= n) {
		tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	
	for (int x, y, a, b, i = 0; i < q; ++i) {
		cin >> x >> y >> a >> b;
		if (x < y)
			swap(x, y);

		cout << sum(x) - sum(y - 1) << '\n';
		update(a, b - arr[a]);
		arr[a] = b;
	}

	return 0;
}