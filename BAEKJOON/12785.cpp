#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <math.h>

using namespace std;

/*
다른 사람
a[1][0]=1;
for (i=1;i<=x;i++)
	for (j=1;j<=y;j++)
		a[i][j]=(a[i-1][j]+a[i][j-1])%1000007;

for (i=x;i<=n;i++)
	for (j=y;j<=m;j++)
		a[i][j]=(a[i-1][j]+a[i][j-1])%1000007;
*/

int w, h, x, y;
int arr[201][201];
const int mod = 1000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> w >> h >> x >> y;
	// 토스트 가게로
	for (int i = 0; i < h; i++) {
		arr[i][0] = 1;
	}
	for (int i = 1; i < w; i++) {
		arr[0][i] = 1;
	}
	for (int i = 1; i < y; i++) {
		for (int j = 1; j < x; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % mod;
		}
	}

	// 학교로
	for (int i = y; i < h; i++) {
		arr[i][x - 1] = arr[y - 1][x - 1];
	}
	for (int i = x; i < w; i++) {
		arr[y - 1][i] = arr[y - 1][x - 1];
	}
	for (int i = y; i < h; i++) {
		for (int j = x; j < w; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % mod;
		}
	}

	cout << arr[h - 1][w - 1];

	return 0;
}