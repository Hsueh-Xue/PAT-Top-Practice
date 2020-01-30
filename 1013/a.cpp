#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Edge {
	int u, v, w;
	
	Edge() {}
	
	Edge(int u, int v, int w): u(u), v(v), w(w) {}

	void input() {
		cin >> u >> v >> w;
	}
	
	bool operator < (const Edge &other) const {
		return w < other.w;
	}
};

int n, m, c;
int fa[N], sze[N], Max[N];
vector<Edge> E;
vector<int> vec[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (x > y) swap(x, y);
		sze[x] += sze[y];
		fa[y] = x;
	}
}

int main() {
	
#ifdef XHT
//	freopen("1.in", "r", stdin);
	freopen("2.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> c;
	for (int i = 0; i <= n; ++i) fa[i] = i, sze[i] = 1;
	E.resize(m);
	for (auto &e : E) {
		e.input();
	}
	sort(E.begin(), E.end());
	for (auto e : E) {
		int u = e.u, v = e.v, w = e.w;
		if (find(u) == find(v)) continue;
		int fu = find(u), fv = find(v);
		if (Max[fu] + c / sze[fu] < w) continue;
		if (Max[fv] + c / sze[fv] < w) continue;
		Union(u, v);
		Max[find(u)] = w;
	}
	for (int i = 0; i < n; ++i) vec[find(i)].push_back(i);
	for (int i = 0; i < n; ++i) {
		sort(vec[i].begin(), vec[i].end());
		for (int j = 0, len = vec[i].size(); j < len; ++j) {
			cout << vec[i][j] << " \n"[j == len - 1];
		}
	}
	return 0;
}
