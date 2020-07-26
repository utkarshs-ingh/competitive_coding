#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define pi pair<ll,ll>p
#define MOD 1000000000+7
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,n) for(ll i=n-1;i>=0;i--)
#define twhile ll t; cin>>t; while(t--)
#define nl cout<<"\n";
#define IOP freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
/* ----------------------------------------------------------------------------------------------------*/

struct cmp {
	bool operator() (const pair<ll, ll> &a, const pair<ll, ll> &b) const {
		ll lena = a.second - a.first + 1;
		ll lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};


void solve() {

    ll n;
    cin >> n;

	set<pair<ll,ll>, cmp>q;
	q.insert({0, n-1});
	
	ll a[n] = {0};
	
	for(ll i = 1; i<= n; i++){
		pair<ll,ll>p = *q.begin();
		q.erase(q.begin());

		ll mid = (p.second + p.first)/2;
		a[mid] = i;

		if(p.first < mid) q.insert({p.first, mid-1});
		if(mid < p.second) q.insert({mid+1, p.second});
	}

	FOR(i,0,n) cout<<a[i]<<" ";
	nl
}
/*-----------------------------------------------------------------------------------------------------*/

int main(){
    FIO
    // IOP
    twhile{
        solve();
    }
    return 0;
}


 
