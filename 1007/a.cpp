#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll p = 1e9 + 7;
const int N = 510;

int n;
ll r[N][N], b[N][N];

int main() {
	
#ifdef XHT
	freopen("1.in", "r", stdin);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	b[1][2] = 2;
	b[1][1] = 1;
	r[0][1] = 1;
	
	for (int i = 0; i <= 10; ++i) {
		for (int j = 2; j < n; ++j) {
			for (int k = 1; k < j; ++k) {
				r[i][j + 1] = (r[i][j + 1] + b[i][k] * b[i][j - k] % p) % p;
				b[i + 1][j + 1] = (b[i + 1][j + 1] + (r[i][k] + b[i][k]) % p * (r[i][j - k] + b[i][j - k]) % p) % p;
			}
		}
	} 
	ll res = 0;
	for (int i = 0; i <= 10; ++i) {
		res = (res + b[i][n]) % p;
	}
	cout << res << endl;
	return 0;
}

/*
r[i][j] ��ʾ��Ϊ��ɫ��black-heightΪi��internal node��j���ķ����� 
b[i][j] ��ʾ��Ϊ��ɫ��black-heightΪi��internal node��j���ķ�����

����Ȼ
��black-heightΪi��internal node��j + 1������Ϊ��ɫ��ʱ�� r[i][j] = \sum{b[i][k] * b[i][j - k]}
��black-heightΪi + 1�� internal node��j + 1���� ��Ϊ��ɫ��ʱ�� b[i + 1][j + 1] = \sum{(r[i][k] + b[i][j]) * (r[i][j - k] + b[i][j - k])} 
*/
