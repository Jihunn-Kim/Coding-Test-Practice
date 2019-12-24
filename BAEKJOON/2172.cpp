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

int N, L;
int arr[21][21];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dp[21][21][21][21][21]; // dp[x1][y1][x2][y2][L] - (x1, y1) -> (x2, y2) 로 가는 경로 중 길이가 l 인 팰린드롬
// 8방향 dp[xa][ya][xb][yb][L-2] 을 더해줌 if (arr[xa][ya] == arr[xb][yb])
// 참고 - tastyprogramming.tistory.com/11

// L 를 항상 L - 2 에서 가져오므로 l 루프를 2씩 줄이고, 공간도 21 -> 2 (old, new) 로 줄인 빠른 사람의 풀이
// int d[400][400][2];	// d[start][end][2] = number of palindrome paths from 'start' to 'end'
						// d[i][j][0]: old, d[i][j][1]: new

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			dp[i][j][i][j][1] = 1; // 길이 1, 자기자신
		}
	}

	int xa, ya, xb, yb;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 8; ++k) {
				xa = i + dx[k];
				ya = j + dy[k];
				if (xa < 0 || xa >= N || ya < 0 || ya >= N)
					continue;

				if (arr[i][j] == arr[xa][ya])
					dp[i][j][xa][ya][2]++; // 길이 2
			}
		}
	}

	for (int l = 3; l <= L; ++l) {
		// l 길이
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				// (x1, y1)
				for (int i2 = 0; i2 < N; ++i2) {
					for (int j2 = 0; j2 < N; ++j2) {
						// (x2, y2)
						if (arr[i][j] != arr[i2][j2])
							continue;

						for (int k = 0; k < 8; ++k) {
							for (int k2 = 0; k2 < 8; ++k2) {
								xa = i + dx[k];
								ya = j + dy[k];

								xb = i2 + dx[k2];
								yb = j2 + dy[k2];
								if (xa < 0 || xa >= N || ya < 0 || ya >= N || xb < 0 || xb >= N || yb < 0 || yb >= N)
									continue;

								if (arr[xa][ya] == arr[xb][yb])
									dp[i][j][i2][j2][l] += dp[xa][ya][xb][yb][l - 2];
							}
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int i2 = 0; i2 < N; ++i2) {
				for (int j2 = 0; j2 < N; ++j2) {
					ans += dp[i][j][i2][j2][L];
				}
			}
		}
	}

	cout << ans;
	return 0;
}