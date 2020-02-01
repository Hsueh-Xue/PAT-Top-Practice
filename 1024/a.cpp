#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

set<string> se;

struct Edge {
	int u, v, fee;
	string center;
	
	void input() {
		cin >> u >> v >> center >> fee;
	}
	
	bool operator < (const Edge &other) const {
		if (fee != other.fee) {
			return fee > other.fee;
		} else {
			auto it = se.find(center);
			return it == se.end();
		}
	} 
}e[N];

bool cmp(Edge a, Edge b) {
	if (a.center != b.center) {
		return a.center < b.center;
	} else {
		return a.fee < b.fee;
	}
}

int n, m;
int fa[N];
vector<Edge> vec;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i <= n; ++i) fa[i] = i;
	priority_queue<Edge> pq;
	for (int i = 1; i <= m; ++i) {
		e[i].input();
		pq.push(e[i]);
	}
	int res = 0;
	while (!pq.empty()) {
		Edge tmp = pq.top(); pq.pop();
		int u = tmp.u, v = tmp.v;
		u = find(u), v = find(v);
		if (u == v) continue;
		fa[u] = v;
		vec.push_back(tmp);
		se.insert(tmp.center);
		res += tmp.fee;
	}
	sort(vec.begin(), vec.end(), cmp);
	cout << se.size() << " " << res << endl;
	for (auto it :vec) {
		cout << it.u << " " << it.v << " " << it.center << " " << it.fee <<endl;
	}
	return 0;
}
