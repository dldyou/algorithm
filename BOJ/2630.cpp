#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n;
int paper[128][128];
int Bcnt, Wcnt;

void solve(int x, int y, int size) {
	if (x < 0 || y < 0 || x + size > n || y + size > n || !size) return;
	bool blue = true, white = true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (paper[i][j] == 1)
				white = false;
			if (paper[i][j] == 0)
				blue = false;
		}
	}

	if (blue) { Bcnt++; return; }
	if (white) { Wcnt++; return; }

	solve(x, y, size / 2);
	solve(x + size / 2, y, size / 2);
	solve(x, y + size / 2, size / 2);
	solve(x + size / 2, y + size / 2, size / 2);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &paper[i][j]);
	solve(0, 0, n);
	printf("%d\n%d", Wcnt, Bcnt);
	return 0;
}
