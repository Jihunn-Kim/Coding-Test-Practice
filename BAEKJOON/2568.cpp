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

/*
코드 - www.crocus.co.kr/872
LIS 배열 추적 - www.crocus.co.kr/681

빠른 사람
int i = vec.size();
int j = N - 1;
while (i > 0) {
	if (trace[j] == i) {
		used[j] = true;
		--i;
	}
	--j;
}
for (i = 0; i < N; i++) {
	if (!used[i]) {
		std::cout << input[i].s << "\n";
	}
}
*/

int n;
bool visit[500001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	vector<pair<int, int>> arr(n); // index, value
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
		visit[arr[i].first] = true;
	}
	sort(arr.begin(), arr.end());

	vector<int> LIS(1, arr[0].second);
	vector<pair<int, int>> trace(1, { 0, arr[0].first });
	for (int i = 1; i < n; ++i) {
		if (LIS.back() < arr[i].second) {
			trace.push_back({ LIS.size(), arr[i].first });
			LIS.push_back(arr[i].second);
		}
		else {
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i].second) - LIS.begin();
			//cout << *it << ' ';
			trace.push_back({ idx, arr[i].first });
			LIS[idx] = arr[i].second;
		}
	}
	
	cout << n - LIS.size() << '\n';

	int t = LIS.size() - 1;
	stack<int> s;
	// lis 추적 코드
	for (int i = n - 1; i >= 0; i--) {
		if (trace[i].first == t) {
			s.push(trace[i].second);
			t--;
		}
	}

	// 스택에 쌓인 인덱스를 false로 바꿔준다. 
	while (!s.empty()) {
		visit[s.top()] = false;
		s.pop();
	}

	// 정답이 되는 인덱스를 출력
	for (int i = 0; i <= 500000; i++) {
		if (visit[i])
			cout << i << '\n';
	}

	return 0;
}