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

int L, C;
char inputs[16];
char answer[16];
int is_vowel[] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };

void solve(int index, int length, int vowel, int consonant) {
	if (length == L) {
		if (vowel > 0 && consonant > 1)
			cout << answer << '\n';
		return;
	}

	if (index == C)
		return;

	for (int i = index; i < C; ++i) {
		answer[length] = inputs[i];
		int carry = is_vowel[int(inputs[i] - 'a')];
		solve(i + 1, length + 1, vowel + carry, consonant + (carry == 0 ? 1 : 0));
	}

	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; ++i) {
		cin >> inputs[i];
	}
	sort(inputs, inputs + C);

	solve(0, 0, 0, 0);
	
	return 0;
}