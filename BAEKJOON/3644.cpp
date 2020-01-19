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
dp
���� �׷��� ��Ī F_n
����Ŭ �׷��� ��Ī L_n
(n, 1) ���� ����ϸ� F_n-2, �ƴϸ� F_n
L_n = F_n-2 + F_n
L_n = L_n-1 + L_n-2
*/

int n;
vector<string> dp(10001);

string add(string a, string b) {

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string c = "";
	int carry = 0;

	while (a.length() < b.length()) {
		a += "0";
	}

	while (b.length() < a.length()) {
		b += "0";
	}

	int len = a.length();
	for (int i = 0; i < len; i++) {
		int temp = (a[i] - '0') + (b[i] - '0') + carry;
		c += (char)(temp % 10 + '0');
		carry = temp / 10;
	}

	if (carry) {
		c += (char)(carry + '0');
	}
	reverse(c.begin(), c.end());

	return c;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	dp[0] = "2";
	dp[1] = "1";
	dp[2] = "3";

	for (int i = 3; i < 10001; i++) {

		dp[i] = add(dp[i - 1], dp[i - 2]);

	}

	int n;
	while (cin >> n) {
		cout << dp[n] << '\n';
	}

	return 0;
}