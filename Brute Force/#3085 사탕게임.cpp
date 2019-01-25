/*
문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
*/

#include<iostream>
#include<algorithm>
using namespace std;

int arr[51][51];
int test[51];
int ans = 0;
int dump;
int n;
int start;

void eq(int x) {
	if (test[x] == start) dump++;
	else {
		ans = max(ans, dump);
		dump = 1;
		start = test[x];
	}
}

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char temp;
			cin >> temp;
			switch (temp) {
			case 'C':
				arr[i][j] = 1;
				break;
			case 'Y':
				arr[i][j] = 2;
				break;
			case 'Z':
				arr[i][j] = 3;
				break;
			case 'P':
				arr[i][j] = 0;
				break;
			}
		}
	}

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a + 1 <= n) {
				start = -1;
				for (int i = 1; i <= n; i++) test[i] = arr[a][i];
				for (int i = 1; i <= n; i++) eq(i);

				start = -1;
				test[b] = arr[a + 1][b];
				for (int i = 1; i <= n; i++) eq(i);

				start = -1;
				for (int i = 1; i <= n; i++) test[i] = arr[a + 1][i];
				test[b] = arr[a][b];
				for (int i = 1; i <= n; i++) eq(i);
			}

			if (b + 1 <= n) {
				start = -1;
				for (int i = 1; i <= n; i++) test[i] = arr[i][b];
				for (int i = 1; i <= n; i++) eq(i);

				start = -1;
				test[a] = arr[a][b + 1];
				for (int i = 1; i <= n; i++) eq(i);

				start = -1;
				for (int i = 1; i <= n; i++) test[i] = arr[i][b + 1];
				test[a] = arr[a][b];
				for (int i = 1; i <= n; i++) eq(i);
			}
		}
	}

	cout << ans;
}