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

*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int A[6], B[6];
		for (int i = 0; i < 3; ++i) {
			cin >> A[i] >> B[i];
			A[3 + i] = B[i];
			B[3 + i] = A[i];
		}

		int ans = INT_MAX;
		for (int i = 0; i < 6; ++i) {
			for (int j = i + 1; j < 6; ++j) {
				for (int k = j + 1; k < 6; ++k) {
					// 같은 박스
					if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3)
						continue;

					int seq[] = { i, j, k };
					do {
						// 일렬 나열
						int width = A[seq[0]] + A[seq[1]] + A[seq[2]];
						int height = max(B[seq[0]], max(B[seq[1]], B[seq[2]]));
						ans = min(ans, width * height);

						// 하나 위로
						width = max(A[seq[0]] + A[seq[1]], A[seq[2]]);
						height = max(B[seq[0]], B[seq[1]]) + B[seq[2]];
						ans = min(ans, width * height);

					} while (next_permutation(seq, seq + 3));
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}