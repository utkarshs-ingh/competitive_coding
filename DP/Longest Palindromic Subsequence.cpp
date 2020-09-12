/* 12, 17 || 19, 22, 25, 30 || 38, 47, 50, 16, 29*/

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

ll LPS_REC(string s, ll i, ll j){ //RECURSIVE no DP => Longest Palindromic Subsequence problem

	if(i == j) return 1;

	if(s[i] == s[j] and i == j - 1) return 2;

	else if(s[i] == s[j]) return LPS_REC(s, i+1, j-1) + 2;

	return max(LPS_REC(s, i+1, j), LPS_REC(s, i, j-1));

}

void LPS_DP(ll n, string s){ //(ITERATIVE)Bottom Up Dp => Longest Palindromic Subsequence problem

	ll dp[n][n];
	
	FOR(i, 0, n)
		dp[i][i] = 1;
	
	FOR(i, 2, n+1){
		FOR(j, 0, n-i+1){
			ll k = i + j - 1;
			if(s[j] == s[k] and i == 2) dp[j][k] = 2;
			else if(s[j] == s[k]) dp[j][k] = dp[j+1][k-1] + 2;
			else dp[j][k] = max(dp[j+1][k], dp[j][k-1]);
		}
	}
	cout << dp[0][n-1];
	
}

void solve() {
	
	string s;
	cin >> s;

	ll n = s.size();

	// cout << LPS_REC(s, 0, n-1); nl
	LPS_DP(n, s); nl
	
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
