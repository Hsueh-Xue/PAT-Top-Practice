#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N], w[N], vis[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	int res = 0, st = 0, ed = 0, l = 1, tmp = 0, len = 0;
	for (int r = 1; r <= n; ++r) {
//		cout << l << " " << r << endl;
		int x = a[r];
		tmp += w[x];
		while (l <= r && vis[x]) {
			tmp -= w[a[l]];
			vis[a[l]]--;
			++l;
		}
		vis[x]++;
		if (r - l + 1 > len || r - l + 1 == len && tmp > res) {
			len = r - l + 1;
			st = l, ed = r, res = tmp;
		}
	}
	cout << res << " " << st - 1 << " " << ed - 1 <<endl;
	return 0;
}
