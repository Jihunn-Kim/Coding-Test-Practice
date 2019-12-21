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

int a, b, c, d;
set<pair<int, int>> visit;
// bfs 로 다 시도, 0ms 걸리시는 분들 풀이를 이해하지 못함.
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;

	queue<pair<pair<int, int>, int>> water;
	water.push({ { 0, 0 }, 0 });
	visit.insert({ 0, 0 });

	int ans = -1;
	while (!water.empty()) {
		int waterA = water.front().first.first;
		int waterB = water.front().first.second;
		int work = water.front().second;
		water.pop();

		if (waterA == c && waterB == d) {
			ans = work;
			break;
		}

		int next_waterA;
		int next_waterB;
		// fill A
		next_waterA = a;
		next_waterB = waterB;
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}

		// fill B
		next_waterA = waterA;
		next_waterB = b;
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}

		// empty A
		next_waterA = 0;
		next_waterB = waterB;
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}

		// empty B
		next_waterA = waterA;
		next_waterB = 0;
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}

		// move from A to B
		if (waterA + waterB > b) {
			next_waterA = waterA + waterB - b;
			next_waterB = b;
		}
		else {
			next_waterA = 0;
			next_waterB = waterA + waterB;
		}
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}

		// move from B to A
		if (waterA + waterB > a) {
			next_waterA = a;
			next_waterB = waterA + waterB - a;
		}
		else {
			next_waterA = waterA + waterB;
			next_waterB = 0;
		}
		if (visit.find({ next_waterA, next_waterB }) == visit.end()) {
			water.push({ { next_waterA, next_waterB }, work + 1 });
			visit.insert({ next_waterA, next_waterB });
		}
	}
	cout << ans;
	return 0;
}