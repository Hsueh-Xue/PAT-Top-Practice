#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 10;

struct BIT {
	ll a[N];

	void Init() {
		memset(a, 0, sizeof a);
	}
	
	void update(int x, int v) {
		for (; x; x -= x & -x) {
			a[x] += v;
		}
	}
	
	ll query(int x) {
		ll res = 0;
		for (; x < N; x += x & -x) {
			res += a[x];
		}
		return res;
	}
}bit[2];

int n;
int a[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	bit[0].Init(), bit[1].Init();
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		res += bit[1].query(a[i]);
		bit[1].update(a[i], bit[0].query(a[i]));
		bit[0].update(a[i], 1);
	}
	cout << res << endl;
	return 0;
} 
