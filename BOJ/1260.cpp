#include<bits/stdc++.h>
using namespace std;

#define ll long long

int N, M, V;
int arr[1001][1001];
bool vst[1001];
queue<int> q;

void next() { for (int i = 1; i <= N; i++) vst[i] = 0; printf("\n"); }

void dfs(int v) {
	vst[v] = true;
	printf("%d ", v);
	for (int i = 1; i <= N; i++)
		if (arr[v][i] == 1 && vst[i] == 0)
			dfs(i);
}

void bfs(int v) {
	q.push(v);
	vst[v] = true;
	printf("%d ", v);

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[v][i] == 1 && vst[i] == 0) {
				q.push(i);
				vst[i] = true;
				printf("%d ", i);
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		arr[s][e] = 1;
		arr[e][s] = 1;
	}

	dfs(V);
	next();
	bfs(V);

	return 0;
}
