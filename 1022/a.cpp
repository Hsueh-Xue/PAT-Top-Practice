#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 10;

int n, m, l;
vector<int> vec;

int main() {

#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> l;
	vec.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> vec[i];
	}
    return 0;
}
