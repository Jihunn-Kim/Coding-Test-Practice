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

// �ùķ��̼�

int n, k;
int arr[13][13];
int board[13][13][11];
int board_h[13][13];
struct loc {
	int row, col, dir, h;
};
loc piece[11];
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};

bool pieceMove(int index) {

	int pr = piece[index].row;
	int pc = piece[index].col;
	int ph = piece[index].h;

	int nextRow = pr + dr[piece[index].dir];
	int nextCol = pc + dc[piece[index].dir];
	int blockType;
	if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > n)
		blockType = 2;
	else
		blockType = arr[nextRow][nextCol];

	// ���
	if (blockType == 0) {
		// ������ �ǽ� ���̺��� ������ �̵�
		//cout << ph << ' ' << board_h[pr][pc] << '\n';
		for (int i = ph; i < board_h[pr][pc]; ++i) {
			piece[board[pr][pc][i]].row = nextRow;
			piece[board[pr][pc][i]].col = nextCol;
			piece[board[pr][pc][i]].h = board_h[nextRow][nextCol];
			board[nextRow][nextCol][board_h[nextRow][nextCol]++] = board[pr][pc][i];
		}
		board_h[pr][pc] = ph;
		//cout << nextRow << ' ' << nextCol << ' ' << board_h[nextRow][nextCol] << '\n';
		if (board_h[nextRow][nextCol] >= 4) // �� ����
			return true;
	}
	else if (blockType == 1) { // ������
		// �������� �̵�
		for (int i = board_h[pr][pc] - 1; i >= ph; --i) {
			piece[board[pr][pc][i]].row = nextRow;
			piece[board[pr][pc][i]].col = nextCol;
			piece[board[pr][pc][i]].h = board_h[nextRow][nextCol];
			board[nextRow][nextCol][board_h[nextRow][nextCol]++] = board[pr][pc][i];
		}
		board_h[pr][pc] = ph;
		if (board_h[nextRow][nextCol] >= 4) // �� ����
			return true;
	}
	else { // �Ķ���, ��� ��
		// ���� ��ȯ
		if (piece[index].dir == 1)
			piece[index].dir++;
		else if (piece[index].dir == 2)
			piece[index].dir--;
		else if (piece[index].dir == 3)
			piece[index].dir++;
		else
			piece[index].dir--;

		//cout << index << ' ';
		// ���� ��ȯ �� �Ķ����� ��谡 �ƴ϶�� �̵�
		int nr = pr + dr[piece[index].dir];
		int nc = pc + dc[piece[index].dir];
		if (nr < 1 || nr > n || nc < 1 || nc > n || arr[nr][nc] == 2)
			return false;
		else
			return pieceMove(index);
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= k; ++i) {
		cin >> piece[i].row >> piece[i].col >> piece[i].dir;
		piece[i].h = board_h[piece[i].row][piece[i].col];
		board[piece[i].row][piece[i].col][board_h[piece[i].row][piece[i].col]++] = i;
	}

	int gameCount = 0;
	bool check = false;
	while (gameCount < 1000) {

		for (int i = 1; i <= k; ++i) {
			check = pieceMove(i);
			if (check)
				break;
		}

		++gameCount;
		if (check)
			break;
	}
	if (check)
		cout << gameCount;
	else
		cout << -1;
	return 0;
}