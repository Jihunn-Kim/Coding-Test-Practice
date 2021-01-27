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
#include <tuple>

using namespace std;

string inputs;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> inputs;

	stack<int> stck;
	bool error = false;
	for (int i = 0; i < inputs.size(); ++i) {
		if (inputs[i] == '(') {
			stck.push(-2);
		}
		else if (inputs[i] == '[') {
			stck.push(-3);
		}
		else if (inputs[i] == ')') {
			int temp = 0;
			while (!stck.empty() && stck.top() > 0) temp += stck.top(), stck.pop(); // ( 나올때 까지

			if (stck.empty() || stck.top() != - 2) { // ( 없음
				error = true;
				break;
			}
			stck.pop();

			if (temp == 0)
				temp = 1;
			stck.push(temp * 2);
		}
		else {
			int temp = 0;
			while (!stck.empty() && stck.top() > 0) temp += stck.top(), stck.pop();

			if (stck.empty() || stck.top() != -3) {
				error = true;
				break;
			}
			stck.pop();

			if (temp == 0)
				temp = 1;
			stck.push(temp * 3);
		}
	}

	int temp = 0;
	while (!stck.empty()) {
		if (stck.top() < 0) {
			error = true;
			break;
		}
		else {
			temp += stck.top();
			stck.pop();
		}
	}

	if (error)
		cout << 0;
	else
		cout << temp;

	return 0;
}