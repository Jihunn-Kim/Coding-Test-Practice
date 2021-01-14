#pragma warning (disable: 4996)
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
#include <sstream>
#include <deque>
#include <numeric>
#include <typeinfo>

using namespace std;

int N;
int converted_inputs[501];
int temp_inputs[501];
map<int, int> people_order;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string inputs;
	for (int i = 0; i < N * 5; ++i) {
		cin >> inputs;
		converted_inputs[i] = (int)inputs[0] * 1000;
	
		int value = 0;
		for (int k = 2; k < inputs.size(); ++k)
			value = value * 10 + (int)(inputs[k] - '0');

		converted_inputs[i] += value;
		temp_inputs[i] = converted_inputs[i];

	}

	sort(temp_inputs, temp_inputs + (N * 5));
	for (int i = 0; i < N * 5; ++i) {
		people_order[temp_inputs[i]] = i;
	}

	stack<int> stck;
	int now_target = 0;
	for (int i = 0; i < N * 5; ++i) {
		if (people_order[converted_inputs[i]] != now_target) {
			while (!stck.empty() && people_order[stck.top()] == now_target) {
				stck.pop();
				now_target += 1;
			}
			stck.push(converted_inputs[i]);
		}
		else {
			now_target += 1;
		}
	}

	while (!stck.empty() && people_order[stck.top()] == now_target) {
		stck.pop();
		now_target += 1;
	}

	if (now_target == N * 5)
		cout << "GOOD";
	else
		cout << "BAD";

	return 0;
}