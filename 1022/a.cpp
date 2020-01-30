#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, m, l;
vector<int> vec;
int id[N], vis[N];

void gao(vector<int> wolf) {
	if (wolf.size() == m) {
		vector<int> lie;
		for (int i = 1; i <= n; ++i) {
			if (id[abs(vec[i])] * vec[i] < 0) lie.push_back(i);
		}
		if (lie.size() == l) {
			int cnt = 0;
			for (auto it : lie) {
				if (id[it] == -1) cnt++;
			}
			if (cnt > 0 && cnt < m) {
				sort(wolf.end(), wolf.end());
				for (int i = 0, len = wolf.size(); i < wolf.size(); ++i) {
					cout << wolf[i] << " \n"[i == len - 1];
				}
				exit(0);
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		if (!vis[i]) {
			vis[i] = 1;
			id[i] = -1;
			wolf.push_back(i);
			gao(wolf);
			wolf.pop_back();
			vis[i] = 0;
			id[i] = 1;
		}
	}
}

int main() {

#ifdef XHT
//	freopen("1.in", "r", stdin);
//	freopen("2.in", "r", stdin);
	freopen("3.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> l;
	vec.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i];
		id[i] = 1;
	}
	vector<int> wolf;
	gao(wolf);
	cout << "No Solution" << endl;
    return 0;
}
