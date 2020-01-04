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

int n;
long long k;
int tree[200001][2]; // 왼쪽 오른쪽

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> tree[i][0] >> tree[i][1];
	}

	cin >> k;

	int ans;
	int now = 1;
	while (true) {
		if (tree[now][0] == -1 && tree[now][1] == -1) {
			ans = now;
			break;
		}
		else if (tree[now][0] == -1) {
			now = tree[now][1];
		}
		else if (tree[now][1] == -1) {
			now = tree[now][0];
		}
		else {
			if (k & 1) { // 홀수면 나누고 왼쪽
				k = (k >> 1) + 1;
				now = tree[now][0];
			}
			else { // 짝수면 나누고 오른쪽
				k = k >> 1;
				now = tree[now][1];
			}
		}
	}

	cout << ans;
	return 0;
}