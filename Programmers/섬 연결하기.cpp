#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

void uni(int x, int y) {
	parent[x] = y;
}

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

bool cmp(const vector<int>& x, const vector<int>& y) {
	return x[2] < y[2];
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	for (int i = 0; i <= n; ++i) {
		parent[i] = i;
	}

	sort(costs.begin(), costs.end(), cmp);
	for (int i = 0; i < costs.size(); ++i) {
		int from = find(costs[i][0]);
		int to = find(costs[i][1]);

		if (from != to) {
			uni(from, to);
			--n;
			answer += costs[i][2];
		}
		if (n == 1)
			break;
	}
	return answer;
}