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

/* ���� Ǯ��, ���� ���� ���ĺ��� ���� �� �Ҵ�

long long int sum = 0;
int num = 0; // �Ҵ��� ��
int ind;
while(num!=10){

	long long int min = 99999999999999;
	for(int i=0;i<='J'-'A';i++){		  // ���� ���� ã��
		if(min > arr[i] && check[i]==0){
			if(num == 0){
				if(not_zero[i]==0){
					min = arr[i];
					ind = i;
				}
			}
			else{
				min = arr[i];
				ind = i;
			}
		}
	}
	check[ind] =1;
	sum += arr[ind] * num;
	num++;
	}

*/

int n;
long long sum[10];
bool impossible[10];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string tmp;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		impossible[tmp[0] - 'A'] = true; // �� ���ڸ� 0 ����
		for (long long j = tmp.size() - 1, k = 1; j >= 0; --j, k *= 10)
			sum[tmp[j] - 'A'] += k;
	}
	
	int p[10]; // ���� �Ҵ� �迭
	long long ans = 0;
	for (int i = 0; i < 10; i++)
		p[i] = i;

	do {
		if (impossible[p[0]]) continue;
		long long temp = 0;
		for (int i = 1; i < 10; i++) temp += sum[p[i]] * i;
		ans = max(ans, temp);
	} while (next_permutation(p, p + 10));
	
	cout << ans;

	return 0;
}