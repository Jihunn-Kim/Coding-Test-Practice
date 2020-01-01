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

// blog.encrypted.gg/439 - ����
// x = k ������ ��ġ�� ������ �ִ� ����

/* ���� ���

if (h > max_h)
{
	max_h = h;
	max_pos = arr[i].first;
}

for (int i = 0; i < N; i ++)
	if (L[i] <= max_pos && max_pos <= R[i])
		cout << i + 1 << ' ';
*/

int n;
pair<int, int> clique[600001]; // s Ȥ�� e, �ε���

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int s, e, i = 0; i < n; ++i) {
		cin >> s >> e;
		clique[2 * i] = { s, i + 1};
		clique[2 * i + 1] = { e + 1, -(i + 1)}; // ������ ���� ��ġ�°� ����, - �� ���� ����
	}

	int cnt = 0;
	int mx = 0;
	sort(clique, clique + 2 * n);
	int sec = clique[0].first;
	int idx = 0;
	while (idx < 2 * n) {
		while (idx < 2 * n && sec == clique[idx].first) {
			if (clique[idx].second < 0) cnt--; // �����̸� ��ġ�� �� --
			else cnt++;
			idx++;
		}
		if (idx == 2 * n) break;
		if (cnt > mx) mx = cnt;
		sec = clique[idx].first;
	}

	cout << mx << '\n';

	set<int> S;
	cnt = 0;
	idx = 0;
	sec = clique[0].first;
	while (idx < 2 * n) {
		while (idx < 2 * n && sec == clique[idx].first) {
			if (clique[idx].second < 0) {
				cnt--;
				S.erase(-clique[idx].second);
			}
			else {
				cnt++;
				S.insert(clique[idx].second);
			}
			idx++;
		}
		if (cnt == mx) {
			for (auto s : S)
				cout << s << ' ';
			return 0;
		}
		sec = clique[idx].first;
	}

	return 0;
}