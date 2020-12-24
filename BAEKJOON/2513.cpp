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

int N, K, S;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> S;

	vector<pair<int, int>> input(N);
	for (int i = 0; i < N; ++i) {
		cin >> input[i].first >> input[i].second;
	}

	sort(input.begin(), input.end());
	int ans = 0;
	int dis = 0, person = 0, idx = 0;
	while (idx < N && input[idx].first < S) {
		if (dis == 0) { // 왕복 했으면
			dis = S - input[idx].first;
		}

		if (person + input[idx].second < K) { // 태울만큼 태우고
			person += input[idx].second;
			++idx;
		}
		else if (person + input[idx].second == K) { // 찼으면 데려다 주고
			person = 0;
			ans += dis * 2;
			dis = 0;
			++idx;
		}
		else {	// 넘치면 다시 오고
			input[idx].second -= (K - person);
			person = 0;
			ans += dis * 2;
			dis = 0;
		}
	}
	ans += dis * 2;

	dis = 0, person = 0, idx = N - 1;
	while (idx >= 0 && input[idx].first > S) {
		if (dis == 0) {
			dis = input[idx].first - S;
		}

		if (person + input[idx].second < K) {
			person += input[idx].second;
			--idx;
		}
		else if (person + input[idx].second == K) {
			person = 0;
			ans += dis * 2;
			dis = 0;
			--idx;
		}
		else {
			input[idx].second -= (K - person);
			person = 0;
			ans += dis * 2;
			dis = 0;
		}
	}
	ans += dis * 2;

	cout << ans;

	return 0;
}