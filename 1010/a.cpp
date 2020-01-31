#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct BIT {
	int a[N];
	
	void Init() {
		memset(a, 0, sizeof a);
	} 
	
	void update(int x, int v) {
		for (; x < N; x += x & -x) {
			a[x] += v;
		}
	}
	
	int query(int x) {
		int res = 0;
		for (; x; x -= x & -x) {
			res += a[x];
		}
		return res;
	}
}bit;

struct HASH {
	int a[N];
	
	void Init() {
		*a = 0;
	}
	
	void add(int x) {
		a[++*a] = x;
	}
	
	void gao() {
		sort(a + 1, a + 1 + *a);
		*a = unique(a + 1, a + 1 + *a) - a - 1;
	} 
	
	int get(int x) {
		return lower_bound(a + 1, a + 1 + *a, x) - a;
	}
}ha;

int n;
int a[N];
int res[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ha.add(a[i]);
	}
	ha.gao();
	for (int i = n; i >= 1; --i) {
		int x = ha.get(a[i]);
		res[i] = bit.query(x);
		bit.update(x, 1);
	}
	for (int i = 1; i <= n; ++i) {
		cout << res[i] << " \n"[i == n];
	}
	return 0;
} 
