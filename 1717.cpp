#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001000];

int find(int x) {
	if (arr[x] == x) return x;
	else return arr[x] = find(arr[x]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u > v) arr[u] = v;
	else if (u < v) arr[v] = u;
}

bool isCon(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return true;
	return false;
}

void init(void) {
	for (int i = 0; i <= n; i++) arr[i] = i;
}
int main(void) {
	scanf("%d %d", &n, &m);
	init();
	for (int i = 0; i < m; i++) {
		int c, u, v;
		scanf("%d %d %d", &c, &u, &v);
		if (c == 0) merge(u, v);
		else if (c == 1)
			if (isCon(u, v))
				printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}
