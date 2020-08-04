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

int TotalCoins(ll n, ll coins[], ll amt){ //***2D-DP***(ITERATIVE)Bottom up Dp + memoization => Total unique Coin change Problem
	ll dp[amt+1][n+1];

	FOR(i,0,amt+1) dp[i][0] = 0;
	FOR(i,0,n+1) dp[0][i] = 1;

	FOR(i,1,amt+1){
		FOR(j,1,n+1){
			if(i < coins[j-1]){
				dp[i][j] = dp[i][j-1];
			}
			else dp[i][j] = dp[i-coins[j-1]][j] + dp[i][j-1];
		}
	}
	cout<<dp[amt][n];
}

int MinCoinsDP(ll n, ll coins[], ll amt, ll *dp){  //(RECURSIVE)Top Down Dp + memoization => Coins change Problem

	if(amt == 0) return 0;

	ll ans = INT_MAX;
	if(dp[amt] != 0) return dp[amt];

	FOR(i,0,n){
		if(amt >= coins[i]){
			ll minans = MinCoinsDP(n, coins, amt-coins[i], dp);
			ans = min(ans, minans+1);
		}
	}
	dp[amt] = ans;
	return dp[amt];
}


int minCoins(ll n, ll coins[], ll amt){ //Recursive without DP
	
	if(amt == 0){
		return 0;
	}
	ll minAns = INT_MAX;
	FOR(i,0,n){
		if(amt-coins[i] >= 0){
			ll ans = minCoins(n, coins, amt-coins[i]);
			if(ans < minAns){
				minAns = ans+1;
			}
		}
	}
	return minAns;
}

int minCoinsDP(ll n, ll coins[], ll amt){ //(ITERATIVE)Bottom up Dp + memoization => Coin change Problem
	ll dp[amt];
	memset(dp, 0, sizeof(dp));
	
	FOR(i,1,amt+1){
		dp[i] = INT_MAX;
		FOR(j,0,n){ //iterate over available coins
			if(coins[j] <= i){
				ll ans = dp[i - coins[j]];
				if(ans != INT_MAX) dp[i] = min(ans+1, dp[i]);
			}
		}
	}
	if(dp[amt] == INT_MAX) dp[amt] = -1;
	cout<<dp[amt];
}


void solve() {
	
	ll n;
	cin>>n;

	ll coins[n];
	FOR(i,0,n) cin>>coins[i];
	
	ll amt;
	cin>>amt;

	//RECURSIVE
	cout<<minCoins(n,coins,amt); nl

	// //ITERATIVE DP
	minCoinsDP(n,coins,amt); nl

	//RECURSIVE DP
	ll dp[amt+1];
	memset(dp, 0, sizeof(dp));

	cout<<MinCoinsDP(n,coins,amt,dp); nl
	// FOR(i,0,amt) cout<<dp[i]<<" ";
}

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
