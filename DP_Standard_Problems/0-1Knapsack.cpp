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

ll knap(ll *val, ll *w, ll n, ll Tw){ //Recursive without DP

	if(n == 0 || Tw == 0) return 0;

	if(w[n] > Tw) return knap(val, w, n-1, Tw);
	else{
		return max((val[n] + knap(val, w, n-1, Tw - w[n])), knap(val, w, n - 1, Tw));
	}
}

ll knap_DP(ll *val, ll *w, ll n, ll Tw, ll **dp){ //Recursive Top down DP with memoization
	
	if(n < 0) return 0;
	if(dp[n][Tw] != -1) return dp[n][Tw];
	if(w[n] > Tw){
		dp[n][Tw] = knap_DP(val, w, n-1, Tw, dp);
		return  dp[n][Tw]; 
	}

	else{
		dp[n][Tw] = max((val[n] + knap_DP(val, w, n-1, Tw - w[n], dp)), knap_DP(val, w, n-1, Tw, dp));
		return dp[n][Tw];	
	}

}

int knap_DP(ll *val, ll *w, ll n, ll t){ //(ITERATIVE)Bottom Up Dp => 0/1 Knapsack Problem
	
	ll dp[n+1][t+1];
	
	FOR(i,0,n+1){
		FOR(j,0,t+1){
			if(i == 0 or j == 0) dp[i][j] = 0;
			else if(w[i-1] > j) dp[i][j] =  dp[i-1][j];
			else{
				dp[i][j] = max((val[i-1] + dp[i-1][j - w[i-1]]), dp[i-1][j]);
			}
		}
	}
	// FOR(i,0,n+1){
	// 	FOR(j,0,t+1)
	// 		cout<<dp[i][j]<<" ";
	// 	nl
	// }
	cout<<dp[n][t]; nl
}


void solve() {
	ll n, Tw;
	cin>>n>>Tw;

	ll val[n], W[n];
	FOR(i,0,n) cin>>val[i];
	FOR(i,0,n) cin>>W[i];

	cout<<knap(val, W, n-1, Tw); nl

	ll **dp = new ll*[n];
	FOR(i,0,n) dp[i] = new ll[Tw + 1];
	
	FOR(i,0,n) 
        FOR(j,0,Tw+1) 
            dp[i][j] = -1; 

	cout<<knap_DP(val, W, n-1, Tw, dp); nl
	knap_DP(val, W, n, Tw); 
	
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
