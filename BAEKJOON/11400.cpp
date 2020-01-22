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
코드 - www.crocus.co.kr/1164
단절점, 단절선
*/

vector<int> vc[100001];
int discovered[100001];
vector<pair<int, int> > isCut;
int number, v, e;

int dfs(int here, int parent) {
	discovered[here] = ++number; // DFS 탐색 순서 지정
	int ret = discovered[here];

	for (int i = 0; i < vc[here].size(); i++)
	{
		int next = vc[here][i];

		if (next == parent)
			continue;

		if (discovered[next]) { // 이미 방문 한 점에서 갈 수 있는 제일 빠른 점 
			ret = min(ret, discovered[next]);
			continue;
		}

		int prev = dfs(next, here);

		if (prev > discovered[here]) // 현재 점보다 빠른 점을, 현재 점을 안거치고 갈 수 있음
			isCut.push_back({ min(here, next), max(here, next) });

		ret = min(ret, prev);
	}

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> v >> e;
	for (int from, to, i = 0; i < e; i++) {
		cin >> from >> to;
		vc[from].push_back(to);
		vc[to].push_back(from);
	}

	for (int i = 1; i <= v; i++)
		if (!discovered[i])
			dfs(i, 0);

	sort(isCut.begin(), isCut.end());

	cout << isCut.size() << '\n';
	for (int i = 0; i < isCut.size(); i++)
		cout << isCut[i].first << ' ' << isCut[i].second << '\n';

	return 0;
}