#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout<<"\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
#define all(v) (v).begin(), (v).end()
#define twhile ll t; cin>>t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/*----------------------------------------------------------------------------------------------------*/

int LCS(char *x, ll n, char *y, ll k){ //Recursive without DP

	if(n == 0 || k == 0) return 0;

	if(x[n-1] == y[k-1]) return 1 + LCS(x, n-1, y, k-1);

	else return max(LCS(x, n, y, k-1), LCS(x, n-1, y, k));

}

int LCS_DP(char *x, ll n, char *y, ll k, ll dp[101][101]){ //Recursive Top down DP with memoization

	if(n < 0 || k < 0) return 0;
	if(dp[n][k] != -1) return dp[n][k];
	
	ll res;
	if(x[n] == y[k]) res = 1 + LCS_DP(x, n-1, y, k-1, dp);
	else res = max(LCS_DP(x, n, y, k-1, dp), LCS_DP(x, n-1, y, k, dp)); 

	dp[n][k] = res;
	return res;
}

int LCS_DP(char *x, ll n, char *y, ll k){ //(ITERATIVE)Bottom Up Dp + memoization => Longest common subseq Problem
	
	ll dp[n+1][k+1];
	
	FOR(i,0,n+1) dp[i][0] = 0;
	FOR(i,0,k+1) dp[0][i] = 0;
	
	FOR(i,1,n+1){
		FOR(j,1,k+1){
			if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n][k];
	nl
	ll val = dp[n][k];
	
	ll ans[val+1];

	ll i = n, j = k;
	while (i > 0 and j > 0){
		if(x[i-1] == y[j-1]){
			ans[val] = x[i-1];
			val--, i--, j--; 
		}
		else if(dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}

	FOR(i,1,dp[n][k]+1) cout<<ans[i]<<" ";
}


void solve() {
	ll n,k;
	cin>>n>>k;

	char X[n], Y[k];
	FOR(i,0,n) cin>>X[i];
	FOR(i,0,k) cin>>Y[i];

	cout<<LCS(X, n, Y, k);
	nl
	LCS_DP(X, n, Y, k);
	nl
	
	ll dp[101][101];
	memset(dp, -1, sizeof(dp));

	cout<<LCS_DP(X, n, Y, k, dp);
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
