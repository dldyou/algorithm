#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s1, s2;
vector<int> pi;
vector<int> result;

void get_pi(string s) {
	int len = s.size();
	int k = 0;
	pi.resize(len, 0);

	for (int i = 1; i < len; i++) {
		while ((k > 0) && (s[i] != s[k])) k = pi[k - 1];
		if (s[i] == s[k]) pi[i] = ++k;
	}
}

void kmp(void) {
	int len1 = s1.size();
	int len2 = s2.size();
	int k = 0;

	for (int i = 0; i < len1; i++) {
		while ((k > 0) && (s1[i] != s2[k])) k = pi[k - 1];
		if (s1[i] == s2[k]) {
			if (k == (len2 - 1)) {
				result.emplace_back(i - len2 + 1);
				k = pi[k];
			}
			else k++;
		}
	}
}
int main(void) {
	//fast io
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s1);
	getline(cin, s2);

	get_pi(s2);
	kmp();

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] + 1 << '\n';
	return 0;
}
