#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e3 + 10, p = 1e9 + 7;

int n, m;
char s[N];
ll pre[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> s;
	n = strlen(s) + 1;
	m = min(101, n);
	vector<vector<ll> > f(m, vector<ll> (n, 1));
	for (int i = 1; i < m; ++i) {
		memset(pre, 0, sizeof pre);
		pre[s[i - 1]] = 1;
		for (int j = i + 1; j < n; ++j) {
			f[i][j] = (f[i][j - 1] + f[i - 1][j - 1] - pre[s[j - 1]] + p) % p;
			pre[s[j - 1]] = f[i - 1][j - 1];
		}
	}
	ll res = 0;
	for (int i = 1; i < m; ++i) {
		res = (res + f[i][n - 1]) % p;
	}
	cout << res << endl;
	return 0;
} 
