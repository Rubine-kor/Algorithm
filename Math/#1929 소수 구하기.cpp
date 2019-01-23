/*
����
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1 �� M �� N �� 1,000,000)

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/

#include<iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	bool a[1000001];

	cin >> n >> m;

	for (int i = n; i <= m; i++) a[i] = true;
	a[1] = false;

	for (int i = 2; i*i <= m; i++) {
		for (int j = 2 * i; j <= m; j += i) a[j] = false;
	}
	for (int i = n; i <= m; i++) {
		if (a[i] == true) cout << i << "\n";
	}
}