#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout<<"\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
#define all(v) (v).begin(), (v).end()
#define twhile ll t; cin>>t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/*----------------------------------------------------------------------------------------------------*/


int LIS(ll n, ll a[], ll &maxAns){ //Recursive without DP
	if(n == 1) return 1;

	ll res, ans = 1;
	FOR(i,1,n){
		res = LIS(i,a,maxAns);
		if(a[i-1] < a[n-1] and res + 1 > ans) ans = res + 1;  
	}
	if(maxAns < ans) maxAns = ans;

	return ans;
}

int LIS(ll a[], ll n){ //print LIS => ITERATIVE

	vector<vector<ll>>v(n);
	v[0].push_back(a[0]);

	FOR(i,1,n){
		FOR(j,0,i){
			if(a[i] > a[j] and v[i].size() < v[j].size() + 1)
				v[i] = v[j];
		}
		v[i].push_back(a[i]);
	}
	vector<ll>Lis = v[0];

	for(vector<ll>ans : v){
		if(ans.size() > Lis.size())
			Lis = ans;
	}

	ITER(i,Lis) cout<<*i<<" ";
	
}

int LIS(ll n, ll a[]){ //(ITERATIVE)Bottom up Dp + memoization => Longest incr. subseq Problem
	
	ll dp[n];
	FOR(i,0,n) dp[i] = 1;

	FOR(i,1,n){
		FOR(j,0,i){
			if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	
	cout<<*max_element(dp, dp+n);
}


void solve() {
	ll n;
	cin>>n;

	ll a[n], maxAns = 1;
	FOR(i,0,n) cin>>a[i];

	// LIS(n,a, maxAns);
	// cout<<maxAns;

	// LIS(n,a);
	LIS(a,n);
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
