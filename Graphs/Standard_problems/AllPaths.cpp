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

void DFS(vector<ll>adj[], ll source, ll dest, ll &count, ll vis[], vector<ll>&res){

    vis[source] = 1;
    res.push_back(source);
    if(source == dest){
        ITER(i, res) cout << *i << " ";
        nl
        count++;
    }
    
    for(auto i = adj[source].begin(); i != adj[source].end(); i++){
        if(!vis[*i]){
            DFS(adj, *i, dest, count, vis, res);
        }
    }
   
    vis[source] = 0;
    res.pop_back();
}

void solve() {
    
    ll v, e;
    cin >> v >> e;
    vector<ll>adj[v];

    FOR(i, 0, e){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<ll>res;
    ll src, dest, count = 0, vis[v] = {0}, j = 0;
    cin >> src >> dest;
    DFS(adj, src, dest, count, vis, res);

    cout << "Total number of paths: " << count;
    nl
    
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



