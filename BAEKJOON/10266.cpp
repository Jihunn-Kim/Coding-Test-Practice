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

// 환형 문자열 A를 탐색, A 2개를 이어붙인 문자열에서 B를 탐색
// kmp 설명 - bowbowbow.tistory.com/6

const int N = 360000;
int n;
bool arr[720002];
bool brr[360001];
int pi[360001];

void getpi() {
	int j = 0;
	for (int i = 1; i < N; i++) {
		while (j > 0 && brr[i] != brr[j])
			j = pi[j - 1];
		if (brr[i] == brr[j])
			pi[i] = ++j;
	}
}

void kmp() {
	bool check = false;
	int j = 0;
	for (int i = 0; i < 2 * N; i++) {
		while (j > 0 && arr[i] != brr[j])
			j = pi[j - 1];
		if (arr[i] == brr[j]) {
			if (j == N - 1) {
				check = true;
				break;
			}
			else
				j++;
		}
	}
	if (check)
		cout << "possible";
	else
		cout << "impossible";
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp] = 1;
		arr[tmp + N] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		brr[tmp] = 1;
	}
	getpi();
	kmp();

	return 0;
}