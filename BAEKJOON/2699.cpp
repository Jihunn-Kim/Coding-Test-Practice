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

int p, n;

struct Point {
	int x, y;
	double cos = 0;
};
Point point[51];

// ���� AB�� ���� AC�� CW/CCW
int ccw(const Point& A, const Point& B, const Point& C) {
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
// �������� �� ��, �����̹Ƿ� �ڻ���
bool cmp(const Point& p1, const Point& p2) {
	if (abs(p1.cos - p2.cos) > 1e-6)
		return p1.cos > p2.cos;
	else if (p1.y != p2.y)
		return p1.y > p2.y;
	else
		return p1.x < p2.x;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> p;
	while (p--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> point[i].x >> point[i].y;
			point[i].cos = 0;
		}

		sort(point, point + n, cmp);

		//for (int i = 0; i < n; ++i) {
		//	cout << point[i].x << ' ' << point[i].y << ' ' << point[i].cos << ' ';
		//}
		//cout << '\n';

		// ���� �� ���� �ڻ���
		for (int i = 1; i < n; i++) {
			point[i].cos = (point[i].x - point[0].x) / sqrt(
				(point[i].x - point[0].x) * (point[i].x - point[0].x) + 
				(point[i].y - point[0].y) * (point[i].y - point[0].y));
		}

		sort(point + 1, point + n, cmp);
		
		vector<Point> s;
		s.push_back(point[0]);
		s.push_back(point[1]);
		// ó�� 2���� ���� ����

		int next = 2;
		while (next < n) {
			while (s.size() >= 2) {
				// �ð�����̸� ���� ����
				if (ccw(s[s.size() - 2], s[s.size() - 1], point[next]) < 0)
					break;
				s.pop_back();
			}
			// ���� ���� ����
			s.push_back(point[next++]);
		}
		
		cout << s.size() << '\n';
		for (int i = 0; i < s.size(); i++)
			cout << s[i].x << ' ' << s[i].y << '\n';
	}
	
	return 0;
}