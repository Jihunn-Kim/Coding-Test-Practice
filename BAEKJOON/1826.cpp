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

int N, L, P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<pair<int, int>> station(N);
	for (int a, b, i = 0; i < N; ++i) {
		cin >> a >> b;
		station[i] = { a, b };
	}
	cin >> L >> P;

	sort(station.begin(), station.end()); // 입력이 거리 오름차순이 아닌가?
	int ans = 0;
	int now = P;
	priority_queue<int> max_heap;
	for (int a, b, i = 0; i < N; ++i) {
		int dis = station[i].first;
		int fuel = station[i].second;
		if (now >= dis) {	// 현재 연료로 갈 수 있으면 후보
			max_heap.push(fuel);
		}
		else {
			while (now < dis) {	// 못가면 후보지 중 최대 연료부터 씀
				if (max_heap.size() == 0)
					break;

				++ans;
				now += max_heap.top();
				max_heap.pop();
				if (now >= dis) {
					max_heap.push(fuel);
				}
			}
		}
	}

	while (now < L) {
		if (max_heap.size() == 0)
			break;

		++ans;
		now += max_heap.top();
		max_heap.pop();
	}
	
	if (now < L)
		cout << -1;
	else
		cout << ans;

	return 0;
}