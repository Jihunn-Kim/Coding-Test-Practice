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

int T, M;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		vector<int> ans;
		cin >> M;
		for (int tmp, i = 0; i < M; ++i) {
			cin >> tmp;
			if (max_heap.size() == min_heap.size())
				max_heap.push(tmp);
			else
				min_heap.push(tmp);
			// 큰놈 다 min heap 쪽으로
			if (!min_heap.empty() && !max_heap.empty() && min_heap.top() < max_heap.top()) {
				int a = max_heap.top(), b = min_heap.top();
				max_heap.pop();
				min_heap.pop();
				max_heap.push(b);
				min_heap.push(a);
			}

			if (i % 2 == 0)
				ans.push_back(max_heap.top());
		}

		cout << ans.size() << '\n';
		int cnt = 0;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
			++cnt;
			if (cnt == 10) {
				cnt = 0;
				cout << '\n';
			}
		}
		cout << '\n';
	}

	return 0;
}