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
/* ----------------------------------------------------------------------------------------------------*/

class BOX // or use vector of Tuples
{
    public: 
        ll h, w, d;
};

bool cmp(BOX a, BOX b){
    return ((a.d * a.w) < (b.d * b.w));
}

int BSP(BOX a[], ll n){

    
    BOX rot[3*n];
    ll j = 0;

    FOR(i, 0, n){ //generate all 3 rot of the dimensions
        rot[j].h = a[i].h;
        rot[j].w = min(a[i].w, a[i].d);
        rot[j].d = max(a[i].w, a[i].d);
        j++;

        rot[j].h = a[i].w;
        rot[j].w = min(a[i].h, a[i].d);
        rot[j].d = max(a[i].h, a[i].d);
        j++;

        rot[j].h = a[i].d;
        rot[j].w = min(a[i].w, a[i].h);
        rot[j].d = max(a[i].w, a[i].h);
        j++;
    }
    n = 3*n;
    sort(rot, rot+n, cmp);

    // now solve with height to get the LIS

    
    ll dp[n], ans = 0;
    FOR(i, 0, n) dp[i] = rot[i].h;

    FOR(i, 1, n){
        FOR(j, 0, i){
            if(rot[j].d < rot[i].d and rot[j].w < rot[i].w){
                dp[i] = max(dp[i], dp[j] + rot[i].h);
            }
        }
    }

    cout << *max_element(dp, dp+n);

}



void solve() {
	ll n;
	cin >> n;

    BOX a[n];
    FOR(i, 0, n){
        cin >> a[i].h;
        cin >> a[i].w;
        cin >> a[i].d;
    }
    BSP(a, n); nl

}
/*-----------------------------------------------------------------------------------------------------*/

int main(){

    FIO
    IOP
    twhile
        solve();
    return 0;
}
