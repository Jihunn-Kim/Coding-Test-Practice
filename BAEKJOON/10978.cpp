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

// 출처 - blog.naver.com/PostView.nhn?blogId=pasdfq&logNo=221321784908&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView

long long dp[21]; // i 명일 때 수
int t, n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;

	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i < 21; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}