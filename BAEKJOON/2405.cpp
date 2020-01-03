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
long long arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	// 끝점 고정 ( (a + b + c) / 3 - b ) * 3 = a - 2 * b + c
	long long ans = 0;
	for (int i = 0; i < n - 2; i++) {
		ans = max(ans, abs(arr[i] - arr[i + 1] * 2 + arr[n - 1])); // c 고정
		ans = max(ans, abs(arr[0] - arr[i + 1] * 2 + arr[i + 2])); // a 고정
	}

	cout << ans;
	return 0;
}