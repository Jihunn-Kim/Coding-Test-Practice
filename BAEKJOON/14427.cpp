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

/* segment tree 변형? 빠른 사람 풀이
void update(int idx, int v) {
	tree[idx].X = v;

	idx >>= 1;
	while (idx) {
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
		idx >>= 1;
	}
}
*/

int n, m;
set<pair<int, int>> input; // 값, 인덱스
int arr[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	int tmp, idx, val;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		arr[i] = tmp;
		input.insert({ tmp, i });
	}

	cin >> m;
	set<pair<int, int>>::iterator it;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		if (tmp == 2) {
			it = input.begin();
			cout << (*it).second << '\n';
		}
		else {
			cin >> idx >> val;
			input.erase({ arr[idx], idx });
			arr[idx] = val;
			input.insert({ arr[idx], idx });
		}
	}

	return 0;
}