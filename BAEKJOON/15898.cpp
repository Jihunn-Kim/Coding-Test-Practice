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


int n, ans;
int effect[10][4][4][4];
char element[10][4][4][4];
int dr[4] = {0, 0, 1, 1};
int dc[4] = {0, 1, 1, 0};

void bomb(int p, int q, int r) {
	// p, q, r 순서대로 
	// p, q, r 별 4 회전
	for (int pp = 0; pp < 4; ++pp) {
		for (int qq = 0; qq < 4; ++qq) {
			for (int rr = 0; rr < 4; ++rr) {
				// p, q, r 별 가마 위치 4 곳
				for (int ppp = 0; ppp < 4; ++ppp) {
					for (int qqq = 0; qqq < 4; ++qqq) {
						for (int rrr = 0; rrr < 4; ++rrr) {
							// 더하기 시작
							int matN[5][5] = { 0, };
							char matC[5][5] = { 0, };
							// p 더하기
							for (int i = 0; i < 4; ++i) {
								for (int j = 0; j < 4; ++j) {

									matN[i + dr[ppp]][j + dc[ppp]] += effect[p][i][j][pp];
									if (matN[i + dr[ppp]][j + dc[ppp]] > 9)
										matN[i + dr[ppp]][j + dc[ppp]] = 9;
									else if (matN[i + dr[ppp]][j + dc[ppp]] < 0)
										matN[i + dr[ppp]][j + dc[ppp]] = 0;

									if (element[p][i][j][pp] != 'W')
										matC[i + dr[ppp]][j + dc[ppp]] = element[p][i][j][pp];
								}
							}
							// q 더하기
							for (int i = 0; i < 4; ++i) {
								for (int j = 0; j < 4; ++j) {

									matN[i + dr[qqq]][j + dc[qqq]] += effect[q][i][j][qq];
									if (matN[i + dr[qqq]][j + dc[qqq]] > 9)
										matN[i + dr[qqq]][j + dc[qqq]] = 9;
									else if (matN[i + dr[qqq]][j + dc[qqq]] < 0)
										matN[i + dr[qqq]][j + dc[qqq]] = 0;

									if (element[q][i][j][qq] != 'W')
										matC[i + dr[qqq]][j + dc[qqq]] = element[q][i][j][qq];
								}
							}
							// r 더하기
							for (int i = 0; i < 4; ++i) {
								for (int j = 0; j < 4; ++j) {

									matN[i + dr[rrr]][j + dc[rrr]] += effect[r][i][j][rr];
									if (matN[i + dr[rrr]][j + dc[rrr]] > 9)
										matN[i + dr[rrr]][j + dc[rrr]] = 9;
									else if (matN[i + dr[rrr]][j + dc[rrr]] < 0)
										matN[i + dr[rrr]][j + dc[rrr]] = 0;

									if (element[r][i][j][rr] != 'W')
										matC[i + dr[rrr]][j + dc[rrr]] = element[r][i][j][rr];
								}
							}

							// 품질 계산
							int R = 0, B = 0, G = 0, Y = 0;
							for (int i = 0; i < 5; ++i) {
								for (int j = 0; j < 5; ++j) {
									if (matC[i][j] == 'R')
										R += matN[i][j];
									else if (matC[i][j] == 'B')
										B += matN[i][j];
									else if (matC[i][j] == 'G')
										G += matN[i][j];
									else if (matC[i][j] == 'Y')
										Y += matN[i][j];
								}
							}
							int local = 7 * R + 5 * B + 3 * G + 2 * Y;
							ans = max(ans, local);

						}
					}
				}

			}
		}
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				cin >> effect[i][r][c][0];
				effect[i][3 - c][r][3] = effect[i][3 - r][3 - c][2] = effect[i][c][3 - r][1] = effect[i][r][c][0];
			}
		}

		for (int r = 0; r < 4; ++r) {
			for (int c = 0; c < 4; ++c) {
				cin >> element[i][r][c][0];
				element[i][3 - c][r][3] = element[i][3 - r][3 - c][2] = element[i][c][3 - r][1] = element[i][r][c][0];
			}
		}
		//cin >> arr[0][0][0] >> arr[0][3][1] >> arr[3][3][2] >> arr[3][0][3];
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (i == j || i == k || j == k)
					continue;

				bomb(i, j, k);
			}
		}
	}

	cout << ans;
	return 0;
}