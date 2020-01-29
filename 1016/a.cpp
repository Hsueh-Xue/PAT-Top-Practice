#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

struct node {
	int u, v, w, vis;
	
	node() {}
	
	node(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
	
	void input() {
		cin >> u >> v >> w;
		vis = 0;
	}
	
	bool operator < (const node &other) const {
		return w < other.w;
	}
}e[N];

struct Edge {
	int to, nxt, w;
	
	Edge() {}
	
	Edge(int _to, int _nxt, int _w) {
		to = _to, nxt = _nxt, w = _w;
	}
}edge[N << 1];

int n, m, cnt;
int head[N], tot, dis[N], father[N], dep[N];
int fa[N], sze[N];

void Init() {
	for (int i = 0; i < N; ++i) fa[i] = i, sze[i] = 1;
	memset(head, -1, sizeof head);
	tot = 0;
}

void addedge(int u, int v, int w) {
	edge[tot] = Edge(v, head[u], w); head[u] = tot++;
	edge[tot] = Edge(u, head[v], w); head[v] = tot++;
}

int find(int x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}

bool same(int  x, int y) {
	return find(x) == find(y);
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (sze[x] > sze[y]) swap(x, y);
		sze[y] += sze[x];
		fa[x] = y;
	}
}

int Kruscal() {
	sort(e + 1, e + 1 + m);
	int res = 0, cnt = 0;
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (same(u, v)) {
			e[i].vis = 1;
		} else {
			Union(u, v);
			addedge(u, v, w);
			res += w;
			cnt++;
		}
	}
	if (cnt != n - 1) return -1;
//	for (int i = 1; i <= n; ++i) if (!same(1, i)) return -1;
	return res;
}

void dfs(int u) {
	dep[u] = 1;
	memset(father, -1, sizeof father);
	queue<int>q;
	q.push(u);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to, w = edge[i].w;
			if (dep[v]) continue;
			if (v == father[u]) continue;
			father[v] = u, dis[v] = w, dep[v] = dep[u] + 1;
			q.push(v);
		}
	}
}

int gao(int u, int v) {
	int res = 0;
	while (u != v) {
		if (dep[u] < dep[v]) swap(u, v);
		res = max(res, dis[u]);
		u = father[u];
	}
	return res;
}

bool ok() {
	for (int i = 1; i <= m; ++i) {
		if (e[i].vis) {
			int w = gao(e[i].u, e[i].v);
			if (w == e[i].w) return false;
		}
	}
	return true;
}

int main() {

#ifdef XHT
	freopen("1.in", "r", stdin);
//	freopen("2.in", "r", stdin);
//	freopen("3.in", "r", stdin);
#endif	
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	Init();
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		e[i].input();
	}
	int res = Kruscal();
	if (res == -1) {
		res = 0;
		for (int i = 1; i <= n; ++i) res += find(i) == i;
		cout << "No MST" << endl;
		cout << res << endl;
		return 0;
	}
	cout << res << endl;
	dep[1] = 1;
	dfs(1);
	cout << (ok() ? "Yes" : "No") << endl;
	return 0;
} 
