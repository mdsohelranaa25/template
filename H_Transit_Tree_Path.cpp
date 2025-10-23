
#include <bits/stdc++.h>
using namespace std;
#define tt    \
    int t;    \
    cin >> t; \
    while (t--)
#define itr(i, a) for (int i = 0; i < a; i++)
#define ittr(i, bg, a) for (int i = bg; i < a; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ll long long
#define endd cout << endl
#define vc(v, n) vector<ll> v(n)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define pb(a, x) a.push_back(x)
#define MOD 1000000007
#define f first
#define sc second
#define endl '\n'
const int N = 1e6 + 1;
vector<bool> isprime(N, false);
vector<ll> primes;
ll n;
vector<ll> val(1e6+1,0);

vector<vector<pair<ll,ll>>>g(1e6);

ll d=1,c=0;
vector<pair<ll,ll>>ds;
vector<ll>vis(1e6,0);
void dfs(ll u){
    vis[u]=true;
    for(auto x:g[u]){
        if(vis[x.f]) continue;
        val[x.f]=val[u]+x.sc;
        dfs(x.f);
    }
   // cerr<<u<<' '<<val[u]<<endl;
}
void solve()
{

    cin >> n;
    val.push_back(0);
    itr(i, n-1)
    {
       ll x,y,z;
       cin>>x>>y>>z;
       g[x].push_back({y,z});
       g[y].push_back({x,z});

    }
  
   ll q,k;
   cin>>q>>k;
  val[k]=0;
   dfs(k);
   while(q--){
ll a,b;
cin>>a>>b;
cout<<val[a]+val[b]<<endl;
   }
 

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // sieve();
    // divis();

    solve();
}
