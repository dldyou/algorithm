#include <bits/stdc++.h>
using namespace std;

int F, node;
int arr[201010];
int ans[201010];

int find(int x) {
	if (arr[x] == x) return x;
	else return arr[x] = find(arr[x]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u != v) {
		if (ans[u] < ans[v]) swap(u, v);
		ans[u] += ans[v];
		ans[v] = 0;
		arr[v] = u;
	}
}
void init() {
	for (int i = 0; i < 201010; i++) {
		arr[i] = i; ans[i] = 1;
	}
	node = 1;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	string u, v;
	cin >> test_case;
	for (int _ = 0; _ < test_case; _++) {
		cin >> F;
		init();
		map<string, int> m;

		for (int i = 0; i < F; i++) {
			cin >> u >> v;
			if (!m.count(u)) m[u] = node++;
			if (!m.count(v)) m[v] = node++;
			merge(m[u], m[v]);

			int U = find(m[u]);
			int V = find(m[v]);
			cout << max(ans[U], ans[V]) << '\n';
		}
	}
	return 0;
}
