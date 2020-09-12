/*50, 16, 29, 8*/

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

ll superSeq(string x, ll n, string y, ll k, ll total){

    ll dp[n + 1][k + 1];
	
	FOR(i, 0, n+1) dp[i][0] = 0;
	FOR(i, 0, k+1) dp[0][i] = 0;
	
	FOR(i, 1, n+1){
		FOR(j, 1, k+1){
			if(x[i-1] == y[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << total - dp[n][k];
	nl

}

void solve() {

    string s1, s2;
    cin >> s1 >> s2;

    ll n = s1.length();
    ll k = s2.length();

    ll total = n + k;
        
    superSeq(s1, n, s2, k, total);
	
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}

