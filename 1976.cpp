#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[202];
int route[1001];

int find(int x) {
	if (arr[x] == x) return x;
	else return arr[x] = find(arr[x]);
}

void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u > v) arr[u] = v;
	else if (u < v) arr[v] = u;
}

void init(void) {
	for (int i = 0; i <= n; i++) arr[i] = i;
}

int main(void) {
	scanf("%d %d", &n, &m);
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int con;
			scanf("%d", &con);
			if (con == 1) merge(i, j);
		}
	}
	int routeNum;
	for (int i = 0; i < m; i++) {
		scanf("%d", &route[i]);
		if (i == 0) routeNum = arr[route[i]];
		else if (arr[route[i]] != routeNum) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
