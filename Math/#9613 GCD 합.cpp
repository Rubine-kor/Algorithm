/*
문제
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
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