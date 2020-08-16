/* 19, 22, 25, 30 || 38, 47, 50, 16, 29*/

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
ll dp[1001][1001];

bool isPalindrome(ll i, ll j, string s){
	while(i <= j){
		if(s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

ll PP_REC(string s, ll i, ll j){ //RECURSIVE no DP => Palindromic patitioning problem

	if(i >= j or isPalindrome(i, j, s)) return 0;

	ll ans = INT_MAX;
	FOR(k, i, j){
		ll res = PP_REC(s, i, k) + PP_REC(s, k+1, j) + 1;
		ans = min(ans, res);
	}
	
	return ans;
}

int PP_DP(string s, ll i, ll j){ //recursive DP
	if(i >= j or isPalindrome(i, j, s)) return 0;
	if(dp[i][j] != -1) return dp[i][j];

	ll ans = INT_MAX, res, res1, res2;
	FOR(k, i, j){
		if(dp[i][k] != -1){
			res1 = dp[i][k];
		}
		else {
			res1 = PP_DP(s, i, k);
			dp[i][k] = res1;
		}

		if(dp[k+1][j] != -1){
			res2 = dp[k+1][j];
		}
		else {
			res2 =  PP_DP(s, k+1, j);
			dp[k+1][j] = res2;
		}

		res = res1 + res2 + 1;

		ans = min(ans, res);
		dp[i][j] = ans;
	}
	return ans;
	
}

void solve() {
	
	string s;
	cin >> s;

	ll n = s.size();

	// cout << PP_REC(s, 0, n-1); nl
	memset(dp, -1, sizeof(dp));
	cout << PP_DP(s, 0, n-1); nl
	
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
