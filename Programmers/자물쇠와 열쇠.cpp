#include <string>
#include <vector>

using namespace std;

int key_rotate[4][21][21];
int key_size, lock_size, lock_empty;

bool match(int sx, int sy, const vector<vector<int>>& lock) {

	int cnt[4] = { 0, };
	for (int x = 0; x < key_size; ++x) {
		for (int y = 0; y < key_size; ++y) {
			int lock_x = x + sx;
			int lock_y = y + sy;
			if (lock_x < 0 || lock_x >= lock_size || lock_y < 0 || lock_y >= lock_size)
				continue;

			for (int k = 0; k < 4; ++k) {
				if (key_rotate[k][x][y] == 1 && lock[lock_x][lock_y] == 1) // 돌기끼리 안됨
					cnt[k] = -1;
				else if (key_rotate[k][x][y] == 1 && lock[lock_x][lock_y] == 0)
					++cnt[k];
			}
		}
	}

	for (int k = 0; k < 4; ++k) { // 하나의 회전이라도 된다면
		if (cnt[k] == lock_empty)
			return true;
	}
	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	lock_size = lock.size();
	for (int i = 0; i < lock_size; ++i) { // 빈칸 세기
		for (int j = 0; j < lock_size; ++j) {
			if (lock[i][j] == 0)
				++lock_empty;
		}
	}

	key_size = key.size();
	for (int i = 0; i < key_size; ++i) { // 4 회전 입력
		for (int j = 0; j < key_size; ++j) {
			key_rotate[0][i][j] = key[i][j];
			key_rotate[1][j][key_size - 1 - i] = key[i][j];
			key_rotate[2][key_size - 1 - i][key_size - 1 - j] = key[i][j];
			key_rotate[3][key_size - 1 - j][i] = key[i][j];
		}
	}

	for (int i = -key_size + 1; i < key_size + lock_size; ++i) { // 한칸씩 밀어가며 시도
		for (int j = -key_size + 1; j < key_size + lock_size; ++j) {
			if (match(i, j, lock))
				return true;
		}
	}

	return false;
}