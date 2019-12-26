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

/* ������� ������ ���� �ϴ� ���� ��� Ǯ��
for (int i = 1; i <= 2000000; i++) {
		int cnt = 0;
		for (int j = i; j <= 2000000; j += i) {
			cnt += arr[j];
		}
		if (cnt > 1) ans = max(ans, (ll)cnt * i);
	}
*/

int n;
long long divisor[2000001]; // �б����� ��� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		// ��� ���ϱ�
		for (int j = 1; j * j <= tmp; ++j) {
			if (tmp % j == 0) {
				divisor[j]++;
				
				int other = tmp / j;
				if (other != j)
					divisor[other]++;
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i < 2000001; ++i) {
		if (divisor[i] > 1)
			ans = max(ans, divisor[i] * i);
	}

	cout << ans;
	return 0;
}