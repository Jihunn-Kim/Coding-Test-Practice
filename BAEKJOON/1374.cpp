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
pair<long long, long long> inputs[100001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int tresh, i = 0; i < N; ++i) {
		cin >> tresh >> inputs[i].first >> inputs[i].second;
	}
	sort(inputs, inputs + N);

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	pq.push(0);
	for (int i = 0; i < N; ++i) {
		int pq_top = pq.top();
		if (inputs[i].first < pq_top) {
			pq.push(inputs[i].second);
		}
		else {
			pq.pop();
			pq.push(inputs[i].second);
		}
	}

	cout << pq.size();

	return 0;
}