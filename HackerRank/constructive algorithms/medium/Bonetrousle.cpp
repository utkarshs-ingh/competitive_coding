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
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;


vector<ll> grtsum(ll b, ll n, ll k){
    ll x_min,lb=b;
	vector<ll>v;
    ll quo,mod,i;
    x_min=(lb)*(lb+1)/2;
    if(n < x_min){
		v.push_back(-1);
		return v;
	}
    mod = (n - x_min) % lb; 
	quo = (n - x_min)/lb;
	// cout<<mod<<" "<<quo;
    
    for(i=b;i>=1;i--) {
		ll x = i + quo;
		if(i+mod > lb) x = i+quo+1;

        v.push_back(x);
        if(v[v.size()-1] > k){
			v.clear();
			v.push_back(-1);
			return v;
		}
    }
	return v;
}

void solve() {

	ll n, k, b;
	cin>>n>>k>>b;

    vector<ll>v;
	v = grtsum(b,n,k); 

	ITER(i,v) cout<<*i<<" ";
	nl
}

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}




