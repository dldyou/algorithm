#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> v;
ll arr[20002];
ll n, m;
int main(void) {
	scanf("%lld", &n);
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		sum += arr[i];
		arr[i + n] = arr[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll temp = 0;
		for (int j = i; j < i + n; j++) {
			temp += arr[j];
			if (temp < 0) {
				ll ttemp = -temp;
				ans += (ttemp - 1) / sum + 1;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
