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
이분 매칭 개념 - www.crocus.co.kr/499
코드 - red-pulse.tistory.com/211
*/

vector<int> arr[101];
int visit[101];
int binaryMatch[101];
int n, m, visitCnt;

bool dfs(int cur) {
	if (visit[cur] == visitCnt)
		return false;

	visit[cur] = visitCnt;

	for (unsigned int i = 0; i < arr[cur].size(); i++) {
		int next = arr[cur][i];
		if (binaryMatch[next] == 0 || dfs(binaryMatch[next])) {
			// next노드가 연결되어 지지 않은 상태거나,
			// 연결되었지만 next가 현재 연결된 노드 이외의 다른 노드로 연결되어도 되는경우.
			binaryMatch[next] = cur;
			return true;
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int a, b, i = 1; i <= m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		visitCnt++;
		if (dfs(i))
			ans++;
	}
	cout << ans;

	return 0;
}