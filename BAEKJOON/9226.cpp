#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstring>
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

string input;
char arr[] = {'a', 'e', 'i', 'o', 'u'};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		cin >> input;
		if (input == "#")
			break;

		int index;
		for (index = 0; index < input.size(); ++index) {
			bool check = false;
			for (int i = 0; i < 5; ++i) {
				if (input[index] == arr[i]) {
					check = true;
					break;
				}
			}
			if (check)
				break;
		}

		cout << input.substr(index) << input.substr(0, index) << "ay\n";
	}
	return 0;
}