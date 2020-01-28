#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

struct Edge {
	int u, v, cost, status;
	
	Edge() {}
	
	Edge(int u, int v, int cost, int status) : u(u), v(v), cost(cost), status(status) {}
	
	bool operator < (const Edge &other) const {
		if (status + other.status) {
			if (status + other.status == 2) {
				return cost < other.cost;
			} else {
				return status > other.status;
			}
		} else {
			return cost < other.cost;
		}
	}
};

int n, m;
vector<Edge> edge;
vector<int> ans;

int fa[N], sze[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Union(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (sze[x] > sze[y]) swap(x, y);
		sze[y] += sze[x];
		fa[x] = y;
	}
}

int gao(int u) {
	for (int i = 1; i <= n; ++i) fa[i] = i, sze[i] = 1;
	int res = 0, count = 1;
	for (auto e : edge) {
		if (e.u == u || e.v == u) continue;
		if (find(e.u) == find(e.v)) continue;
		if (e.status == 0) res += e.cost;
		Union(e.u, e.v);
		count++;
		if (count == n - 1) break;
	}
	if (count == n - 1) return res;
	else return INF;
}

int main() {
	
#ifdef XHT
//	freopen("1.in", "r", stdin);
	freopen("2.in", "r", stdin);
#endif
	
	cin >> n >> m;
	for (int i = 1, u, v, cost, status; i <= m; ++i) {
		cin >> u >> v >> cost >> status;
		edge.push_back(Edge(u, v, cost, status));
	}
	sort(edge.begin(), edge.end());
	int Max = 1;
	for (int i = 1; i <= n; ++i) {
		int res = gao(i);
		if (res > Max) {
			ans.clear();
			ans.push_back(i);
			Max = res;
		} else if (res == Max) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) cout << 0 << endl;
	else {
		for (int i = 0, len = ans.size(); i < len; ++i) {
			cout << ans[i] << " \n"[i == len - 1];
		}
	}
	return 0;
} 

/*
题意：给定一张带权无向图，有些路已经损坏，问删去哪个或者哪些点会使得图联通的代价最大
思路：做n遍Krusual 
*/
