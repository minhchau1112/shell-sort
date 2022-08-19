#include<iostream>
using namespace std;

// 0  1  2  3  4  5  6  7  8 9 10 11 12 13
// 17 45 23 89 91 43 65 77 6 8 1 9 33 21
// 6.
// 17 45 6  8 1 9 21 77 23 89 91 43 33 65
// 5.
void ShellSort(int* a, int n) {
	int cnt = 0;
	int temp = n;
	while (temp > 1) {
		temp /= 2;
		cnt++;
	}
	temp = n;
	int* h = new int[cnt];
	for (int i = 0; i < cnt; i++) {
		temp = temp / 2;
		h[i] = temp;
	}
	for (int j = 0; j < cnt; j++) {
		int len = h[j];
		for (int k = len; k <= n - 1; k++) {
			int x = a[k];
			int z = k - len;
			while (z >= 0 && a[z] > x) {
				a[z + len] = a[z];
				z -= len;
			}
			a[z + len] = x;
		}
	}
	delete[] h;
}
int main() {
	int n;
	cout << "Enter the number of elements : ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
	ShellSort(a, n);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	delete[] a;
	return 0;
}