#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10, INF = 0x3f3f3f3f;

int n, res;
string goal;
vector<string> vec;
vector<int> choose;
int vis[N];

void gao(int cur, int extra, int remind) {
	if (extra >= res) return ;
	if (!remind) {
		res = min(res, extra);
		return ;
	}
	if (cur >= n) return ;
	for (int i = cur; i < n; ++i) {
		int tmp = extra, tmp2 = remind;
		for (auto it : vec[i]) {
			if (vis[it] > 0) tmp2--;
			else tmp++;
			vis[it]--;
		}
		gao(i + 1, tmp, tmp2);
		for (auto it : vec[i]) {
			vis[it]++;
		}
	}
}

//void gao(int cur, int extra, string remind) {
//	if (extra >= res) return ;
//	if (remind.empty()) {
//		res = min(res, extra);
//		return ;
//	}
//	if (cur >= n) return ;
//	for (int i = cur; i < n; ++i) {
//		string tmp = remind;
//		int tmp2 = extra;
//		for (auto it : vec[i]) {
//			if (tmp.find(it) != string::npos) {
//				int pos = tmp.find(it);
//				tmp = tmp.erase(pos, 1);
//			} else {
//				tmp2++;
//			}
//		}
//		gao(i + 1, tmp2, tmp);
//	}
//}

int main() {

#ifdef XHT
	freopen("1.in", "r", stdin);
//	freopen("2.in", "r", stdin);
#endif	
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> goal;
	cin >> n;
	vec.resize(n);
	for (auto &it : vec) {
		cin >> it;
		for (auto c : it) {
			vis[c]++;
		}
	}
	for (auto it : goal) {
		if (!vis[it]) {
			res++;
			continue;
		}
		vis[it]--;
	}
	if (res) {
		cout << "No " << res << endl;
		return 0;
	}
	memset(vis, 0, sizeof vis);
	for (auto it : goal) {
		vis[it]++;
	}
	int len = goal.length();
	res = INF;
	gao(0, 0, len);
	cout << "Yes " << res << endl;
	return 0;	
}
