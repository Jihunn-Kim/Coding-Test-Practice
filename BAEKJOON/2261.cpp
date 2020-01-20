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
jason9319.tistory.com/306 - 라인 스위핑?
casterian.net/archives/92 - 분할 정복
*/

struct Point {
	int x, y;
};

struct Comp {
	bool comp_in_x;
	Comp(bool b) : comp_in_x(b) {}
	bool operator()(Point &p, Point &q) {
		return (this->comp_in_x ? p.x < q.x : p.y < q.y);
	}
};

int n;
vector<Point> input;

int dist(const Point& p, const Point& q) {
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}

int closest_pair(int start, int size) {
	if (size == 2)
		return dist(input[start + 0], input[start + 1]);
	if (size == 3)
		return min(dist(input[start + 0], input[start + 1]), 
				min(dist(input[start + 0], input[start + 2]), dist(input[start + 1], input[start + 2])));

	int yline = (input[start + size / 2 - 1].x + input[start + size / 2].x) / 2;
	int d = min(closest_pair(start, size / 2), closest_pair(start + size / 2, size - size / 2));

	vector<Point> mid;

	for (int i = 0; i < size; i++) {
		int t = yline - input[start + i].x;
		if (t*t < d)
			mid.push_back(input[start + i]);
	}

	sort(mid.begin(), mid.end(), Comp(false));

	int mid_sz = mid.size();
	for (int i = 0; i < mid_sz - 1; i++)
		for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y)*(mid[j].y - mid[i].y) < d; j++)
			d = min(d, dist(mid[i], mid[j]));

	return d;
}

bool cmp(const Point &a, const Point &b) {
	if (a.y == b.y)return a.x < b.x;
	return a.y < b.y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	input.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> input[i].x >> input[i].y;
	}

	sort(input.begin(), input.end(), Comp(true));

	cout << closest_pair(0, n);

	return 0;
}