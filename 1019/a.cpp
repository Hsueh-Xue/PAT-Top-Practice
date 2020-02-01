#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 10;

struct node {
	int x, y;
	
	node() {}
	
	node(int x, int y): x(x), y(y) {}
};

int n, m, k, h;
int mp[N][N], bf[N][N];
char s[N];
int res;
set<ll> se;
int vis[N][N];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

bool ok(ll S) {
	int H = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			bf[i][j] = mp[i][j];
		}
	}
	int cur = 0;
	ll tmp = S;
	while (tmp) {
		if (tmp & 1) {
			int x = (cur / m) + 1, y = (cur % m) + 1;
//			cout << x << " " << y << " " << cur << endl;
			bf[x][y] = 2; 
		} 
		cur++;
		tmp >>= 1;
	}
	queue<node> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (bf[i][j] == 2) continue;
			bool hole = true;
			int animal = (bf[i][j] == 1);
			bf[i][j] = 2;
			q.push(node(i, j));
			while (!q.empty()) {
				node u = q.front(); q.pop();
				for (int k = 0; k < 4; ++k) { 
					int dx = u.x + dir[k][0], dy = u.y + dir[k][1];
					if (dx < 1 || dx > n || dy < 1 || dy > m) {
						hole = false;
						continue;
					}
					if (bf[dx][dy] == 2) continue;
					if (bf[dx][dy] == 1) animal++;
					if (animal >= 2) return false;
					q.push(node(dx, dy));
					bf[dx][dy] = 2;
				}
			}
			H += hole;
			hole = true;
		}
	}
	return H == h;
}

void gao(ll S, int cur) {
	if (se.count(S)) return ;
	se.insert(S);
	if (cur == k) {
		if (ok(S)) {
			res++;
		}
		return ;
	}
	ll now = S;
	int tmp = 0;
	while (now) {
		if (now & 1) {
			int x = (tmp / m) + 1, y = (tmp % m) + 1;
			for (int i = 0; i < 4; ++i) {
				int dx = x + dir[i][0], dy = y + dir[i][1];
				if (mp[dx][dy] == 0 && dx >= 1 && dx <= n && dy >= 1 && dy <= m && !vis[dx][dy]) {
					vis[dx][dy] = 1;
					gao(S | (1ll << ((dx - 1) * m + (dy - 1))), cur + 1);
					vis[dx][dy] = 0;
				}
			}	
		}
		tmp++;
		now >>= 1;
	} 
}

int main() {
	
#ifdef XHT	
	freopen("1.in", "r", stdin);
#endif

	cin >> n >> m >> k >> h;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		for (int j = 1; j <= m; ++j) {
			mp[i][j] = (s[j - 1] == '.' ? 0: 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!mp[i][j]) {
				memset(vis, 0, sizeof vis);
				vis[i][j] = 1;
				gao(1ll << ((i - 1) * m + j - 1), 1);
			}
		}
	}
	cout << res <<endl;
	return 0;
}
