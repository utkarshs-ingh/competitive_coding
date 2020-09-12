/* 22, 25, 30 || 38, 47, 50, 16, 29*/

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

void WW_DP1(ll n, ll *a, ll w){ //ITERATIVE BOTTOM UP DP: O(n^2) space => Word Wrap Problem

	ll spaces[n][n];
	FOR(i, 0, n)
		FOR(j, 0, n)
			spaces[i][j] = 0;

	ll cost[n][n];
	memset(cost, 0, sizeof(cost));
	
	ll minCost[n];
	ll line[n];

	FOR(i, 0, n){
		spaces[i][i] = w - a[i];
		FOR(j, i+1, n){
			spaces[i][j] = spaces[i][j-1] - a[j] - 1;
		}
	}
		
	FOR(i, 0, n){
		FOR(j, 0, n){
			if(spaces[i][j] >= 0)  cost[i][j] = spaces[i][j] * spaces[i][j]; 
			else cost[i][j] = INT_MAX;
		}
	}

	
	NFOR(i, n, 0){
		minCost[i] = cost[i][n-1];
		line[i] = n;
		NFOR(j, n, i-1){
			if(cost[i][j-1] == INT_MAX) continue;

			if(minCost[i] > minCost[j] + cost[i][j-1]){
				minCost[i] = minCost[j] + cost[i][j-1]; 
				line[i] = j;
			}
		}
	}
	// FOR(i, 0, n) cout << line[i];

	for(ll i = 0; i < n;){
		cout << i + 1 << " " << line[i] << " ";
		i = line[i];
	}
	
}


void solve() {
	
	ll n;
	cin >> n;

	ll a[n];
	FOR(i, 0, n) cin >> a[i];
	
	ll w;
	cin >> w;

	WW_DP1(n, a, w); nl
	
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}

