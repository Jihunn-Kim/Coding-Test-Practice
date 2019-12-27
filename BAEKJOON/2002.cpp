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

/* 배열로 푼 사람
carIn[i] = i + 1;

if (!strcmp(temp, data[j]))
{
	carOut[i] = j + 1;
	break;
}

if (carOut[i] > carOut[j])
{	
	ans++;
	break;
}
*/

int n;
unordered_map<string, int> inCar;
stack<string> outCar;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	string tmp;
	for (int i = 1; i <= n; ++i) {
		cin >> tmp;
		inCar.insert({ tmp, i });
	}

	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		outCar.push(tmp);
	}

	int ans = 0;
	int target = outCar.size();
	while (!outCar.empty()) {
		tmp = outCar.top();
		outCar.pop();
		int num = inCar[tmp];

		// 이전에 나간 차보다 빨리나가면 추월
		if (target >= num) {
			target = min((int)outCar.size(), num);
		}
		else {
			++ans;
		}
	}

	cout << ans;
	return 0;
}