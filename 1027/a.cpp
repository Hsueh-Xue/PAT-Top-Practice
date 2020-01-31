#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n;
int a[N];
int f[N][N];

struct BIT {
	int a[N];
	
	void Init() {
		memset(a, 0, sizeof a);
	}
	
	void update(int x, int v) {
		for (; x; x -= x & -x) {
			a[x] += v;
		}		
	}
	
	int query(int x) {
		int res = 0;
		for (; x < N; x += x & -x) {
			res += a[x];
		}
		return res;
	}
}bit;

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >>a[i];
	}
	for (int l = 1; l <= n; ++l) {
		bit.Init();
		int tmp = 0;
		for (int r = l; r <= n; ++r) {
			tmp += bit.query(a[r] + 1);
			f[l][r] = tmp;
			bit.update(a[r], 1);
		}
	}
	int all = f[1][n];
	vector<int> vec;
	for (int l = 1; l <= n; ++l) {
		for (int r = l; r <= n; ++r) {
			int len = r - l + 1;
			int tmp = all - f[l][r] + len * (len - 1) / 2 - f[l][r];
			vec.push_back(tmp);
		}
	}
	for (int i = 0, len = vec.size(); i < len; ++i) {
		cout << vec[i] << " \n"[i == len - 1];
	}
	return 0;
}
