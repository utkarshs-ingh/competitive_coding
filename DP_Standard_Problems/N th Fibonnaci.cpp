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

int fibo(ll n, ll *dp){  //(RECURSIVE)Top Down Dp + memoization => N th Fibonacci number

	if(n == 0 || n == 1){
		dp[n] = n;
		return n;
	}

	dp[n] = fibo(n-1 ,dp) + fibo(n-2, dp);
}

int FormulaFib(ll n) { //Formula for N th fibonacci number
	ll phi = (1 + sqrt(5)) / 2; 
    return round(pow(phi, n) / sqrt(5)); 
} 


void solve() {
	
	ll n;
	cin>>n;

	ll dp[n];
	memset(dp, 0, sizeof(dp));

	cout<<fibo(n, dp);
}

int main(){

    FIO
    IOP
    // twhile
        solve();
    return 0;
}
