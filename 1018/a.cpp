#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 10, p = 1e9 + 7;

int n;
char s[N];
ll fac[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	scanf("%s", s + 1);
	n = strlen(s + 1);
	reverse(s + 1, s + 1 + n); 
	fac[0] = 1ll;
	for (int i = 1; i <= n; ++i) {
		fac[i] = (fac[i - 1] * 10 + 1) % p; 
	}
	ll res = 0, tmp = 0;
	for (int i = 1; i <= n; ++i) {
		int x = s[i] - '0';
		tmp = (tmp + x * fac[i - 1]) % p;
		if (x) {
			res = (res + tmp) % p;
		}
	}
	cout << res <<endl;
	return 0;
}

/*
reverse then do it
*/
