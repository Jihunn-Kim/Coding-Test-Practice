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
ƒ⁄µÂ - www.crocus.co.kr/782
∆Ê¿®∆Æ∏Æ
*/

int tree[500002];
int input[500002];
int n;

void update(int i)
{
	while (i <= n)
	{
		tree[i] += 1;
		i += (i & -i);
	}
}

long long sum(int i)
{
	long long ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	// ∆Ê¿®∆Æ∏Æ ¿Œµ¶Ω∫ 1 ∫Œ≈Õ
	for (int val, i = 1; i <= n; i++) {
		cin >> val;
		input[i] = val;
	}

	unordered_map<int, int> B;
	for (int val, i = 1; i <= n; i++)
	{
		cin >> val;
		B[val] = i;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int valA = input[i];
		int idxB = B[valA];

		ans += sum(n) - sum(idxB);

		update(idxB);
	}

	cout << ans;

	return 0;
}