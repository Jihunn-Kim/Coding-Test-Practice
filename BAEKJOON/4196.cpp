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
ƒ⁄µÂ - jaimemin.tistory.com/1279
∫¸∏• ªÁ∂˜ - ¿Ã∫–≈Ωªˆ ªÁøÎ ???
*/

int n, sx, sy, hcnt;
char arr[51][51];
int height[51][51];
bool visit[51][51];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] == 'P') {
				sx = i;
				sy = j;
			}
			else if (arr[i][j] == 'K') {
				++hcnt;
			}
		}
	}

	vector<int> fatigue;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> height[i][j];
			fatigue.push_back(height[i][j]);
		}
	}

	sort(fatigue.begin(), fatigue.end());
	fatigue.erase(unique(fatigue.begin(), fatigue.end()), fatigue.end());

	int ans = 1000001;
	int low = 0, high = 0; // ≈ı ∆˜¿Œ≈Õ

	while (low < fatigue.size()) {
		memset(visit, false, sizeof(visit));

		queue<pair<int, int>> q;
		int piro = height[sx][sy];

		if (piro >= fatigue[low] && piro <= fatigue[high]) {
			visit[sx][sy] = true;
			q.push({ sx, sy });
		}

		int K = 0;
		while (!q.empty()) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int k = 0; k < 8; k++) {
				int nextY = y + dy[k];
				int nextX = x + dx[k];

				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n || visit[nextY][nextX])
				{
					continue;
				}

				int piro = height[nextY][nextX];

				if (piro >= fatigue[low] && piro <= fatigue[high]) {
					visit[nextY][nextX] = true;
					q.push({ nextY, nextX });

					if (arr[nextY][nextX] == 'K') {
						K++;
					}
				}
			}
		}

		if (hcnt == K) { // π¸¿ß ¡º»˚
			ans = min(ans, fatigue[high] - fatigue[low]);
			low++;
		}
		else if (high + 1 < fatigue.size()) { // π¸¿ß ≥–»˚
			high++;
		}
		else {
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}