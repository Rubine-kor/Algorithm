#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int d[1001];
int v[1001];

void go(int x) {
	if (x == 0) return;
	go(v[x]);
	cout << arr[x] << ' ';
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int len = 0;
	int q;
	for (int i = 1; i <= n; i++) {
		if (len < d[i]) q = i;
		len = max(len, d[i]);
	}
	cout << len << endl;
	go(q);
}