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

/* ������ �޸� ���� ���
	MAX_V = 3200 ??? �����ؼ� 9999999 ���϶�?
	void back(int cur, int cc) {
		if (cur < MAX_V && !chk[cur]) // prime �ٷ� üũ ����
			res.insert(cur);
		else if (cur >= MAX_V) { // prime üũ �ؾ���
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

	// �����佺�׳׽��� ü
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
			pool[s[i] - '0']++; // ����� �� �ִ� ���� ����
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
		map<int, bool> visited; // �ߺ� ����
		for (int idx = 1; idx <= number.size(); idx++) { // ���� 1 ~ size ����
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