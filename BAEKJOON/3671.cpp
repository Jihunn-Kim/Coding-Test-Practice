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

/* 빠르고 메모리 적은 사람
	MAX_V = 3200 ??? 제곱해서 9999999 이하라서?
	void back(int cur, int cc) {
		if (cur < MAX_V && !chk[cur]) // prime 바로 체크 범위
			res.insert(cur);
		else if (cur >= MAX_V) { // prime 체크 해야함
			bool can = 1;
			for (int i = 0; i<p.size() && can; i++) {
				if (!(cur%p[i])) can = 0;
			}
			if (can) res.insert(cur);
		}
		if (cc == L)
			return;
		for (int i = 0; i<10; i++) {
			if (pool[i]) {
				pool[i]--;
				back(cur * 10 + i, cc + 1);
				pool[i]++;
			}
		}
	}

	// 에라토스테네스의 체
	chk[0] = chk[1] = 1
	for (i = 2; i<MAX_V; i++) {
		if (chk[i]) continue;
		p.push_back(i);
		for (j = i*i; j<MAX_V; j += i)
			chk[j] = 1;
	}

	while (c--) {
		res.clear(); // set
		memset(pool, 0, sizeof pool);
		scanf("%s", s);
		L = strlen(s);
		for (i = 0; i<L; i++) 
			pool[s[i] - '0']++; // 사용할 수 있는 숫자 세기
		back(0, 0);
		printf("%d\n", res.size());
	}

*/

int c;
const int MAX = 1e7;
bool check[MAX];

void eratosthenes(void) {

	check[0] = check[1] = true;
	for (int i = 2; i*i < MAX; i++) {
		if (!check[i]) {
			for (int j = i * i; j < MAX; j += i) {
				check[j] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c;

	eratosthenes();

	for (int i = 0; i < c; ++i) {
		string input;
		cin >> input;
		
		vector<int> number(input.size());
		for (int j = 0; j < input.size(); ++j) {
			number[j] = input[j] - '0';
		}

		int ans = 0;
		map<int, bool> visited; // 중복 방지
		for (int idx = 1; idx <= number.size(); idx++) { // 길이 1 ~ size 까지
			sort(number.begin(), number.end());

			do {
				string s;
				for (int j = 0; j < idx; j++) {
					s += number[j] + '0';
				}

				int now = stoi(s);

				if (visited.count(now))
					continue;
				visited[now] = true;

				if (!check[now])
					++ans;
			} while (next_permutation(number.begin(), number.end()));
		}
		cout << ans << '\n';
	}

	return 0;
}