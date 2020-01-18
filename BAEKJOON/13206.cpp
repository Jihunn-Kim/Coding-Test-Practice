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
코드 - github.com/kks227/BOJ/blob/master/13200/13206.cpp
LCM % mod - stackoverflow.com/questions/24574299/lcm-of-n-numbers-modulo-1000000007
그냥 lcm 하면 mod 보다 커지므로, 소인수 분해 후 mod 적용?

보기 쉽고 mod 덜 쓴 빠른 사람
void preproc() {
	for (int i = 2; i <= 1000; ++i) {
		if (notPrime[i]) {
			continue;
		}
		primes.push_back(i);
		for (int j = i + i; j <= 1000; j += i) {
			notPrime[j] = true;
		}
	}
}

void proc() {
	memset(maxexp, 0, sizeof(maxexp));
	memset(chk, 0, sizeof(chk));

	n = FIO::readUnsigned();
	for (int i = 0; i < n; ++i) {
		int v = FIO::readUnsigned();
		if (chk[v]) {
			continue;
		}
		chk[v] = true;

		for (int j = 0; j < primes.size() && v >= primes[j] * primes[j]; ++j) {
			int p = primes[j];
			if (v % p == 0) {
				int cnt = 0;
				while (v % p == 0) {
					++cnt;
					v /= p;
				}
				maxexp[p] = max(maxexp[p], cnt);
			}
		}
		if (v > 1) {
			maxexp[v] = max(maxexp[v], 1);
		}
	}

	int ans = 1;
	for (int p : primes) {
		for (int j = 0; j < maxexp[p]; ++j) {
			ans = (long long)ans * p % 1000000007;
		}
	}
	printf("%d\n", ans);
}
*/

int n, t;
bool check[1001];
const int MOD = 1000000007;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 에라토네스의 체
	vector<int> prime(1, 2);
	for (int i = 3; i < 1001; i += 2) {
		if (check[i]) continue;
		prime.push_back(i);
		for (int j = i * i; j < 1001; j += i * 2)
			check[j] = true;
	}
	int P = prime.size();

	cin >> t;
	while (t--) {
		int N, result = 1;
		vector<int> cnt(P, 0), factor(P, 1);
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int A;
			cin >> A;
			for (int j = 0; j < P && A > 1; ++j) {
				int tcnt = 0, temp = 1;
				while (A%prime[j] == 0) {
					++tcnt;
					temp = 1LL * temp * prime[j] % MOD;
					A /= prime[j];
				}
				if (cnt[j] < tcnt) { // 소수 최고 지승 저장
					cnt[j] = tcnt;
					factor[j] = temp;
				}
			}
		}
		for (int i = 0; i < P; ++i)
			result = 1LL * result * factor[i] % MOD;
		cout << result << '\n';
	}
	return 0;
}