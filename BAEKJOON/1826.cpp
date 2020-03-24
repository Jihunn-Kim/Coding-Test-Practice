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

	sort(station.begin(), station.end()); // �Է��� �Ÿ� ���������� �ƴѰ�?
	int ans = 0;
	int now = P;
	priority_queue<int> max_heap;
	for (int a, b, i = 0; i < N; ++i) {
		int dis = station[i].first;
		int fuel = station[i].second;
		if (now >= dis) {	// ���� ����� �� �� ������ �ĺ�
			max_heap.push(fuel);
		}
		else {
			while (now < dis) {	// ������ �ĺ��� �� �ִ� ������� ��
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