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

int N, M, T;
int circle[52][52];
int tmp[52][52];
bool die[52][52];
bool die_tmp[52][52];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> circle[i][j];
		}
	}

	for (int x, d, k, input = 0; input < T; ++input) {
		cin >> x >> d >> k;
		// 회전
		for (int idx = x; idx <= N; idx += x) {
			if (d == 0) {
				for (int j = 1; j <= M; ++j) {
					int next = j + k; 
					if (next > M)
						next = next - M;
					tmp[idx][next] = circle[idx][j];
					die_tmp[idx][next] = die[idx][j];
				}
				for (int j = 1; j <= M; ++j) {
					circle[idx][j] = tmp[idx][j];
					die[idx][j] = die_tmp[idx][j];
				}
			}
			else {
				for (int j = 1; j <= M; ++j) {
					int next = j - k;
					if (next < 1)
						next = M + next;
					tmp[idx][next] = circle[idx][j];
					die_tmp[idx][next] = die[idx][j];
				}
				for (int j = 1; j <= M; ++j) {
					circle[idx][j] = tmp[idx][j];
					die[idx][j] = die_tmp[idx][j];
				}
			}
		}

		double cnt = 0, sum = 0;
		bool check = true;
		vector<pair<int, int>> die_xy;
		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= M; ++j) {
				if (die[i][j])
					continue;

				++cnt;
				sum += circle[i][j];
				int target = circle[i][j];
				// 상하
				if (i - 1 > 0 && !die[i - 1][j] && circle[i - 1][j] == target) {
					die_xy.push_back({ i - 1, j });
					die_xy.push_back({ i, j });
					check = false;
				}
				if (i + 1 <= N && !die[i + 1][j] && circle[i + 1][j] == target) {
					die_xy.push_back({ i + 1, j });
					die_xy.push_back({ i, j });
					check = false;
				}
				// 좌
				if (j - 1 == 0 && !die[i][M] && circle[i][M] == target) {
					die_xy.push_back({ i, M });
					die_xy.push_back({ i, j });
					check = false;
				}
				if (j - 1 > 0 && !die[i][j - 1] && circle[i][j - 1] == target) {
					die_xy.push_back({ i, j - 1});
					die_xy.push_back({ i, j });
					check = false;
				}
				// 우
				if (j + 1 > M && !die[i][0] && circle[i][0] == target) {
					die_xy.push_back({ i, 0 });
					die_xy.push_back({ i, j });
					check = false;
				}
				if (j + 1 <= M && !die[i][j + 1] && circle[i][j + 1] == target) {
					die_xy.push_back({ i, j + 1});
					die_xy.push_back({ i, j });
					check = false;
				}
			}
		}
		// 죽은 곳 처리
		for (pair<int, int> xy : die_xy) {
			die[xy.first][xy.second] = true;
			circle[xy.first][xy.second] = -1;
		}

		if (check) {
			double mean = sum / cnt;
			for (int i = 1; i <= N; ++i) {
				for (int j = 1; j <= M; ++j) {
					if (!die[i][j]) {
						if (circle[i][j] < mean) {
							circle[i][j] += 1;
						}
						else if (circle[i][j] > mean) {
							circle[i][j] -= 1;
						}
					}
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (!die[i][j])
				ans += circle[i][j];
		}
	}
	cout << ans;
	return 0;
}