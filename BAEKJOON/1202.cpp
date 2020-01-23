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
�ڵ� - js1jj2sk3.tistory.com/14
*/

int n, k;
pair<int, int> jewel[300001];
int bag[300001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < k; ++i) {
		cin >> bag[i];
	}

	sort(jewel, jewel + n);
	sort(bag, bag + k); // ���� ū ������ �� ���, ���� ������ ���� �� �ִ°� ���� �� �ִ�?

	long long sum = 0;
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < k; ++i) {
		while (j < n && jewel[j].first <= bag[i]) // ������ ���� �� �ִ� �ĺ��� �� ����
			pq.push(jewel[j++].second);

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;

	return 0;
}