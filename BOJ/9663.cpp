#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, cnt = 0;
int arr[15];
bool isOk(int row) {
	for (int i = 0; i < row; i++)
		if (arr[i] == arr[row] || row - i == abs(arr[row] - arr[i]))
			return 0;
	return 1;
}

void nqueen(int row) {
	if (row == n) {
		cnt++; 
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[row] = i;
		if (isOk(row)) nqueen(row + 1);
	}
}
int main(void) {
	scanf("%d", &n);
	nqueen(0);
	printf("%d", cnt);
	return 0;
}
