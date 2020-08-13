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

int LPS(ll n, string s){ //ITERATIVE without DP in constant space

	ll start = 0, len = 1, left, right;

	FOR(i,1,n+1){

		left = i - 1;
		right = i;

		while(left >= 0 and right < n and s[left] == s[right]){
			if(right - left + 1 > len) len = right - left + 1, start = left;
			left--;
			right++;
		}


		left = i - 1;
		right = i + 1;

		while(left >= 0 and right < n and s[left] == s[right]){
			if(right - left + 1 > len) len = right - left + 1, start = left;
			left--;
			right++;
		}
	}

	cout<<len; nl
	FOR(i,start, start + len) cout<<s[i];
	
}

int LPS_DP(ll n, string s){ //(ITERATIVE)Bottom Up Dp => Longest Palindromic Substring problem

	ll dp[n][n];
	memset(dp, 0, sizeof(dp));

	FOR(i,0,n) dp[i][i] = 1; //diagonal elements are same 

	ll len = 1, start = 0;

	FOR(i,0,n-1){ // just for len 2 pallendromic substrings
		if(s[i] == s[i+1]){
			dp[i][i+1] = 1;
			start = i;
			len = 2;
		}
	} 

	FOR(k,3,n+1){ 
        FOR(i,0,n-k+1){ 

            ll j = i + k - 1; 
            if (dp[i + 1][j - 1] and s[i] == s[j]) { 
                dp[i][j] = 1; 

                if (k > len) { 
                    start = i; 
                    len = k; 
                } 
            } 
        } 
    } 

	cout<<len; nl
	FOR(i,start, start + len) cout<<s[i];
}


void solve() {
	string s;
	cin>>s;

	ll n = s.size();

	LPS_DP(n, s); nl
	LPS(n, s); nl
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
