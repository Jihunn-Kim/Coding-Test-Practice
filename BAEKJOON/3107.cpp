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

using namespace std;

string inputs;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> inputs;
	vector<string> splited = split(inputs, ':');
	
	int missing_zero = 8;
	for (int i = 0; i < splited.size(); ++i) {
		if (splited[i] != "")
			missing_zero -= 1;
	}
	
	string ans = "";
	for (int i = 0; i < splited.size(); ++i) {
		if (splited[i] != "") {
			for (int j = 0; j < 4 - splited[i].size(); ++j)
				ans += '0';
			ans += splited[i] + ':';
		}
		else {
			for (int j = 0; j < missing_zero; ++j)
				ans += "0000:";
			while (i + 1 < splited.size() && splited[i + 1] == "")
				i += 1;
		}
	}

	ans.pop_back();
	cout << ans;

	return 0;
}