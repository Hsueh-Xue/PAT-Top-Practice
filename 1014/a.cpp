#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10; 

int n;
int fa[N], cnt[N];
int f[N];
vector<vector<int> > G;

int gao(int rt) {
	int res = 0;
	memset(f, -1, sizeof f);
	queue<int> q;
	f[rt] = 0;
	q.push(rt);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) {
			if (f[v] == -1) {
				f[v] = f[u] + 1;
				res = max(res, f[v]);
				q.push(v);
			}
		}
	}
	return res;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		fa[x] = y;
	}
}

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	G.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		int sze;
		cin >> sze;
		for (int j = 1, u; j <= sze; ++j) {
			cin >> u;
			G[u].push_back(i);
			G[i].push_back(u);
			Union(i, u);
		}
	}
	for (int i = 1; i <= n; ++i) cnt[find(i)]++;
	int res = 0, Max = 0;
	for (int i = 1; i <= n; ++i) {
		if (cnt[i]) res++;
		Max = max(Max, gao(i));
	}
	cout << res << " " << max(Max - 1, 0) << endl;
	return 0;
}
