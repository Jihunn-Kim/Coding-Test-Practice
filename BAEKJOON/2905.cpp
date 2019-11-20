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
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int n, x;
int height[1000001];
long long area;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> height[i];
		area += height[i];
	}

	deque<pair<int, int>> dq; //idx, height
	//monotone priority queue

	for (int i = 0; i < x; i++) {
		// 최소값 유지
		while (!dq.empty() && dq.back().second > height[i])
			dq.pop_back();

		dq.push_back({ i, height[i] });
	}

	int tempHeight = dq.front().second; //칠할 높이
	int result = 0;
	int idx = 0; //밑변 범위를 위해

	for (int i = x; i <= n; i++) {

		while (!dq.empty() && dq.back().second > height[i])
			dq.pop_back();

		dq.push_back({ i, height[i] });

		// 높이가 바뀌었음
		// i ~ (idx - 1)까지 이전 높이로 칠해주고 높이 업데이트
		if (tempHeight != dq.front().second) {
			result += (i - idx - 1) / x + 1;
			area -= (long long)(i - idx) * tempHeight;
			idx = i;
			tempHeight = dq.front().second;
		}

		// 붓 너비를 벗어남
		if (dq.front().first <= i - x) {
			int curIdx = dq.front().first;
			dq.pop_front();

			if (tempHeight != dq.front().second) {
				result += (curIdx - idx) / x + 1;
				area -= (long long)(curIdx - idx + 1) * tempHeight;
				idx = curIdx + 1;
				tempHeight = dq.front().second;
			}
		}
	}

	cout << area << '\n';
	cout << result << '\n';
	return 0;
}