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

using namespace std;

// 코드 및 설명(그리디?) - chttps://beginthread.tistory.com/58
const int LEN = 1e6 + 1;
int n, m, ans[LEN], a[LEN];

bool go() {
	set<int> s;
	for (int i = 0; i < m; ++i) {
		int t; cin >> t;
		if (t == 0) { // 
			s.insert(i);
			ans[i] = 0;
		}
		else { // 이전에 물 먹었던 날 이후로 가능하고 가장 앞선 날을 찾음
			set<int>::iterator it = s.upper_bound(a[t]);
			if (it == s.end()) {
				while (++i < m) {
					cin >> t;
				}
				return false;
			}
			ans[*it] = t;
			a[t] = i;
			s.erase(it);
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int z;
	cin >> z;
	while (z--) {
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			a[i] = ans[i] = -1;
		}

		if (go()) {
			cout << "YES\n";
			for (int i = 0; i < m; ++i) {
				if (ans[i] != -1)
					cout << ans[i] << ' ';
			}
			cout << '\n';
		}
		else 
			cout << "NO\n";
	}

	return 0;
}