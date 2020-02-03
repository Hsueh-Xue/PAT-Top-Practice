#include <bits/stdc++.h>

using namespace std;

const int N = 20, INF = 0x3f3f3f3f;

int n, k;
char mp[N][N];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool F;
int Min, cnt;

bool ok(int x, int y) {
	return mp[x][y] == '.';
}

void gao(int x, int y, int Dir, int left) {
//	cout << x << " " << y << endl; 
	if (ok(x + dir[Dir][0], y + dir[Dir][1])) {
		int sx = x, sy = y;
		while (ok(sx + dir[Dir][0], sy + dir[Dir][1])) {
			sx += dir[Dir][0], sy += dir[Dir][1];
			mp[sx][sy] = '*';
			left--;
		}
		if (left < Min) {
			Min = left, cnt = 1, F = false;
		} else if (left == Min && F) {
			cnt++, F = false;
		}
		for (int i = 0; i < 4; ++i) {
			gao(sx, sy, i, left); 
		}
		while (sx != x || sy != y) {
			mp[sx][sy] = '.';
			sx -= dir[Dir][0], sy -= dir[Dir][1];
			left++;
		}
	}
}

void run(int left) {
	Min = INF, cnt = 0;
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < n; ++j) {
			if (mp[i][j] == '.') {
				mp[i][j] = '*';
				F = true;
				for (int k = 0; k < 4; ++k) {
					gao(i, j, k, left - 1);
				} 
				mp[i][j] = '.';
			}
		}
	}
}

int main() {
	
#ifdef XHT
//	freopen("1.in", "r", stdin);
	freopen("2.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		mp[i][n] = mp[n][i] = '#';
		mp[i][1] = mp[1][i] = '#';
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < n; ++j) {
			mp[i][j] = '.';
		}
	} 
	for (int i = 1, x, y; i <= k; ++i) {
		cin >> x >> y;
		mp[x][y] = '@';
	} 
	run((n - 2) * (n - 2) - k);
	cout << Min << " " << cnt << endl;
	int oldMin = Min, oldCnt = cnt;
	int improveMin = oldMin, improveCnt = 0;;
	for (int i = 2; i < n; ++i) {
		for (int j = 2; j < n; ++j) {
			if (mp[i][j] == '.') {
				mp[i][j] = '@';
				run((n - 2) * (n - 2) - k - 1);
				if (Min < improveMin) {
					improveMin = Min;
					improveCnt = 1;
				} else if (Min == improveMin && Min < oldMin) {
					improveCnt++;
				}
				mp[i][j] = '.';
			}
		}
	}
	if (improveMin == oldMin) {
		cout << -1 << endl;
	} else {
		cout << improveMin << " " << improveCnt << endl;
	}
	return 0;
}
