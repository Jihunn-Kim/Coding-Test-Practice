#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_set>
#include <math.h>

using namespace std;

/* 

*/

int N, M, K;
int arr[41][41];
int sticker[101][11][11][4];
pair<int, int> sticker_size[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int R, C, i = 0; i < K; ++i) {
		cin >> R >> C;
		sticker_size[i].first = R;
		sticker_size[i].second = C;
		for (int r = 0; r < R; ++r) {
			for (int c = 0; c < C; ++c) {
				cin >> sticker[i][r][c][0];
				sticker[i][c][R - r - 1][1] = sticker[i][r][c][0];
				sticker[i][R - r - 1][C - c - 1][2] = sticker[i][r][c][0];
				sticker[i][C - c - 1][r][3] = sticker[i][r][c][0];
			}
		}
	}

	// 스티커 하나 마다
	for (int idx = 0; idx < K; ++idx) {
		int R = sticker_size[idx].first;
		int C = sticker_size[idx].second;
		// 회전 마다
		bool used = false;
		for (int k = 0; k < 4; ++k) {
			if (used)
				break;
			// 노트북 0, 0 ~ N, M 마다 
			for (int i = 0; i < N; ++i) {
				if (used)
					break;
				for (int j = 0; j < M; ++j) {
					int sticker_r = (k & 1) ? C : R;
					int sticker_c = (k & 1) ? R : C;
					if (i + sticker_r > N || j + sticker_c > M)
						continue;
					// 노트북 비어있는지 확인
					bool check = true;
					for (int p = i; p < i + sticker_r; ++p) {
						for (int q = j; q < j + sticker_c; ++q) {
							if (sticker[idx][p - i][q - j][k] == 1 && arr[p][q] == 1) {
								check = false;
								break;
							}
						}
						if (!check)
							break;
					}
					// 붙임
					if (check) {
						for (int p = i; p < i + sticker_r; ++p) {
							for (int q = j; q < j + sticker_c; ++q) {
								if (sticker[idx][p - i][q - j][k] == 1)
									arr[p][q] = sticker[idx][p - i][q - j][k];
							}
						}
						used = true;
						break;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 1)
				++ans;
		}
	}
	cout << ans;
	return 0;
}