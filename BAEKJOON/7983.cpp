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
#include <sstream>
#include <deque>
#include <numeric>

using namespace std;

int N;
pair<int, int> arr[1000001];

bool comp(const pair<int, int>& left, const pair<int, int>& right) {
	return left.second > right.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, comp);

	int last_day = arr[0].second - arr[0].first;
	for (int i = 1; i < N; ++i) {
		if (last_day >= arr[i].second) {
			last_day = arr[i].second - arr[i].first;
		}
		else {
			last_day = last_day - arr[i].first;
		}
	}

	cout << last_day;

	return 0;
}