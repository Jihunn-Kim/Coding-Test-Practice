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

/* 빠른 사람
for (int i = 0;i < n;i++) {
	for (int j = 0;j < m;j++) {
		pair<int, int> t;
		t.first = input[i][j];
		t.second = i;
		in.push_back(t);
	}
}
int s = in.size();
sort(in.begin(), in.end());
register int ans = 1e9;
register int j = 0;
int not_0 = 0;
for (int i = 0;i < s;i++) {
	if (i != 0) {
		cnt[in[i-1].second]--;
		if (cnt[in[i-1].second] == 0)not_0--; // 제일 작은거 빼기?
	}
	for (;j < s && not_0 < n;j++) {
		if (cnt[in[j].second] == 0)not_0++; // 그룹 만들기?
		cnt[in[j].second]++;
	}
	if (not_0 == n&& ans > in[j - 1].first - in[i].first) // 최대 - 최소
		ans = in[j - 1].first - in[i].first;
}
*/

typedef pair<int, pair<int, int>> piii;

int n, m;
int arr[1001][1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
		sort(arr[i], arr[i] + m);
	}
	
	int local_max = -1;
	priority_queue<piii, vector<piii>, greater<piii>> pq;
	for (int i = 0; i < n; ++i) {
		if (arr[i][0] > local_max)
			local_max = arr[i][0];
		pq.push({ arr[i][0], {i, 0} });
	}

	int ans = INT_MAX;
	while (1) {
		int val = pq.top().first;
		int row = pq.top().second.first;
		int col = pq.top().second.second;
		pq.pop();

		int diff = local_max - val;
		if (ans > diff)
			ans = diff;

		if (col + 1 >= m) // 한 학급이 끝남
			break;
		int next = arr[row][col + 1]; // 제일 작은 것 증가
		if (next > local_max)
			local_max = next;
		pq.push({ next, {row, col + 1} });
	}

	cout << ans;
	return 0;
}