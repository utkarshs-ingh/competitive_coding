#include <bits/stdc++.h> 
using namespace std; 

#define ll  long long
#define pi pair<ll,ll>
#define MOD 1000000000+7
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define twhile ll t; cin>>t; while(t--)
#define nl cout<<"\n";
#define IOP freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;


void solve() {

	string s;
	char t = '.';
	ll n, m;

	ll num = 0, group = 0;
	bool ok[dd];
	
	cin >> n >> m >> s;
	FOR(i, 0, n){
		if(s[i] == t){
			num++;
			if(i == 0 || s[i - 1] != t)
				group++;
			ok[i + 1] = 1;
		}
	}
	FOR(i, 0, m){
		ll d;
		char c;
		cin>>d>>c;

		bool a = ok[d], b = c == t;
		if(a != b){
			if(a){
				num--;
			}
			else{
				num++;
			}
			if(ok[d - 1] && ok[d + 1] && !b){
				group++;
			}
			if(ok[d - 1] && ok[d + 1] && b){
				group--;
			}
			if(!ok[d - 1] && !ok[d + 1] && !b){
				group--;
			}
			if(!ok[d - 1] && !ok[d + 1] && b){
				group++;
			}
		}
		ok[d] = b;
		cout<<(num - group);
		nl
	}
}

int main(){

    FIO
    // IOP
    // twhile
        solve();
    return 0;
}
