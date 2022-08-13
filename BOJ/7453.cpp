#include<bits/stdc++.h>
using namespace std;

#define ll long long
int arr[4001][4], n;
vector<int> A, B;
ll ans;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < 4; j++) 
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A.emplace_back(arr[i][0] + arr[j][1]);
			B.emplace_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(A.begin(), A.end()); sort(B.begin(), B.end());

	for (int i = 0; i < n * n; i++)
		ans += (upper_bound(B.begin(), B.end(), -A[i]) - lower_bound(B.begin(), B.end(), -A[i]));
	printf("%lld", ans);
	return 0;
}
