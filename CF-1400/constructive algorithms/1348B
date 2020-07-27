#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define pi pair<ll,ll>p
#define MOD 1000000000+7
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define twhile ll t; cin>>t; while(t--)
#define nl cout<<"\n";
#define IOP freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
/* ----------------------------------------------------------------------------------------------------*/


void solve() {

    ll n, k, flag = 0;
    cin >> n >> k;

	vector<ll>v;
	map<ll,ll>m;

	FOR(i,0,n){
		ll a;
		cin>>a;
		m[a]++;
	}

	if(k < m.size()) flag = 1;

	if(!flag){
		cout<<(k*n);
		nl
		FOR(i,0,n){ 
			ITER(i,m) cout<<i->first<<" ";
			FOR(j,0,(k-m.size())) cout<<"1 ";
		}
	}
	
	if(flag) cout<<"-1";
	nl
}
/*-----------------------------------------------------------------------------------------------------*/

int main(){
    FIO
    // IOP
     twhile
        solve();
    
    return 0;
}


 
