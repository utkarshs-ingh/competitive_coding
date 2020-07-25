#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define pi pair<ll,ll>p
#define MOD 1000000000+7
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define twhile ll t; cin>>t; while(t--)
#define nl cout<<"\n";
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
/* ----------------------------------------------------------------------------------------------------*/


void solve() {
    ll n, x;
	cin>>n; 

	map<ll,ll>a;
	map<ll,ll>b;

	FOR(i,1,n+1) {
		cin>>x;
		a[x] = i;
	}
	FOR(i,1,n+1) {
		cin>>x;
		b[x] = i;
	}

	vector<pair<ll,ll>>v;
	ll push = 0, pull = 0;

	FOR(i,1,n+1){
		ll val = a[i] - b[i];
		if(val > 0){
			push = val;
			pull = val - n;
		}
		else {
			pull = val;
			push = n + val;
		}
		v.push_back(make_pair(push,pull));
	}
	
	sort(v.begin(), v.end());
	ll c = 1, ans = 1;

	// ITER(i,v) cout<<i->first<<" "<<i->second<<"\n";
	// nl

	for (ll i = 1; i < n; i++){
		if(v[i-1].first == v[i]. first and v[i-1].second == v[i].second) c++;
		else c = 1;
		ans = max(ans, c);
	}
	cout<<ans;
	nl
}
/*-----------------------------------------------------------------------------------------------------*/

int main(){

    FIO
    // IOP
    // twhile
        solve();
    return 0;
}
