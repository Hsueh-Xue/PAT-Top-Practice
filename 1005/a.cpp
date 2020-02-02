#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

const ull Base = 233;

int n;
string s;
unordered_map<ull, int> mp;
vector<int> vec;

bool f(int a, int b) {
	for (int i = 0; i < n; ++i) {
		if (s[i + a] != s[i + b]) {
			return s[i + a] < s[i + b];
		}
	}
	return true;
}

int main() {

#ifdef XHT
//	freopen("1.in", "r", stdin);
	freopen("2.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	cin.ignore();
	getline(cin, s);
	ull hash = 0, high = 1;
	for (int i = 0; i < n; ++i) {
		hash = hash * Base + s[i];
		high = high * Base;
	}
	int Max = 0, len = s.size();
	for (int i = 0; i + n <= len; ++i) {
		int tmp = ++mp[hash];
		if (tmp > Max) {
			Max = tmp;
			vec.clear();
			vec.push_back(i);
		} else if (tmp == Max) {
			vec.push_back(i);
		}
		if (i + n < len) hash = hash * Base + s[i + n] - s[i] * high;
	}
	int res = -1;
	for (auto idx : vec) {
		if (res == -1 || f(idx, res)) res = idx;
	}
	for (int i = 0; i < n; ++i) cout << s[res + i];
	cout << " " << Max << endl;
	return 0;
}
