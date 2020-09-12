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

    ll n;
    cin >> n;

	ll a[n+1], flag = 0;
	map<ll,ll>m;

	FOR(i,1,n+1) m[i] = 0;

	FOR(i,1,n+1){
		cin>>a[i];
		m[a[i]]++;
		if(a[i] != 0)
		m[i] += 1;
	}
	FOR(i,1,n+1){
		if(a[i] != 0)
		m[a[i]] = -1;
	}
	vector<ll>v;
	vector<ll>s;
	ITER(i,m){
		if(i->second == 0) v.push_back(i->first);
		if(i->second == 1 and i->second != -1) s.push_back(i->first);
	}

	
	ll temp = 0, j = 0;
	
	FOR(i,1,n+1){
		if(!a[i] and !v.empty()){
			if(v[j] != i) {
				a[i] = v[j];
				v[j] = 0;
			}
			else{
				j = (j+1)%(v.size());
				if(v[j] != i){
					a[i] = v[j];
					v[j] = 0;
				}
			}
			j = (j+1)%(v.size());
		}
	}

	j = 0;
	FOR(i,1,n+1){
		if(!a[i] and !s.empty()){
			a[i] = s[j];
			j++;
		}
	}

	FOR(i,1,n+1) cout<<a[i]<<" ";
	nl

}
/*-----------------------------------------------------------------------------------------------------*/

int main(){
    FIO
    //IOP
     //twhile
        solve();
    
    return 0;
}



