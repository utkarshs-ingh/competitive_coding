/* 22, 25, 30 || 38, 47, 50, 16, 29*/

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


void solve() {
	
    ll n, m;
    cin >> n >> m;

    ll a[n][m];
    FOR(i, 0, n)
        FOR(j, 0, m)
            cin >> a[i][j];

    ll dp[n][m];
    memset(dp, 0, sizeof(dp));

    FOR(i, 0, n) dp[i][0] = a[i][0];
    FOR(i, 0, m) dp[0][i] = a[0][i];

	
    FOR(i, 1, n){
        FOR(j, 1, m){
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            if(a[i][j] == 0) dp[i][j] = 0;
        }
    }
	ll ans = INT_MIN;
    FOR(i, 0, n){
        FOR(j, 0, m){
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans;
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
