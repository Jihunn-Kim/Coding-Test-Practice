#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

/* 다른 사람들
int N;
unordered_set<int> cache[10];
unordered_set<int> solve(int n) { // n 개로 만들 수 있는 수들
	if (!cache[n].empty()) return cache[n];
	int num = 0;
	for (int i = 0; i < n; i++) num = 10 * num + N;
	unordered_set<int> res;
	res.insert(num);
	for (int i = 1; i < n; i++) { // i, j 번째 조합으로 n 번째를 생성
		int j = n - i;
		auto s1 = solve(i);
		auto s2 = solve(j);
		for (int n1 : s1) {
			for (int n2 : s2) {
				res.insert(n1 + n2);
				res.insert(n1 - n2);
				res.insert(n1 * n2);
				if (n2 != 0) res.insert(n1 / n2);
			}
		}
	}
	return cache[n] = res;
}

int solution(int _N, int number) {
	N = _N;
	for (int i = 1; i <= 8; i++) {
		solve(i);
		if (cache[i].find(number) != cache[i].end()) return i;
	}
	return -1;
}

------------------------------------

int N, number;
int answer = 1e9;

void dfs(int num, int count) {
	if (count > 8)
		return;
	if (count >= answer)
		return;
	if ((count < answer) && (num == number)) {
		answer = count;
		return;
	}

	int temp = 0;
	for (int i = 0; i < 7; i++) {
		temp = temp * 10 + N;
		dfs(temp + num, count + i + 1);
		dfs(temp * num, count + i + 1);
		if (num != 0) {
			dfs(temp / num, count + i + 1);
		}
		dfs(num / temp, count + i + 1);
		dfs(temp + num, count + i + 1);
		dfs(temp - num, count + i + 1);
		dfs(num - temp, count + i + 1);
	}
}
int solution(int N_, int number_) {
	N = N_;
	number = number_;

	dfs(0, 0);
	if (answer > 8)
		return -1;
	else
		return answer;
}
*/

int solution(int N, int number) {
	unordered_map<int, int> check;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	for (int tmp = 0, i = 1; i <= 8; ++i) { // N, NN, NNN ...
		tmp = tmp * 10 + N;
		check[tmp] = i;
		que.push({ i, tmp });
	}
	while (!que.empty()) {
		int cnt = que.top().first;
		int now = que.top().second;
		que.pop();

		if (now == number)
			break;
		// 최대 범위 8 혹은 다른 곳에서 더 적은 수로 가능
		if (check.count(now) != 0 && (check[now] >= 8 || check[now] < cnt))
			continue;

		for (int tmp = 0, i = 1; i <= 8; ++i) { // N, NN, NNN ...
			tmp = tmp * 10 + N;

			if (check.count(now - tmp) == 0 || check[now - tmp] > cnt + i) {
				check[now - tmp] = cnt + i;
				que.push({ cnt + i, now - tmp });
			}
			if (check.count(tmp - now) == 0 || check[tmp - now] > cnt + i) {
				check[tmp - now] = cnt + i;
				que.push({ cnt + i, tmp - now });
			}
			if (check.count(now + tmp) == 0 || check[now + tmp] > cnt + i) {
				check[now + tmp] = cnt + i;
				que.push({ cnt + i, now + tmp });
			}

			if (check.count(now / tmp) == 0 || check[now / tmp] > cnt + i) {
				check[now / tmp] = cnt + i;
				que.push({ cnt + i, now / tmp });
			}
			if (now != 0 && (check.count(tmp / now) == 0 || check[tmp / now] > cnt + i)) {
				check[tmp / now] = cnt + i;
				que.push({ cnt + i, tmp / now });
			}
			if (check.count(now * tmp) == 0 || check[now * tmp] > cnt + i) {
				check[now * tmp] = cnt + i;
				que.push({ cnt + i, now * tmp });
			}
		}
	}

	int answer;
	if (check.count(number) == 0 || check[number] > 8)
		answer = -1;
	else
		answer = check[number];

	return answer;
}