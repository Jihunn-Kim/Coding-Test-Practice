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

const int MOD = 1000000007;

// blog.naver.com/PostView.nhn?blogId=kks227&logNo=221383409543&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=postList
/*
어떤 그래프의 인접행렬을 구한 뒤 그 행렬을 k승한 뒤 i행 j열 성분은 정점 i에서 정점 j로 간선 정확히 k개를 거쳐 가는 경로의 개수가 됩니다.

dp[i][j][k] = 정점 i에서 j로 정확히 k개 간선을 거쳐 가는 경로의 개수라고 생각해 보면, dp[i][j][k] = Σ(j') dp[i][j'][k-1]*dp[j'][j][1]이 되는데, 이 결과식이 행렬 곱셈을 통해 구해지는 셈입니다.

이 문제는 행렬을 D승을 한 뒤 1행 1열 성분을 보면 되겠군요. 시간은 O(logD * N^3)입니다.

[출처] 동적 계획법 3(Dynamic Programming 3) (수정: 2019-08-05)|작성자 라이
*/

vector<vector<long long>> matrix_mul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
	int n = a.size();
	vector<vector<long long>> c(n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][k] += a[i][j] * b[j][k];
				c[i][k] %= MOD;
			}
		}
	}
	return c;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	vector<vector<long long>> ans(8, vector<long long>(8, 0));
	vector<vector<long long>> arr(8, vector<long long>(8, 0));

	arr[0][1] = arr[1][0] = 1; // 지도 별 연결
	arr[0][2] = arr[2][0] = 1;
	arr[1][2] = arr[2][1] = 1;
	arr[1][3] = arr[3][1] = 1;
	arr[2][3] = arr[3][2] = 1;
	arr[2][4] = arr[4][2] = 1;
	arr[3][4] = arr[4][3] = 1;
	arr[3][5] = arr[5][3] = 1;
	arr[4][5] = arr[5][4] = 1;
	arr[4][6] = arr[6][4] = 1;
	arr[5][7] = arr[7][5] = 1;
	arr[6][7] = arr[7][6] = 1;

	for (int i = 0; i < 8; i++) { // 단위 행렬
		ans[i][i] = 1;
	}

	int d;
	cin >> d;

	while (d > 0) {
		if (d % 2 == 1) {
			ans = matrix_mul(ans, arr);
		}
		arr = matrix_mul(arr, arr);
		d /= 2;
	}

	cout << ans[0][0];

	return 0;
}