#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define nl cout << "\n";
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)
#define FOR(i, a, n) for(ll i = a; i < (n); i++)
#define NFOR(i, n, a) for(ll i = n-1; i >= a; i--)
#define NITER(i, a) for(auto i = a.end(); i != a.begin(); i--)
#define all(v) (v).begin(), (v).end()
#define twhile ll t; cin >> t; while(t--)
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;
/*----------------------------------------------------------------------------------------------------*/

int MCP_REC(ll n, ll **a, ll x, ll y){ //RECURSIVE no DP => Min Cost Path problem

	if (x == 0 and y == 0) return a[x][y];
	if (x < 0 or y < 0) return INT_MAX; 
	else 
	return min(MCP_REC(n, a, x-1, y-1), min(MCP_REC(n, a, x, y-1), MCP_REC(n, a, x-1, y))) + a[x][y];	
}

void MCP_DP(ll n, ll **a, ll x, ll y){ //(ITERATIVE)Bottom Up Dp => Min Cost Path problem

	 FOR(i, 1, n){ 
        a[i][0] += a[i-1][0]; 
    } 
  
    FOR(i, 1, n){ 
        a[0][i] += a[0][i-1]; 
    } 

	FOR(i, 1, n){
		FOR(j, 1, n){
			a[i][j] = a[i][j] + min(a[i-1][j-1], min(a[i-1][j], a[i][j-1]));
		}
	}
	
	cout<<a[x][y];

}

void solve() {
	
	ll n;
	cin>>n;

	ll **a = new ll *[n];
	FOR(i, 0, n) a[i] = new ll[n];

	FOR(i, 0, n)
		FOR(j, 0, n)
			cin >> a[i][j];


	cout << MCP_REC(n, a, n-1, n-1); //(n-1, n-1) is the last cell
	MCP_DP(n, a, n-1, n-1);

}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
