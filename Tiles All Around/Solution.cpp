#include <bits/stdc++.h>

using namespace std;

#define ll                      long long
#define vi                      vector<int>
#define vll                     vector<ll>
#define MOD                     1000000007
#define endl                    "\n"
#define fastIO                  ios_base::sync_with_stdio(false),cin.tie(NULL), cout.tie(NULL)
#define ALL(v)                  v.begin(),v.end()
#define REP(i, n)               FOR(i, 0, n) 
#define REPN(i, n)              FORN(i, 1, n) 
#define FOR(a, b, c)            for (int(a) = (b); (a) < (c); ++(a)) 

/*Matrix exponentiotion works like binary exponentiation
ll fastexp(ll base, ll exp) {
	ll res = 1;
	while (exp > 0) {
		if (exp % 2 == 1)
			res = (res * base) % MOD;
		base = (base * base) % MOD;
		exp /= 2;
	}
	return res % MOD;
}
*/
//2x2 Matrix multiplication
void matrixMul(vector<vector<ll>>& identity, vector<vector<ll>>& mt, int n) {
	vector<vector<ll>> res(n, vector<ll>(n, 0));
	REP(i, n) {
		REP(j, n) {
			REP(k, n) {
				res[i][j] =(res[i][j]+ (mt[i][k] * identity[k][j])%MOD)%MOD;
			}
		}
	}
	identity = res;
}

//Matrix Exponentiation
void matrixExpo(vector<vector<ll>>& mt, int n, ll exp) {
	vector<vector<ll>> identity(n, vector<ll>(n, 0));
	REP(i, n)
		REP(j, n) {
		if (i == j)
			identity[i][j] = 1;
	}
	while (exp) {
		if (exp % 2 == 1) {
			matrixMul(identity, mt, n);
		}
		matrixMul(mt, mt, n);
		exp /= 2;
	}
	mt = identity;
}

int main() {
	fastIO, srand(time(0));
	int test, sno = 0;
	cin >> test;

	while (sno++ < test) {
		int n;
		ll exp;
		cin >> exp;
		n = 2;
		vector<vector<ll>> mt(n, vector<ll>(n, 0));
		mt[0][0] = 1ll;
		mt[0][1] = 1ll;
		mt[1][0] = 1ll;
		mt[1][1] = 0ll;
		matrixExpo(mt, n, exp);
		cout << mt[0][0]%MOD << endl;
	}

}