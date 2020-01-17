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
최소공통조상 개념
blog.naver.com/PostView.nhn?blogId=kks227&logNo=220820773477&categoryNo=299&parentCategoryNo=0&viewDate=&currentPage=6&postListTopCurrentPage=&from=postList&userTopListOpen=true&userTopListCount=5&userTopListManageOpen=false&userTopListCurrentPage=6
*/

int n;
char input[4002];
int apple[4002];
int x, y, target_i, target_j, apple_cnt;
int parent[2001][14];
int depth[2001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> input + 1;
	cin >> x >> y;

	int now = 0; // make tree
	for (int i = 1; i <= 2 * n; ++i) {
		if (input[i] == '0') {
			apple_cnt++;
			parent[apple_cnt][0] = now;
			depth[apple_cnt] = depth[now] + 1;
			apple[i] = apple_cnt;
			now = apple_cnt;
		}
		else {
			apple[i] = now;
			now = parent[now][0];
		}
	}

	// LCA
	for (int j = 0; j < 13; j++)
		for (int i = 1; i <= n; i++)
				parent[i][j + 1] = parent[parent[i][j]][j];

	x = apple[x];
	y = apple[y];
	if (depth[x] < depth[y])
		swap(x, y);

	int diff = depth[x] - depth[y];
	for (int j = 0; diff; j++) {
		if (diff & 1)
			x = parent[x][j];
		diff >>= 1;
	}

	if (x != y) {
		for (int j = 13; j >= 0; j--) {
			if (parent[x][j] != parent[y][j]) {
				x = parent[x][j];
				y = parent[y][j];
			}
		}
		x = parent[x][0];
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (input[i] == '0' && apple[i] == x)
			target_i = i;
		else if (input[i] == '1' && apple[i] == x)
			target_j = i;
	}

	cout << target_i << ' ' << target_j;
	return 0;
}