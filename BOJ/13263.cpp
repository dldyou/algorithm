#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fastio cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define ff first
#define ss second

//convex hull trick 
//특수한 점화식을 가진 dp의 형태에서 사용
//y = ax * b로 그렸을 때 최솟값을 가져오는데, 그 부분들이 볼록한 모양을 이뤄 convex hull trick이라는 이름을 가지게 됨

struct fun {
	ll a, b; // y = ax + b
	double minX; //x >= minX : 앞의 함수와 만나는 x중 최소값 저장
};

vector<fun> v;
int n, a[100001], b[100001];
ll dp[100001];

double cross(const fun& f, const fun& g) {
	//f(x) = ax + b, g(x) = cx + d -> 교점 찾기
	//ax + b = cx + d -> x = (d - b) / (a - c)
	return (g.b - f.b) / (f.a - g.a); //f, g의 교점의 x좌표
}
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);

	fun f;
	int top = 0;
	for (int i = 1; i < n; i++) {
		f = { b[i - 1], dp[i - 1], 0 };
		while (!v.empty()) {
			f.minX = cross(f, v.back());
			if (f.minX < v.back().minX)
				v.pop_back();
			else break;
		}
		v.push_back(f);
		int s = 0, e = v.size() - 1, mid;
		int pos = 0;
		while (s <= e) {
			mid = (s + e) >> 1;
			if (v[mid].minX < a[i]) {
				pos = mid;
				s = mid + 1;
			}
			else e = mid - 1;
		}
		dp[i] = v[pos].a * a[i] + v[pos].b;
	}
	printf("%lld", dp[n - 1]);
	return 0;
}
