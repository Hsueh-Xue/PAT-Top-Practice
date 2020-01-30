#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int n;
int a[N], L[N], R[N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
//	freopen("2.in", "r", stdin);
#endif
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	L[0] = R[n + 1] = -1; 
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (a[i] > a[j]) {
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = n; j > i; --j) {
			if (a[i] > a[j]) {
				R[i] = max(R[i], R[j] + 1);
			}
		}
	}
	int res = -1, index = -1, Min = INF;
	for (int i = 1; i <= n; ++i) {
		if (L[i] == 0 || R[i] == 0) continue; 
		if (res < L[i] + R[i] + 1 || (res == L[i] + R[i] + 1 && abs(R[i] - L[i]) < Min)) {
			res = L[i] + R[i] + 1;
			Min = abs(R[i] - L[i]);
			index = i;
		}
	}
	if (res != -1) {
		cout << res << " " << index << " " << a[index] << endl;
	}
	else {
		cout << "No peak shape" << endl;
	}
	return 0;
}
