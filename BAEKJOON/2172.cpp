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
int dp[21][21][21][21][21]; // dp[x1][y1][x2][y2][L] - (x1, y1) -> (x2, y2) �� ���� ��� �� ���̰� l �� �Ӹ����
// 8���� dp[xa][ya][xb][yb][L-2] �� ������ if (arr[xa][ya] == arr[xb][yb])
// ���� - tastyprogramming.tistory.com/11

// L �� �׻� L - 2 ���� �������Ƿ� l ������ 2�� ���̰�, ������ 21 -> 2 (old, new) �� ���� ���� ����� Ǯ��
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
			dp[i][j][i][j][1] = 1; // ���� 1, �ڱ��ڽ�
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
					dp[i][j][xa][ya][2]++; // ���� 2
			}
		}
	}

	for (int l = 3; l <= L; ++l) {
		// l ����
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