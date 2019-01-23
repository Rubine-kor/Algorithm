/*
문제
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
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