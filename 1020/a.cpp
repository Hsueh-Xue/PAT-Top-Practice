#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e6 + 10;

int n;
char str[N];
ll f[N][5];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif
	
//	ios::sync_with_stdio(false);
//	cin.tie(0), cout.tie(0);
	
	scanf("%s", str + 1);
	n = strlen(str + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 2; ++j) {
			if (j >= 1) f[i][j] += f[i - 1][j - 1];
			f[i][j] += f[i - 1][j];
			for (int k = i - 1; j >= (i - k); --k) {
				if (str[i] == str[k]) {
					f[i][j] -= f[k - 1][j - (i - k)];
					break;
				}
			}
		}
	}
	ll res = 0;
	for (int i = 0; i <= 2; ++i) res += f[n][i];
	printf("%lld\n", res);
	return 0;
}
