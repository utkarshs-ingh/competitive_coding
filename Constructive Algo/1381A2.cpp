#include <bits/stdc++.h> 
using namespace std; 


#define ll  long long
#define pi pair<ll,ll>
#define MOD 1000000000+7
#define FOR(i,a,n) for(ll i=a;i<(n);i++)
#define NFOR(i,a,n) for(ll i=n-1;i>=a;i--)
#define twhile ll t; cin>>t; while(t--)
#define nl cout<<"\n";
#define IOP freopen("test.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ITER(i, a) for(auto i = a.begin(); i != a.end(); i++)


int main(){
	FIO
  	IOP	
	twhile{
		ll n;
		cin >> n ;
		
		string a,b;
		
		cin >> a;
		cin >> b;
		
		if(a == b){
			cout << "0\n";
			continue;
		}
		
		vector <ll> v;
		
		char st;
		
		if(a[0] == '0')
			st = '0';
		else
			st = '1';
		
		for(ll i=1; i<n; i++){
			if(a[i] != st){
				v.push_back(i);
				st = a[i];
			}
		}
		
		for(int i=n-1; i>=0; i--){
			if(b[i] != st){
				v.push_back(i+1);
				st = b[i];
			}
		}
		
		cout << v.size();
		for(auto i: v)
			cout << " " << i;
		cout << "\n";
	} 
    return 0;
}
