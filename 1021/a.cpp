#include <bits/stdc++.h>

using namespace std;

using pII = pair<int, int>;

const int N = 1e3 + 10;

int n, m, pos, res, cost;
int G[N][N], id[N], no[N];
int w[N];
int cnt[N], group[N], vis[N];


void gao(int u, int t_res, int t_cost) {
	for (int i = u + 1; i <= n; ++i) {
		if (cnt[i] + t_res < res || (cnt[i] + t_res == res && t_cost >= cost)) return ;
		if (G[u][i]) {
			bool F = true;
			for (int j = 0; j < t_res; ++j) {
				if (!G[i][vis[j]]) {
					F = false;
					break;
				}
			}
			if (!F) continue;
			vis[t_res] = i;
			gao(i, t_res + 1, t_cost + w[i]);
		}
	}
	if (t_res > res || (t_res == res && t_cost < cost)) {
		for (int i = 0; i < t_res; ++i) {
			group[i] = vis[i];
		}
		res = t_res;
		cost = t_cost;
	}
}

void maxclique() {
	res = -1;
	for (int i = n; i >= 1; --i) {
		vis[0] = i;
		gao(i, 1, w[i]);
		cnt[i] = res;
	}
}

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	pos = 1;
	scanf("%d %d", &m, &n);
	memset(G, -1, sizeof G);
	vector<pII> E;
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		E.push_back(pII(u, v));	
	}
	for (int i = 0, a, b; i < n; ++i) {
		scanf("%d %d", &a, &b);
		if (!no[a]) no[a] = pos, id[pos++] = a;
		w[no[a]] = b;
	}
	for (auto it : E) {
		int u = no[it.first], v = no[it.second];
		G[u][v] = G[v][u] = 0;
	}
	maxclique();
	vector<int> vec;
	for (int i = 0; i < res; ++i) vec.push_back(id[group[i]]);
	sort(vec.begin(), vec.end());
	printf("%d\n", res);
	for (int i = 0; i < res; ++i) {
		printf("%03d%c", vec[i], " \n"[i == res - 1]);
	}
	printf("%d\n", cost);
	return 0;
}
