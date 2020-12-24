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
빠른 사람
int max = 0;
for(int i = 0; i < N-1; i++){ // i층과 i+1층을 통과할 수 있는 시간을 알아봄
	if(stick[i].second == stick[i+1].second) // 방향이 같으면 언제든 통과할 수 있으니 pass
		continue;
	int tmp = (L - stick[i].first - stick[i+1].first) / 2;
	max = max > tmp ? max : tmp;
}
*/

int N, L;

bool connected(const pair<int, int>& x, const pair<int, int>& y) {
	return (x.first <= y.second && x.second >= y.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	vector<pair<pair<int, int>, int>> bar;
	for (int l, d, i = 0; i < N; ++i) {
		cin >> l >> d;
		if (d == 0) {
			bar.push_back({ {0, l}, 1 });
		}
		else {
			bar.push_back({ {L - l, L}, -1 });
		}
	}

	int floor = 0;
	int ans = 0;
	while (1) {
		if (floor == N - 1)
			break;

		if (connected(bar[floor + 1].first, bar[floor].first)) {
			++floor;
			continue;
		}

		++ans;
		for (int i = floor; i < N; ++i) {
			if (bar[i].second == 1) {
				++bar[i].first.first;
				++bar[i].first.second;
				if (bar[i].first.second == L)
					bar[i].second = -1;
			}
			else {
				--bar[i].first.first;
				--bar[i].first.second;
				if (bar[i].first.first == 0)
					bar[i].second = 1;
			}
		}

	}
	cout << ans;
	return 0;
}