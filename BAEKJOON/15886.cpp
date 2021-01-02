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

using namespace std;

int N;
string inputs;
int component;
int ans[1001];
bool visit[1001];

int dfs(int now) {
	//cout << now;
	if (now < 0 || now >= inputs.size()) { // �¿� ������ ��
		++component;
		return ans[now] = component;
	}

	if (visit[now] && ans[now] == -1) { // component �Ҵ� �ȵǾ��µ� �¿�� �Դٰ��� ��
		++component;
		return ans[now] = component;
	}

	if (ans[now] != -1)
		return ans[now];

	visit[now] = true;
	if (inputs[now] == 'E') {
		ans[now] = dfs(now + 1);
	}
	else {
		ans[now] = dfs(now - 1);
	}

	return ans[now];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> inputs;

	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < N; ++i) {
		dfs(i);
	}

	cout << component;

	return 0;
}