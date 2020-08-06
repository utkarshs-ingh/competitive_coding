#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout<<"\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,n,a) for(ll i=n-1;i>=a;i--)
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
#define all(v) (v).begin(), (v).end()
#define twhile ll t; cin>>t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/*----------------------------------------------------------------------------------------------------*/

int jump(ll n, ll a[]){ //Recursive without DP

	if(n == 1) return 0;

	ll res = INT_MAX;
	NFOR(i,n-1,0){
		if(a[i] + i >= n-1){
			ll ans = jump(i+1, a);
			res = min(res, ans + 1);
		}
	}
	return res;
}

int jump_DP(ll n, ll a[]){ //(ITERATIVE)Bottom Up Dp => min jumps to reach end

	ll dp[n+1];
	dp[0] = 0;

	FOR(i,1,n) dp[i] = INT_MAX;

	FOR(i,0,n){
		FOR(j,0,i){
			if(i - j <= a[j]){
				dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}

	if(dp[n-1] == INT_MAX) dp[n-1] = -1;
	cout<<dp[n-1];
}


void solve() {
	ll n;
	cin>>n;

	ll a[n];
	FOR(i,0,n) cin>>a[i];

	jump_DP(n, a); nl 
	ll ans = jump(n, a);
	if(ans == INT_MAX) ans = -1;
	cout<<ans; nl
}
/*----------------------------------------------------------------------------------------------------*/

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
