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

int tree[100001];
int input[100001];
int t, n;

void update(int i) {
	while (i <= n) {
		tree[i] += 1;
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

	cin >> t;
	while (t--) {
		cin >> n;
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++) {
			cin >> input[i];
		}

		map<int, int> match;
		for (int val, i = 1; i <= n; i++) {
			cin >> val;
			match[val] = i;
		}

		long long ans = 0;
		for (int tmp, idx, i = 1; i <= n; i++) {
			tmp = input[i];
			idx = match[tmp];

			ans += sum(n) - sum(idx); // 내 앞에 연결된 수를 더함

			update(idx);
		}

		cout << ans << '\n';
	}
	return 0;
}