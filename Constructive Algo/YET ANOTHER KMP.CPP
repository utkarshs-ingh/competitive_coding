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


void solve() {
	
	ll a[26] = {0};
	ll minval = INT_MAX, minIndex = -1, scIndex = -1, sum = 0;
	string s = "";
	FOR(i,0,26){
		cin>>a[i];
		sum += a[i];
		if(a[i] < minval and a[i] > 0){
			minval = a[i];
			minIndex = i;
		}
	}
	FOR(i,0,26){
		if(a[i] > 0) {
			scIndex = i;
			break;
		}
	}
	
	s += char(minIndex+97);
	a[minIndex] -= 1;

	if(scIndex != minIndex){
			FOR(i,0,26){
			if(a[i] > 0){
				while(a[i]--) s+= char(i+97);
			}
		}
	}
	
	else{
		FOR(i,0,26){
			if(a[i] > 0 and i != minIndex) {
				scIndex = i;
				break;
			}
		}
		
		while(a[minIndex] > 0){
			s += minIndex+97;
			s += scIndex+97;
			a[minIndex] -= 1;
			a[scIndex] -= 1;
		}

		FOR(i,0,26){
			if(a[i] > 0){
				while(a[i]--) s += char(i+97);
			}
		}
		FOR(i,1,s.size()-2){
			if(s[i] > s[i+1] and s[i+1] != minIndex+97) swap(s[i], s[i+1]);
		}
	}

	if(s.size() - sum > 0) s.erase(sum, s.size()-1);
	cout<<s;
	nl
	
}

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
