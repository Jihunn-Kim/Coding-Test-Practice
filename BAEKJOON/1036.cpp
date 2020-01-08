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

// blog.naver.com/PostView.nhn?blogId=dsyun96&logNo=221110225393&proxyReferer=https%3A%2F%2Fwww.google.com%2F

int n, k;
int cnt[55][36]; // [i][j], i 자릿수에 j 번째가 나온 수
bool used[36];

inline int chrToint(char c) {
	return c <= '9' ? c - 48 : c - 55;
}

inline char intTochr(int n) {
	return n <= 9 ? n + 48 : n + 55;
}

inline double myPow(int n, int r) {
	double res = 1;
	while (r--) res *= n;
	return res;
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string input;
		cin >> input;
		for (int j = input.size() - 1, pos = 0; j >= 0; --j, ++pos) {
			++cnt[pos][chrToint(input[j])];
		}
	}
	cin >> k;

	// 큰 수에 쓰일 k 개 선택
	while (k--) {
		int idx = -1;
		double val, max = 0;
		for (int i = 0; i < 35; ++i) { // 'z' 검사 안함
			if (used[i])
				continue;

			val = 0;
			for (int j = 0; j < 54; ++j) {
				if (cnt[j][i])
					val += cnt[j][i] * (35 - i) * myPow(36, j); // 'z' 로 바꿨을 때 증가량
			}

			if (max < val) {
				idx = i;
				max = val;
			}
		}

		if (idx >= 0) {
			used[idx] = true;
			for (int i = 0; i < 55; ++i) {
				cnt[i][35] += cnt[i][idx]; // 'z' 로 변환
				cnt[i][idx] = 0;
			}
		}
		else
			break;
	}

	int sum;
	char ans[55]{};
	for (int i = 0; i < 55; ++i) {
		sum = 0;
		for (int j = 0; j < 36; ++j)
			sum += j * cnt[i][j]; // i 자릿수 다 더함

		ans[i + 1] = (ans[i] + sum) / 36;
		ans[i] = intTochr((ans[i] + sum) % 36);
	}

	int flg = 0;
	for (int i = 54; i >= 0; --i) {
		if (ans[i] > '0' || i == 0)
			flg++;

		if (flg)
			putchar(ans[i]);
	}

	return 0;
}