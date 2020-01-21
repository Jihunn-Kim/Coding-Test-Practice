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
코드 - gon109.tistory.com/115
*/

const int NUM = 500000 + 1;
int seg[NUM * 4];
int arr[NUM];
int zip[NUM];
int N, M;

int query(int l, int r, int node, int nodeL, int nodeR) {
	if (nodeL > r || nodeR < l) 
		return 0;
	if (l <= nodeL && nodeR <= r) 
		return seg[node];

	int mid = (nodeL + nodeR) / 2;
	return (query(l, r, node * 2, nodeL, mid) + query(l, r, node * 2 + 1, mid + 1, nodeR));
}

void update(int index, int value, int node, int nodeL, int nodeR) {
	if (nodeL <= index && index <= nodeR) {
		if (nodeL == nodeR)
			seg[node] = value;
		else {
			int mid = (nodeL + nodeR) / 2;
			update(index, value, node * 2, nodeL, mid);
			update(index, value, node * 2 + 1, mid + 1, nodeR);
			seg[node] = seg[node * 2] + seg[node * 2 + 1];
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<pair<int, int>> V;
	for (int i = 0; i < N; i++) {
		V.push_back({ arr[i], i }); // 좌표 압축
	}
	sort(V.begin(), V.end(), greater<pair<int, int>>());
	
	for (auto &p : V) {
		zip[p.second] = query(0, p.second, 1, 0, N - 1); // 자기 보다 앞에 있고 큰놈 찾기
		update(p.second, 1, 1, 0, N - 1);
	}

	for (int i = 0; i < N; i++) {
		cout << zip[i] + 1 << "\n";
	}

	return 0;
}