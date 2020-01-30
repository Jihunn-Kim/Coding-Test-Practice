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

int t, n, m;
const int mod = 1000000007;
long long comb[101][101];
long long dp[101][101]; // i 개로 j 길이 만듦
long long power[101][101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	comb[0][0] = 1;
	for (int i = 1; i < 101; i++) {
		comb[i][0] = 1;
		power[i][0] = 1;
		for (int j = 1; j < 101; j++) {
			power[i][j] = (power[i][j - 1] * i) % mod;
		}
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}
		for (int j = i; j < 101; j++) { // i 의 j 승 - i 보다 적은 수로 j 개를 만드는 경우
			dp[i][j] = power[i][j];
			for (int k = 1; k < i; ++k) {
				dp[i][j] = (dp[i][j] - (comb[i][k] * dp[k][j]) % mod + mod) % mod;
			}
		}
	}

	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		cin >> m >> n;
		cout << '#' << tc << ' ' << dp[m][n] << '\n';
	}

	return 0;
}