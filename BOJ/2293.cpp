#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, k;
int dp[10101] = { 1, };
int coin[101];

int main(void) {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
	for (int i = 0; i < n; i++) 
		for (int j = coin[i]; j <= k; j++) 
			dp[j] += dp[j - coin[i]];

	printf("%d\n", dp[k]);
	return 0;
}
