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
������ ��α� - SCC
blog.naver.com/PostView.nhn?blogId=kks227&logNo=220802519976&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=7&postListTopCurrentPage=1&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=7
�ٸ��� - �ڻ���� - jason9319.tistory.com/98
���� ���?? 
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
// SN: SCC ����, sn[i]: i�� ���� SCC�� ��ȣ
int V, E, cnt, dfsn[MAX], SN, sn[MAX];
vector<int> adj[MAX];
bool finished[MAX]; // SCC �и��� ���� ������ true
stack<int> S;
vector<vector<int>> SCC;

// �ڽ��� ������� �����ϴ� DFS �Լ�
int DFS(int curr) {
	dfsn[curr] = ++cnt; // dfsn ����
	S.push(curr); // ���ÿ� �ڽ��� push

	// �ڽ��� dfsn, �ڽĵ��� ����� dfsn �� ���� ���� ��ȣ�� result�� ����
	int result = dfsn[curr];
	for (int next : adj[curr]) {
		// ���� �湮���� ���� �̿�
		if (dfsn[next] == 0) result = min(result, DFS(next));
		// �湮�� ������ ���� SCC�� ��������� ���� �̿�
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	// �ڽ�, �ڽ��� �ڼյ��� ���� ������ ���� ���� ������ �ڽ��� ��� SCC ����
	if (result == dfsn[curr]) {
		vector<int> currSCC;
		// ���ÿ��� �ڽ��� ���� ������ pop
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		// ����� ���� ���� ����
		sort(currSCC.begin(), currSCC.end());
		// SCC ����
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
		
		// SCC�� indegree�� ��
		int sOutdegree[MAX] = { 0, };
		for (int i = 1; i <= n; i++)
			// ���� i->j�� ����, i�� j�� �ٸ� SCC�� ���ϸ� j�� ���� SCC�� outdegree++
			for (int j : adj[i])
				if (sn[i] != sn[j]) sOutdegree[sn[j]]++;

		int result = 0;
		for (int i = 0; i < SN; i++)
			if (sOutdegree[i] == 0) result++;
		cout << result << '\n';
	}

	return 0;
}