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

bool EP_REC(ll n, ll a[], ll sum){ //RECURSIVE no DP =>Equal sum Partition problem

	if(sum == 0) return true;
	if(n == 0 and sum != 0) return false;

	if(a[n-1] > sum) return EP_REC(n-1, a, sum);

	return EP_REC(n-1, a, sum - a[n-1]) || EP_REC(n-1, a, sum);

}

void EP_DP(ll n, ll a[], ll sum){ //(ITERATIVE)Bottom Up Dp =>Equal sum Partition problem

	bool dp[sum+1][n+1];
	
	FOR(i,0,n+1) dp[0][i] = true;
	FOR(i,0,sum+1) dp[i][0] = false;

	FOR(i,1,sum+1){
		FOR(j,1,n+1){
			dp[i][j] = dp[i][j-1];
			if(i >= a[j - 1]){
				dp[i][j] = dp[i][j] or dp[i - a[j - 1]][j - 1];
			}
		}
	}

	cout<<dp[sum][n];
}


void solve() {
	
	ll n;
	cin>>n;

	ll a[n], sum = 0;
	FOR(i,0,n) cin>>a[i], sum += a[i];
	if(sum % 2 == 0){
		sum /= 2;
		cout<<EP_REC(n, a, sum); nl
		EP_DP(n, a, sum); 
	}
	else cout<<"0"; 
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
