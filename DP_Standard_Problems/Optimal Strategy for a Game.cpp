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
#define IOP freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/* ----------------------------------------------------------------------------------------------------*/

ll OP_REC(ll *a, ll l, ll r){ // RECURSIVE (no DP): optimal game strategy 

	if(l > r) return 0;
	if(l == r - 1) return max(a[l], a[r]);

	ll res1 = a[l] + min(OP_REC(a, l+1, r-1), OP_REC(a, l+2, r));
	ll res2 = a[r] + min(OP_REC(a, l+1, r-1), OP_REC(a, l, r-2));
	return max(res1, res2);
}

ll OP_DP(ll *a, ll l, ll r, ll sum, ll **dp){ //RECURSIVE DP (w memoization): optimal game strategy 

	if(l > r) return 0;
	if(l == r - 1) return max(a[l], a[r]);

	if(dp[l][r] != -1) return dp[l][r];

	ll res1 = sum - OP_DP(a, l+1, r, sum - a[l], dp);
	ll res2 = sum - OP_DP(a, l, r-1, sum - a[r], dp);

	dp[l][r] = max(res1, res2);
	return dp[l][r];

}



void solve() {
	ll n;
    cin>>n;

    ll a[n];
	FOR(i,0,n) cin>>a[i];

	cout << OP_REC(a, 0, n-1); nl
	ll sum = 0; 
	
	sum = accumulate(a, a + n, sum);
	ll **dp = new ll *[sum];
	FOR(i, 0, sum) dp[i] = new ll[sum];
	
	FOR(i, 0, sum)
		FOR(j, 0, sum)
			dp[i][j] = -1;

	cout << OP_DP(a, 0, n-1, sum, dp); nl

}
/*-----------------------------------------------------------------------------------------------------*/

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
