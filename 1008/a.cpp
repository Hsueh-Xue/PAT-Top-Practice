#include <bits/stdc++.h>

using namespace std;

#define endl "\n" 

const int N = 1e5 + 10;

int n, m, q;
vector<vector<int> > G;

int Low[N], DFN[N], Stack[N], Belong[N];
int Index, top;
int scc;
bool Instack[N];

void gao(int u) {
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	for (auto v : G[u]) {
		if (!DFN[v]) {
			gao(v);
			Low[u] = min(Low[u], Low[v]);
		} else if (Instack[v]) {
			Low[u] = min(Low[u], DFN[v]);
		}
	}
	if (Low[u] == DFN[u]) {
		scc++;
		int v;
		do {
			v = Stack[--top];
			Instack[v] = false;
			Belong[v] = scc;
		} while (v != u);
	}
}

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	G.resize(n + 1);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		G[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) if (!DFN[i]) gao(i);
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << (Belong[u] == Belong[v] ? "Yes" : "No") << endl;
	}
	return 0;
}
