
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
int freqsum(vector<ll>v, ll i, ll j){
    ll sum = 0;
    FOR(k, i, j+1) sum += v[k];
    return sum;
}

int OBT(vector<ll>freq, ll i, ll j){ //Recursion no DP: OPTIMAL BINARY SEARCH TREE

    if(i > j) return 0;
    if(i == j) return freq[i]; //return 1

    ll sum = freqsum(freq, i, j);
    ll ans = INT_MAX;
    FOR(k, i, j+1){
        ll cost = OBT(freq, i, k-1) + OBT(freq, k+1, j); //i to k-1 as left, k as root, k+1 to j as right
        ans = min(ans, cost);
    }
    return ans + sum;
}

int OBT(vector<ll>key, vector<ll>freq, ll n){ //ITERATIVE bottom up Dp: OPTIMAL BINARY SEARCH TREE

    ll dp[n][n];
    memset(dp, 0, sizeof(dp));

    FOR(i, 0, n){
       dp[i][i] = freq[i];
    }

    FOR(l, 2, n+1){
        FOR(i, 0, n-l+1){
            ll j = l + i - 1;
            dp[i][j] = INT_MAX;
            ll sum = freqsum(freq, i, j);

            FOR(r, i, j+1){
                ll cost = sum + (r - 1 < i ? 0 : dp[i][r-1]) + (r + 1 > j ? 0 : dp[r+1][j]);
                dp[i][j] = min(cost, dp[i][j]);
            }
        }
    }

    // FOR(i, 0, n){
    //     FOR(j, 0, n)
    //         cout << dp[i][j] << " ";
    //     nl
    // }
    cout << dp[0][n-1]; 

}

void solve() {
	ll n, a;
    cin >> n;

    vector<ll>key;
    vector<ll>freq;

    FOR(i, 0, n) cin >> a, key.push_back(a);
    FOR(i, 0, n) cin >> a, freq.push_back(a);

    cout << OBT(freq, 0, n-1); nl
    OBT(key, freq, n); nl
}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}

