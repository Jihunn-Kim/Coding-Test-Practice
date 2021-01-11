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
#include <sstream>
#include <deque>
#include <numeric>

using namespace std;

int N;
string inputs;
int dp[1000001][2]; // [0] A·Î, [1] B·Î

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> inputs;
	dp[0][0] = (inputs[0] != 'A');
	dp[0][1] = (inputs[0] != 'B');
	for (int i = 1; i < N; ++i) {
		dp[i][0] = min(dp[i - 1][0] + (inputs[i] != 'A'), dp[i - 1][1] + (inputs[i] != 'B') + 1);
		dp[i][1] = min(dp[i - 1][1] + (inputs[i] != 'B'), dp[i - 1][0] + (inputs[i] != 'A') + 1);
	}

	cout << dp[N - 1][0];

	return 0;
}