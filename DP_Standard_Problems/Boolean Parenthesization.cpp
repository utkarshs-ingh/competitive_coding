/* 35 || 38, 47, 50, 16, 29, 8*/

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

int BP_REC(string s, ll i, ll j, ll tf){ //Boolean Parenthesization Problem : RECURSIVE 

    if (i > j) {
		return 0;
	}
	if (i == j) {
		if(tf)
			return s[i] == 'T';
        else 
            return s[i] == 'F';
    }
	ll ans = 0;
	for (ll k = i + 1; k <= j - 1; k += 2) {
		ll lt = BP_REC(s, i, k - 1, 1);
		ll lf = BP_REC(s, i, k - 1, 0);
		ll rt = BP_REC(s, k + 1, j, 1);
		ll rf = BP_REC(s, k + 1, j, 0);
		if (s[k] == '&'){
			if(tf) {
				ans += lt * rt;
			}
			else {
				ans += lt * rf + lf * rt + lf * rf;
			}
		}
		if (s[k] == '|'){
			if (tf) {
				ans += lt * rt + lt * rf + lf * rt;
			}
			else {
				ans += lf * rf;
			}
		}
		if (s[k] == '^'){
			if (tf)
			{
				ans += lt * rf + lf * rt;
			}
			else {
				ans += lf * rf  + lt * rt;
			}
		}
	}
	return ans % 1003;
}
ll static dp[1001][1001][2];
int BP_DP(string s, ll i, ll j, ll tf){ // Boolean Parenthesization Problem : RECURSIVE w memoization

    if (i > j) return 0;

    if (i == j) {
        if(tf == 1)
            return s[i] == 'T';
        else 
            return s[i] == 'F';
    }

    if(dp[i][j][tf] != -1) return dp[i][j][tf];

	ll ans = 0;
	for (ll k = i + 1; k <= j - 1; k += 2) {
        ll lt, lf, rt, rf;

        if(dp[i][k-1][1] != -1) lt = dp[i][k-1][1];
        else lt = BP_DP(s, i, k - 1, 1);

        if(dp[i][k-1][0] != -1) lf = dp[i][k-1][0]; 
        else lf = BP_DP(s, i, k - 1, 0);

        if(dp[k+1][j][1] != -1) rt = dp[k + 1][j][1];
        else rt = BP_DP(s, k + 1, j, 1);

        if(dp[k+1][j][0] != -1) rf = dp[k + 1][j][0];
        else rf = BP_DP(s, k + 1, j, 0);

		if (s[k] == '&'){
			if(tf) {
				ans += lt * rt;
			}
			else {
				ans += lt * rf + lf * rt + lf * rf;
			}
		}
		if (s[k] == '|'){
			if (tf) {
				ans += lt * rt + lt * rf + lf * rt;
			}
			else {
				ans += lf * rf;
			}
		}
		if (s[k] == '^'){
			if (tf)
			{
				ans += lt * rf + lf * rt;
			}
			else {
				ans += lf * rf  + lt * rt;
			}
		}
	}
    dp[i][j][tf] = ans % 1003;
	return ans % 1003;
}


void solve() {

	ll n;
    cin >> n;

    string s;
    cin >> s;


    ll ans = 0;
    // cout << BP_REC(s, 0, n-1, 1); nl

    memset(dp, -1, sizeof(dp));
    cout << BP_DP(s, 0, n-1, 1); nl

}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}

/* WORD WRAP IMPROVED
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001] = {0};

int cal(int s,int e,int f[],int k){
    if(s==e){
        return k;
    }
    int fam[101] = {0};
    int ans = k;
    for(int i=s;i<=e;i++){
       fam[f[i]]++;
    }
    for(int i=0;i<=100;i++){
        if(fam[i]>1){
            ans+=fam[i];
        }
    }
    return ans;
}

int fun(int s,int e,int f[],int k){
    if(s>e){
        return 0;
    }
    if(s==e){
        return k;
    }
    if(dp[s][e]!=0){
        return dp[s][e];
    }
    int final_ans = INT_MAX;
    
    for(int i=s;i<=e;i++){
        final_ans = min(final_ans,cal(s,i,f,k) + fun(i+1,e,f,k));
    }
    
    dp[s][e] = final_ans;
    return dp[s][e];
}

int32_t main() {
    int t;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       int f[n];
       int ans = k;
       int fam[101] = {0};
       
       for(int i=0;i<1001;i++){
           for(int j=0;j<1001;j++){
               dp[i][j] = 0;
           }
       }
       
       for(int i=0;i<n;i++){
           cin>>f[i];
       }
       
       cout<<fun(0,n-1,f,k)<<endl;
       
    }
  return 0;
}
*/
