/*
����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.
*/

#include <iostream>
using namespace std;

long long mgcd(int n1, int n2) {
	if (n2 == 0) { return n1; }
	else {
		return mgcd(n2, n1%n2);
	}
}

int main() {
	long long test, i, j, k, n, gcd;
	
	cin >> test;
	for (i = 0; i < test; i++) {
		int arr[101] = { 0 };
		gcd = 0;
		cin >> n;
		for (j = 0; j < n; j++) {
			cin >> arr[j];
		}
		for (j = 0; j < n; j++) {
			for (k = j+1; k < n; k++) {
				gcd += mgcd(arr[j], arr[k]);
			}
		}
		cout << gcd << "\n";
	}
	return 0;
}