#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout<<"\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define pi pair<ll,ll>
#define MOD 1000000000+7
#define twhile ll t; cin>>t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;

int Ladder(ll n, ll *dp, ll k){  //(RECURSIVE => WINDOW SLIDING)Top Down Dp + memoization => n th Stair

	if (n == 1 || n == 0) 
    { 
		dp[n] = n;
        return n; 
    } 
	if (n-k < 0) 
    { 
		dp[n] = 2*Ladder(n - 1,dp,k); 
    } 
	else dp[n] = 2*Ladder(n - 1,dp,k) - Ladder(n-k,dp,k); 
}


int ladder(ll n, ll k){ //(ITERATIVE)Bottom Up Dp + memoization => Ladder Problem
	ll dp[n+1];

	dp[0] = 1;

	FOR(i,1,n+1){
		dp[i] = 0;
		FOR(j,1,k+1){
			if(i-j >= 0) dp[i] += dp[i-j];
		} 
	}
	cout<<dp[n];
}


void solve() {
	
	ll n,k;
	cin>>n>>k;
	ll dp[n];
	memset(dp, -1, sizeof(dp));

	cout<<Ladder(n,dp,k);
	// ladder(n,k);
}

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
