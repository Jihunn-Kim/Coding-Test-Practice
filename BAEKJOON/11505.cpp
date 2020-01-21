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

long long tree[1 << 21];
long long arr[1 << 21];
int n, m, k;
const int mod = 1000000007;

void init(int node, int start, int end) { 
	if (start == end) { 
		tree[node] = arr[start]; 
	} 
	else { 
		int half = (start + end) / 2; 
		init(node * 2, start, half); 
		init(node * 2 + 1, half + 1, end); 
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod; 
	} 
}

long long query(int node, int start, int end, int i, int j) { 
	if (j < start || end < i)
		return 1; 
	if (i <= start && end <= j) 
		return tree[node]; 

	int half = (start + end) / 2; 
	return (query(node * 2, start, half, i, j) * query(node * 2 + 1, half + 1, end, i, j)) % mod;
}

void update(int node, int start, int end, int index, int newValue) { 
	if (start <= index && index <= end) { 
		if (start == end) { 
			tree[node] = newValue; 
		} 
		else { 
			int half = (start + end) / 2; 
			update(node * 2, start, half, index, newValue); 
			update(node * 2 + 1, half + 1, end, index, newValue); 
			tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % mod; 
		} 
	} 
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	init(1, 0, n - 1);

	for (int a, b, c, i = 0; i < m + k; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 0, n - 1, b - 1, c);
			arr[b - 1] = c;
		}
		else {
			cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}

	return 0;
}