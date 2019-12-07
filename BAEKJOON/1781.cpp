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

int n;
pair<int, int> input[200001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input[i].first >> input[i].second;
	}
	sort(input, input + n);

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i) {
		int deadline = input[i].first;
		pq.push(input[i].second);

		// deadline 보다 더 많은 문제를 풀었다면 컵라면을 제일 적게 주는 문제를 포기
		while (deadline < pq.size())
			pq.pop();
	}

	int ans = 0;
	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}