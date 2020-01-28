#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

int n;
map<string, int> mp;
int cnt;

int get(string s) {
	if (mp.count(s)) return mp[s];
	else return mp[s] = ++cnt;
}

struct Edge {
	int to, nxt, flow;
	
	Edge() {}
	
	Edge(int to, int nxt, int flow): to(to), nxt(nxt), flow(flow) {}
}edge[N << 1];

int S, T;
int dep[N];
int head[N], tot;

void Init() {
	memset(head, -1, sizeof head);
	tot = 0;
}

void addedge(int u, int v, int w) {
	edge[tot] = Edge(v, head[u], w); head[u] = tot++;
	edge[tot] = Edge(u, head[v], 0); head[v] = tot++;
}

bool BFS() {
	memset(dep, -1, sizeof dep);
	dep[S] = 1;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (edge[i].flow && dep[v] == -1) {
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[T] != -1;
}

int DFS(int u, int f) {
	if (u == T || f == 0) return f;
	int w, used = 0;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (edge[i].flow && dep[v] == dep[u] + 1) {
			w = DFS(v, min(f - used, edge[i].flow));
			edge[i].flow -= w;
			edge[i ^ 1].flow += w;
			used += w;
			if (used == f) return f;
		}
	}
	if (!used) dep[u] = -1;
	return used;
}

int gao() {
	int res = 0;
	while (BFS()) {
		res += DFS(S, INF);
	}
	return res;
}

string st, ed;

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	Init();
	
	cin >> st >> ed >> n;
	S = get(st);
	T = get(ed);
	for (int i = 1, u, v, w; i <= n; ++i) {
		cin >> st >> ed >> w;
		u = get(st);
		v = get(ed);
		addedge(u, v, w);
	}
	cout << gao() << endl;
	return 0; 
} 

/*
ÍøÂçÁ÷Ä£°åÌâ 
*/
