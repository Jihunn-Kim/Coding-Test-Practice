#include <algorithm>
#include <string>
#include <vector>
#include <queue>

// nlogn? 다른사람 구건모
struct node {
	int h, m, id, idx;
	double s;
};
struct cmp {
	bool operator() (float i, float j) {
		return i > j;
	}
};
std::vector < node > event;
std::priority_queue < float, std::vector < float >, cmp > q;
int solution(std::vector< std::string > lines) {
	int res = 0;
	for (int i = 0; i < lines.size(); ++i) {
		int h, m;
		double s, ss;
		sscanf(lines[i].c_str(), "%*s%d:%d:%lf%lfs", &h, &m, &s, &ss);
		event.push_back({ h, m, 1, i, s - ss });
		event.push_back({ h, m, -1, i, s });
	}
	std::sort(event.begin(), event.end(), [](node i, node j) {
		return i.h == j.h ? i.m == j.m ? i.s == j.s ? i.id > j.id : i.s < j.s : i.m < j.m : i.h < j.h;
	});
	for (int i = 0, f = 0; i < event.size(); ++i) {
		if (event[i].id == -1) { // 끝 점
			q.push(event[i].h * 3600 + event[i].m * 60 + event[i].s);
		}
		else { // 시작 점
			++f;
			for (; !q.empty(); ) { // 시작 점에서 1초 넘게 멀어진 끝점은 삭제
				double t = q.top();
				if (event[i].h * 3600 + event[i].m * 60 + event[i].s - t >= 0.999) {
					--f;
					q.pop();
				}
				else {
					break;
				}
			}
		}
		res = std::max(res, f);
	}
	return res;
}