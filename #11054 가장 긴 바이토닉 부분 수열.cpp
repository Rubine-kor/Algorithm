#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int inc[1001];
int decr[1001];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		inc[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && inc[i] < inc[j] + 1) {
				inc[i] = inc[j] + 1;
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		decr[i] = 1;
		for (int j = n; j >= i; j--) {
			if (arr[j] < arr[i] && decr[i] < decr[j] + 1) {
				decr[i] = decr[j] + 1;
			}
		}
	}

	int len = 0;
	for (int i = 1; i <= n; i++) {
		len = max(len, inc[i] + decr[i] - 1);
	}
	cout << len;
}