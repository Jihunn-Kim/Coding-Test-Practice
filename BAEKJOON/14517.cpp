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

const int MOD = 10007;
char input[1002];
int dp[1001][1001]; // dp[i][j] - 1 ~ i, j ���� �������� ������� �Ӹ���� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> (input + 1);

	int len = strlen(input + 1);
	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j < i; ++j)
			dp[i][j] = dp[i - 1][j]; // ���� �� ��������

		for (int j = i; j <= len; ++j) {
			dp[i][j] = dp[i - 1][j];

			if (input[i] == input[j]) { // ������ ��ġ�ϸ�
				dp[i][j] += 1;
				for (int k = j; k < len; ++k) {
					dp[i][j] += dp[i - 1][k + 1];
				}
			}
			dp[i][j] %= MOD;
		}
	}

	int ans = 0;
	for (int i = 1; i <= len; i++)
		ans += dp[len][i];

	cout << ans % MOD;
	return 0;
}