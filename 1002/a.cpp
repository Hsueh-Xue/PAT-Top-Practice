#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10, M = 1e6 + 10;

using ll = long long;

struct node {
	int P, L, D;
	
	bool operator < (const node &other) const {
		return D < other.D;
	}
}a[N];

int n;
int f[M];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	int M = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].P >> a[i].L >> a[i].D;
		M = max(M, a[i].D);
	}
	sort(a + 1, a + 1 + n);
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = a[i].D; j >= a[i].L; --j) {
			f[j] = max(f[j], f[j - a[i].L] + a[i].P);
		}
	}
	for (int i = 0; i <= M; ++i) res = max(res, f[i]);
	cout << res <<endl;
	return 0;
} 
