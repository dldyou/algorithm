#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll arr[100001];

ll solve(int s, int e) {
	if (s == e) return arr[s];
	int mid = (s + e) / 2;
	ll ret = max(solve(s, mid), solve(mid + 1, e));
	ll lo = mid, hi = mid + 1;
	ll height = min(arr[lo], arr[hi]);
	ret = max(ret, height * 2);

	while (s < lo || hi < e) {
		if (hi < e && (lo == s || arr[lo - 1] < arr[hi + 1])) {
			hi++;
			height = min(height, arr[hi]);
		}
		else {
			lo--;
			height = min(height, arr[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main(void) {
	while (1) {
		scanf("%d", &n);
		if (n <= 0) break;
		for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
		printf("%lld\n", solve(1, n));
	}
	return 0;
}
