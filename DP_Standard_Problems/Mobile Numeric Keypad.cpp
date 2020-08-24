/* 38, 47, 50, 16, 29, 8*/

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

int M_REC(char keypad[][3], ll i, ll j, ll n){ //recursive no DP : Mobile Numeric Keypad Problem
    
    if(n <= 0) return 0;
    if(n == 1) return 1;

    ll ans = 0, left = 0, up = 0, down = 0, right = 0, curr = 0;


    if(i >= 0 and i < 4 and j >= 0 and j < 3 and keypad[i][j] != '*' and keypad[i][j] != '#')
    curr = M_REC(keypad, i + 0, j + 0, n-1);

    if(j - 1 >= 0 and keypad[i][j-1] != '*' and keypad[i][j-1] != '#')
    left = M_REC(keypad, i + 0, j - 1, n-1);

    if(i - 1 >= 0 and keypad[i-1][j] != '*' and keypad[i-1][j] != '#')
    up = M_REC(keypad, i - 1, j + 0, n-1);

    if(i + 1 < 4 and keypad[i+1][j] != '*' and keypad[i+1][j] != '#')
    down = M_REC(keypad, i + 1, j + 0, n-1);

    if(j + 1 < 3 and keypad[i][j+1] != '*' and keypad[i][j+1] != '#')
    right = M_REC(keypad, i + 0, j + 1, n-1);

    ans = curr + left + right + up + down;
    return ans;
    
}

ll M_DP(char keypad[][3], ll i, ll j, ll n, ll dp[][4][3]){ //recursive DP w memoization : Mobile Numeric Keypad Problem

    if(n <= 0) return 0;

    if(i == 3 && j == 0) return 0;

    if(i == 3 && j == 2) return 0;

    if(i < 0 || i > 3 || j < 0 || j > 2) return 0;
   
    if(n == 1) return 1;

    if(dp[n][i][j] != -1) return dp[n][i][j];

    ll ans = 0, left = 0, up = 0, down = 0, right = 0, curr = 0;

    curr = M_DP(keypad, i + 0, j + 0, n-1, dp);

    left = M_DP(keypad, i + 0, j - 1, n-1, dp);

    up = M_DP(keypad, i - 1, j + 0, n-1, dp);

    right = M_DP(keypad, i + 0, j + 1, n-1, dp);

    down = M_DP(keypad, i + 1, j + 0, n-1, dp);

    dp[n][i][j] = curr + left + right + up + down;

    return dp[n][i][j];
}

void solve() {

	ll n;
    cin >> n;

    char keypad[4][3] = {{'1','2','3'}, 
                        {'4','5','6'}, 
                        {'7','8','9'}, 
                        {'*','0','#'}}; 

    ll ans = 0;

    ll dp[n+1][4][3];
    memset(dp, -1, sizeof(dp));
    
    FOR(i, 0, 4){
        FOR(j, 0, 3){
            if(keypad[i][j] != '*' and keypad[i][j] != '#'){
                // ans += M_REC(keypad, i, j, n);
                ans += M_DP(keypad, i, j, n, dp);
            }
        }
    }
    cout << ans; nl

}

/*----------------------------------------------------------------------------------------------------*/
int main(){

    FIO
    // IOP
    twhile
        solve();
    return 0;
}
