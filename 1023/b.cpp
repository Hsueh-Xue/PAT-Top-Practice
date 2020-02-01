/*
time complexity O(n^m) Time limited exceled
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
	
	db operator ^ (const Point &other) const {
		return x * other.y - y * other.x;
	}
	
	bool operator < (const Point &other) const {
		return (x - X) * (other.y - Y) < (y - Y) * (other.x - X);
	}
}p[N];

int n, m;
db Max;
vector<int> res, tmp;

void gao(int cur, int dep) {
	if (dep == m) {
		db S = 0;
		for (int i = 0; i < m; ++i) S += p[tmp[i]] ^ p[tmp[(i + 1) % m]];
		S = fabs(S);
		if (S > Max) {
			Max = S;
			res.clear();
			for (auto it : tmp) {
				res.push_back(p[it].id);
			}
		}
		return ;
	}
	if (cur > n) return ;
	for (int i = cur; i < n; ++i) {
		tmp.push_back(i);
		gao(i + 1, dep + 1);
		tmp.pop_back();
	}
}

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
	gao(0, 0);
	sort(res.begin(), res.end());
	for (int i = res.size() - 1; i >= 0; --i) {
		cout << res[i] << " \n"[i == 0];
	}
	return 0; 
}
