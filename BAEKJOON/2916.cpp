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

int n, k;
int arr[11];
bool check[361];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	queue<int> myQue;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		myQue.push(arr[i]);
		check[arr[i]] = true;
	}

	while (!myQue.empty()) {
		int now = myQue.front();
		//cout << now << ' ';
		myQue.pop();

		for (int i = 0; i < n; ++i) {
			int next = (now + arr[i]) % 360;
			if (check[next])
				continue;

			myQue.push(next);
			check[next] = true;
		}

		for (int i = 0; i < n; ++i) {
			int next = (now - arr[i]) % 360;
			if (next < 0 || check[next])
				continue;

			myQue.push(next);
			check[next] = true;
		}
	}

	int temp;
	for (int i = 0; i < k; ++i) {
		cin >> temp;
		if (check[temp])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}