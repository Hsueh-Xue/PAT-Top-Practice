#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
char s1[N], s2[N];

int main() {

#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	scanf("%s %s", s1 + 1, s2 + 1);
	n = strlen(s1 + 1);
	int Max = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1, k = i; j <= n; ++j) {
			if (k <= n && s1[j] == s2[k]) ++k;
			Max = max(Max, k - i);
		}
	}
	printf("%d\n", n - Max);
	return 0;
}
