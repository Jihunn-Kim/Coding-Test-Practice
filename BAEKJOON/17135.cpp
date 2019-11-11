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
#include <climits>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int n, m, d, tmp;
//int dx[] = {0, 1, 0, -1};
//int dy[] = {1, 0, -1, 0};
list<pair<int, int>> input;
list<pair<int, int>> enemy;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> tmp;
			if (tmp == 1) {
				input.push_back({ i, j });
			}
		}
	}

	int ans = 0;
	for (int p = 0; p < m; ++p) {
		for (int q = p + 1; q < m; ++q) {
			for (int r = q + 1; r < m; ++r) {

				int archer[] = { p, q, r };
				int count = 0;
				for (list<pair<int, int>>::iterator it = input.begin(); it != input.end(); ++it)
					enemy.push_back({ it->first, it->second });

				while (!enemy.empty()) {
					int map[16][16] = { 0, };
					for (list<pair<int, int>>::iterator it = enemy.begin(); it != enemy.end(); ++it)
						map[it->first][it->second] = 1;

					vector<pair<int, int>> death;
					for (int k = 0; k < 3; ++k) {
						for (int range = 0; range < d; ++range) {
							bool enemyFind = false;
							for (int target = -range; target <= range; ++target) {
								int targetC = archer[k] + target;
								int targetR = n - 1 - ((target < 0) ? (range + target) : (range - target));
								if (targetR < 0 || targetR >= n || targetC < 0 || targetC >= m || map[targetR][targetC] == 0)
									continue;

								death.push_back({ targetR, targetC });
								//cout << targetR << ' ' << targetC << '\n';
								enemyFind = true;
								break;
							}
							if (enemyFind)
								break;
						}
					}

					for (list<pair<int, int>>::iterator it = enemy.begin(); it != enemy.end();) {
						bool isDel = false;
						for (int vs = 0; vs < death.size(); ++vs) {
							if (death[vs].first == it->first && death[vs].second == it->second) {
								//cout << "dd : ";
								//cout << it->first << ' ' << it->second << '\n';
								it = enemy.erase(it);
								++count;
								isDel = true;
								break;
							}
						}
						if (isDel)
							continue;

						if (it->first == n - 1) {
							it = enemy.erase(it);
							continue;
						}

						it->first += 1;
						++it;
					}

				}

				if (ans < count)
					ans = count;
			}
		}
	}
	cout << ans;
	return 0;
}