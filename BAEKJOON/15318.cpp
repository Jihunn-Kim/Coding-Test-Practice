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
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

long long n, arr[300001];
long long dy[300001];
int util[] = { 1, -1 };

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	long long b0 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		b0 += util[i & 1] * (i + 1) * arr[i];
		if (i)
			dy[0] += util[i & 1] * arr[i];
	}

	//cout << dy[0] << ' ';
	for (int i = 1; i < n; ++i) {
		dy[i] = -arr[i] + util[(n - 1) & 1] * arr[(n + i - 1) % n] - dy[i - 1];
		//cout << dy[i] << ' ';
	}

	for (int i = 0; i < n; ++i) {
		cout << b0 << ' ';
		b0 = dy[i] + arr[i] + util[(n - 1) & 1] * n * arr[i] - b0;
	}

	return 0;
}