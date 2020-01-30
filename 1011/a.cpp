#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;

struct Point {
	ll x, y;
	
	Point() {}
	
	Point(int _x, int _y): x(_x), y(_y) {}
	
	void input() {
		cin >> x >> y;
	}
	
	ll dis(Point &other) {
		return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
	}
	
	bool operator == (const Point &other) const {
		return x == other.x && y == other.y;
	}
	
	bool sim(Point other) {
		return x == other.x || y == other.y;
	}
};

int n;
vector<Point>A, B;
vector<ll> v1, v2;

bool RUN() {
	v1.clear(), v2.clear();
	int lena = A.size(), lenb = B.size(), cntA = 0, cntB = 0;
	for (int i = 0; i < lena; ++i) {
		if (A[i].sim(A[(i + 1) % lena])) {
			cntA++;
		}
	} 
	for (int i = 0; i < lenb; ++i) {
		if (B[i].sim(B[(i + 1) % lenb])) {
			cntB++;
		}
	} 
	//4 4
	if (lena == 4 && lenb == 4) {
		if (cntA == 4 && cntB == 4) {
			for (int i = 0; i < 4; ++i) {
				v1.push_back(A[i].dis(A[(i + 1) % 4]));
				v2.push_back(B[i].dis(B[(i + 1) % 4]));
			}
			return v1[0] == v2[0] || v1[0] == v2[1] || v1[1] == v2[0] || v2[1] == v2[1];
		} else if (cntA == 3 && cntB == 3) {
			for (int i = 0; i < 4; ++i) {
				if (A[i].sim(A[(i + 1) % 4])) continue;
				int x1 = i, x2 = (i + 1) % 4, x3 = (i + 2) % 4, x4 = (i + 3) % 4;
				v1.push_back(A[x1].dis(A[x2]));
				ll tmp = sqrt(A[x2].dis(A[x3])) - sqrt(A[x1].dis(A[x4]));
				v1.push_back(tmp * tmp);
				v1.push_back(A[x3].dis(A[x4]));
			}
			for (int i = 0; i < 4; ++i) {
				if (B[i].sim(B[(i + 1) % 4])) continue;
				int x1 = i, x2 = (i + 1) % 4, x3 = (i + 2) % 4, x4 = (i + 3) % 4;
				v2.push_back(B[x1].dis(B[x2]));
				ll tmp = sqrt(B[x2].dis(B[x3])) - sqrt(B[x1].dis(B[x4]));
				v2.push_back(tmp * tmp);
				v2.push_back(B[x3].dis(B[x4]));
			}
//			sort(v1.begin(), v1.end());
//			sort(v2.begin(), v2.end());
			return v1 == v2;
		} else {
			return false;
		}
	}
	if (lena != 3 || cntA != 2) return false;
	for (int i = 0; i < lena; ++i) v1.push_back(A[i].dis(A[(i + 1) % lena]));
	if (lenb == 3 && cntB == 2) {
		for (int i = 0; i < lenb; ++i) {
			v2.push_back(B[i].dis(B[(i + 1) % lenb]));
		}
	} else if (lenb == 4 && cntB == 3) {
		for (int i = 0; i < 4; ++i) {
			if (B[i].sim(B[(i + 1) % 4])) continue;
			int x1 = i, x2 = (i + 1) % 4, x3 = (i + 2) % 4, x4 = (i + 3) % 4;
			v2.push_back(B[x1].dis(B[x2]));
			ll tmp = sqrt(B[x2].dis(B[x3])) - sqrt(B[x1].dis(B[x4]));
			v2.push_back(tmp * tmp);
			v2.push_back(B[x3].dis(B[x4]));
		}
	} else if (lenb == 5 && cntB == 4) {
		for (int i = 0; i < 5; ++i) {
			if (B[i].sim(B[(i + 1) % 5])) continue;
			int x1 = i, x2 = (i + 1) % 5, x3 = (i + 2) % 5, x4 = (i + 3) % 5, x5 = (i + 4) % 5;
			v2.push_back(B[x1].dis(B[x2]));
			ll tmp = sqrt(B[x2].dis(B[x3])) - sqrt(B[x4].dis(B[x5]));
			v2.push_back(tmp * tmp);
			tmp = sqrt(B[x3].dis(B[x4])) - sqrt(B[x5].dis(B[x1]));
			v2.push_back(tmp * tmp);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	return v1 == v2;
}

int main() {

#ifdef XHT
	freopen("1.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		A.clear(), B.clear();
		cin >> n;
		A.resize(n);
		for (auto &it : A) {
			it.input();
		}
		cin >> n;
		B.resize(n);
		for (auto &it : B) {
			it.input();
		}
		if (A.size() > B.size()) swap(A, B);
		cout << (RUN() ? "YES" : "NO") << endl;	
	}
	return 0;
}

/*
仔细观察发现只有四种情况
1. 三角形和三角形
2. 三角形和四边形
3. 三角形和五边形
4. 四边形和四边形

显然123三种情况只要将另一边缺失的三角形画出来，通过判断两个三角形是否相等即可
第四种情况分为竖直和歇着切两种情况 分类讨论即可 
*/
