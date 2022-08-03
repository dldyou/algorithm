#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, arr[101][101], ans[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vst[101][101];

bool isIn(int x, int y) {
	if (x >= 1 && x <= m && y >= 1 && y <= n) return true;
	return false;
}

void solve(int x, int y, int cnt) {
	vst[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];

			if (isIn(tx, ty)) {
				if (!vst[ty][tx] && arr[ty][tx] == 1) {
					vst[ty][tx] = 1;
					ans[ty][tx] = ans[y][x] + 1;
					q.push({ tx, ty });
				}
			}
		}
	}
}
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	solve(1, 1, 1);
	printf("%d", ans[n][m] + 1);
	return 0;
}
