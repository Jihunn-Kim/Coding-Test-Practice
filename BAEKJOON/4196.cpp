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
라이의 블로그 - SCC
blog.naver.com/PostView.nhn?blogId=kks227&logNo=220802519976&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=7&postListTopCurrentPage=1&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=7
다른거 - 코사라주 - jason9319.tistory.com/98
빠른 사람?? 
void dfs(int i)
{
	if (process[i])
		return;
	process[i] = true;

	for (auto a : direct[i])
	{
		dfs(a);
	}
	nodelist.push_back(i);
}

void dfstrue(int i)
{
	if (process[i])
		return;
	process[i] = true;

	for (auto a : direct[i])
	{
		dfs(a);
	}
}
*/

const int MAX = 100001;
// SN: SCC 개수, sn[i]: i가 속한 SCC의 번호
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>> SCC;

// 자신의 결과값을 리턴하는 DFS 함수
int DFS(int curr) {
	dfsn[curr] = ++cnt; // dfsn 결정
	S.push(curr); // 스택에 자신을 push

	// 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 result에 저장
	int result = dfsn[curr];
	for (int next : adj[curr]) {
		// 아직 방문하지 않은 이웃
		if (dfsn[next] == 0) result = min(result, DFS(next));
		// 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	// 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
	if (result == dfsn[curr]) {
		vector<int> currSCC;
		// 스택에서 자신이 나올 때까지 pop
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		// 출력을 위해 원소 정렬
		sort(currSCC.begin(), currSCC.end());
		// SCC 추출
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, m;
	cin >> t;
	while (t--) { 
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			adj[i].clear();

		for (int x, y, i = 0; i < m; ++i) {
			cin >> x >> y;
			adj[x].push_back(y);
		}

		cnt = SN = 0;
		memset(dfsn, 0, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(finished, 0, sizeof(finished));
		for (int i = 1; i <= n; i++)
			if (dfsn[i] == 0) DFS(i);
		
		// SCC의 indegree를 셈
		int sOutdegree[MAX] = { 0, };
		for (int i = 1; i <= n; i++)
			// 간선 i->j에 대해, i와 j가 다른 SCC에 속하면 j가 속한 SCC의 outdegree++
			for (int j : adj[i])
				if (sn[i] != sn[j]) sOutdegree[sn[j]]++;

		int result = 0;
		for (int i = 0; i < SN; i++)
			if (sOutdegree[i] == 0) result++;
		cout << result << '\n';
	}

	return 0;
}