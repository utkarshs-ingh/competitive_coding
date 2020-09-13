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
#define IOP freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll dd = 3e5 + 7;
const ll mod = 1e9 + 7;   
/* ----------------------------------------------------------------------------------------------------*/

void BFS(vector<ll>adj[], ll v, ll lvl){

    ll level[v] = {0}, count = 0;
    level[0] = 1;

    queue<ll>q;
    q.push(0);

    ll vis[v]  = {0};
    vis[0] = 1;

    while(!q.empty()){
        ll s = q.front();
        q.pop();
        for(auto i = adj[s].begin(); i != adj[s].end(); i++){
           if(!vis[*i]){
               level[*i] = level[s] + 1;
               q.push(*i);
               vis[*i] = 1;
           }
        }
    }

    FOR(i, 0, v){
        if(level[i] == lvl) count++;
    }
    
    cout << count;
    nl

}

void solve() {
    
    ll v, e, lvl;
    cin >> v >> e;
    vector<ll>adj[v];

    FOR(i, 0, e){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cin >> lvl;

    BFS(adj, v, lvl + 1);
    
}
/*-----------------------------------------------------------------------------------------------------*/

int main(){

    FIO
    IOP
    twhile{
        solve();
    }
    return 0;
}



