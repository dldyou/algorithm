#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, k, w;
int build[1001];
int chk[1001];
int dp[1001];
vector<int> v[1001];
queue<int> q;

void init(void) {
	memset(dp, 0, sizeof dp);
	memset(chk, 0, sizeof chk);
	for (int i = 0; i <= 1000; i++)
		v[i].erase(v[i].begin(), v[i].end());
}

void input(void) {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &build[i]);
	int s, e;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &s, &e);
		v[s].emplace_back(e);
		chk[e]++;
	}
	scanf("%d", &w);
}

void solve(void) {
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			q.push(i);
			dp[i] = build[i];
		}
	}
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 0; i < v[temp].size(); i++) {
			int next = v[temp][i];
			dp[next] = max(dp[next], dp[temp] + build[next]);
			chk[next]--;
			if (!chk[v[temp][i]]) q.push(next);
		}
	}
}
int main(void) {
	int test_case;
	scanf("%d", &test_case);
	for (int _ = 0; _ < test_case; _++) {
		init();
		input();
		solve();
		printf("%d\n", dp[w]);
	}
	return 0;
}
