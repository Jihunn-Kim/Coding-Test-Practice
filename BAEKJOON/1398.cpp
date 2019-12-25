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

// 설명 - blanik00.github.io/boj/1398/
// 1, 10, 25
// 100, 1000, 2500 ... 아래 동전 개수에 영향을 못미침, 100 단위로 끊기
// dp[i] - i 를 만들기 위한 최소 동전 개수

// 입력값을 1, 10, 25 ... 빼가며 재귀 호출한 다른 풀이가 있음

int coin[3] = { 1, 10, 25 };
int dp[101];
int t;
long long n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	
	memset(dp, 127, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i < 100; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i - coin[j] >= 0)
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		}
	}

	while (t--) {
		cin >> n;

		int ans = 0;
		while (n) {
			ans += dp[n % 100];
			n /= 100;
		}
		cout << ans << '\n';
	}

	return 0;
}