/*
	time complexity O(m \cdot n^3) correct
*/

#include <bits/stdc++.h>

using namespace std;

using db = double;

const int N = 3e2 + 10;

db X, Y;

struct Point {
	int id;
	db x, y;
	
	Point() {}
	
	Point(db _x, db _y) {
		x = _x, y = _y;
	}
	
	void input(int _id) {
		id = _id; 
		cin >> x >> y; 
		X += x, Y += y;
	}
	
	bool operator < (const Point &other) const {
		return (x - X) * (other.y - Y) < (y - Y) * (other.x - X);
	}
}p[N];

db get(Point a, Point b, Point c) {
	db x1 = b.x - a.x, y1 = b.y - a.y, x2 = c.x - a.x, y2 = c.y - a.y;
	return abs(x1 * y2 - x2 * y1);
}

int n, m;
vector<int> res, path[N][N][15];
db f[N][N][11];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
//	freopen("2.in", "r", stdin);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		p[i].input(i);
	}
	X /= n, Y /= n;
	sort(p, p + n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			path[i][j][2].push_back(i);
			path[i][j][2].push_back(j);
		}
	}
	db Max = 0;
	int st = 0, ed = 0;
	for (int k = 3; k <= m; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= i + k - 1; --j) {
				for (int l = j - 1; l > i; --l) {
					db S = f[i][l][k - 1] + get(p[i], p[j], p[l]);
//					cout << i << " " << j << " " << k << " " << l << endl; 
//					cout << S << endl;
					if (S > f[i][j][k]) {
						f[i][j][k] = S;
						path[i][j][k] = path[i][l][k - 1];
						path[i][j][k].push_back(j);
						if (S > Max) {
							Max = S;
							st = i, ed = j;
						}
					}
				}
			}
		}
	} 
	for (auto it : path[st][ed][m]) {
		res.push_back(p[it].id);
	}
	sort(res.begin(), res.end());
	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i] << " \n"[i == 0];
	}
	return 0; 
}
