/*
����
����̴� ����� ���� "������ (Bomboni)" ������ ����ߴ�.

���� ó���� N��Nũ�⿡ ������ ä�� ���´�. ������ ���� ��� ���� ���� ���� �ִ�. ����̴� ������ ���� �ٸ� ������ �� ĭ�� ����. �� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�. ����, ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� �� ������ ��� �Դ´�.

������ ä���� ���°� �־����� ��, ����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (3 �� N �� 50)

���� N�� �ٿ��� ���忡 ä���� �ִ� ������ ������ �־�����. �������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y�� �־�����.

������ ���� �ٸ� ������ �� ĭ�� �����ϴ� �Է¸� �־�����.

���
ù° �ٿ� ����̰� ���� �� �ִ� ������ �ִ� ������ ����Ѵ�.
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