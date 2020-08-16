/*11, 12, 17 || 19, 22, 25, 30 || 38, 47, 50, 16, 29*/

#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout << "\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i, a, n) for(ll i = a; i < (n); i++)
#define NFOR(i, n, a) for(ll i = n-1; i >= a; i--)
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
#define all(v) (v).begin(), (v).end()
#define twhile ll t; cin >> t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/*----------------------------------------------------------------------------------------------------*/

int EGG_REC(ll n, ll e){ //RECURSIVE no DP => Egg Dropping Puzzle problem

	if (n == 1 or n == 0) return 1;
	if (e == 1) return n;

	ll res, ans = INT_MAX;
	FOR(i, 1, n+1){
		res = max(EGG_REC(i-1, e-1), EGG_REC(n-i, e)) + 1;
		ans = min(ans, res);
	}
	return ans;
}

void EGG_DP(ll n, ll e){ //(ITERATIVE)Bottom Up Dp => Egg Dropping Puzzle problem

	ll dp[n+1][e+1];
	FOR(i, 0, n+1)
	    FOR(j, 0, e+1)
	        dp[i][j] = 0;

	FOR(i, 0, n+1) dp[i][1] = i;
	FOR(i, 0, e+1) dp[1][i] = 1;

	ll res = 0;
	FOR(i, 2, n+1){
		FOR(j, 2, e+1){
			dp[i][j] = INT_MAX;
			FOR(x, 1, i+1){
				res = 1 + max(dp[x-1][j-1], dp[i-x][j]);
				dp[i][j] = min(dp[i][j], res);
			}
		}
	}

	cout<<dp[n][e];
}

void solve() {
	
	ll n, e;
	cin >> e >> n;

	cout << EGG_REC(n, e);
	nl
	EGG_DP(n, e);
	nl

}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
