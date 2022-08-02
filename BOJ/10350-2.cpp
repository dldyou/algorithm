#include <bits/stdc++.h>
using namespace std;

int n = 0;
int K[10001] = { 0 };
long long ans = 0;
queue<int> q;

void solve(int i) {
	q.pop();
	ans++;
	int l = i - 1 == -1 ? n - 1 : i - 1;
	int r = i + 1 == n ? 0 : i + 1;
	K[l] += K[i];
	K[r] += K[i];
	K[i] = -K[i];
	if (K[l] < 0) q.push(l);
	if (K[r] < 0) q.push(r);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &K[i]);
		if (K[i] < 0) q.push(i);
	}
	while(!q.empty()) {
		while (K[q.front()] >= 0) {
			q.pop();
		}
		solve(q.front());
	}
	printf("%lld\n", ans);
	return 0;
}
