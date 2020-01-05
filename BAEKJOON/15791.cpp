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

/* ��ó - blog.naver.com/PostView.nhn?blogId=rollrat&logNo=221286410829

1 / m! mod �ϱ�

�丣���� ������, �յ�
p�� �Ҽ��̰� a�� p�� ���μ� �� �� a^p === a(mod p) �� �����Ѵ�

a ^ (p - 1) === 1(mod p), a ^ (p - 2) === a ^ -1 (mod p) �� ����

n! / r! * (n - r)! = n! * (r! * (n - r)!) ^ -1 = n! * (r! * (n - r)!) ^ p - 2 (mod p)

*/

#define ll long long
ll mod = 1e9 + 7, n, m;
ll a = 1, b = 1, c = 1;
ll mypow(ll a, ll b) {
	if (!b) return 1;
	if (b & 1) return (a*mypow(a, b - 1) % mod) % mod;
	return mypow((a*a) % mod, b / 2) % mod;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {
		a *= i;
		a %= mod;
	}
	for (ll i = 1; i <= m; i++) {
		b *= i;
		b %= mod;
	}
	for (ll i = 1; i <= n - m; i++) {
		b *= i;
		b %= mod;
	}
	c = mypow(b, mod - 2);
	a *= c;
	a %= mod;
	
	cout << a;

	return 0;
}