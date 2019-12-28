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

/* 빠른 사람 풀이
algospot.com/wiki/read/Manacher's_algorithm

void manacher(const char str[], int lps[], const int strLen) {
	int c = -1; // centerPosition
	int r = -1; // centerRightPosition

	for (int i = 0; i < strLen; ++i) {
		if (r < i)
			lps[i] = 0;
		else
			lps[i] = min(r - i, lps[2 * c - i]);

		while ((i - lps[i] - 1 >= 0) && (i + lps[i] + 1 < strLen)
				&& (str[i - lps[i] - 1] == str[i + lps[i] + 1]))
			++lps[i];

		if (i + lps[i] > r) {
			r = i + lps[i];
			c = i;
		}
	}

}

for (int i = 0; i < strLen; ++i)
	derivedStr[2 * i] = str[i];

N = 2 * strLen - 1;
manacher(derivedStr, lps, N);

*/

bool check[2002][2002]; // check[s][e], s ~ e 팰린드롬 인지 확인
int dp[2002]; // dp[i], i 에서의 최소 분할 수
string input;

bool func(int s, int e) {
	if (s == e)
		return true;
	else if (s + 1 == e) {
		if (input[s] == input[e])
			return true;
		else
			return false;
	}

	if (check[s][e])
		return check[s][e];

	if (input[s] != input[e])
		return check[s][e] = false;
	else
		return check[s][e] = func(s + 1, e - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> input;

	int n = input.size();

	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = -1;
		for (int j = 1; j <= i; ++j) {
			if (func(j - 1, i - 1)) { // 팰린드롬 이면
				if (dp[i] == -1 || dp[i] > dp[j - 1] + 1) { // j 에서 짜르고 + 1
					dp[i] = dp[j - 1] + 1;
				}
			}
		}
	}

	cout << dp[n];
	return 0;
}