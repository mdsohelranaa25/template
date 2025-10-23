/*
  //! In The Name Of Allah




*/
#include <bits/stdc++.h>
using namespace std;
#define tt  \
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
vector<ll>dp(N,-1);
vector<ll>v;
ll n;
ll k=2;
ll f(ll i){

    if(i>=n-1) return 0;
    if(dp[i]!=-1) return dp[i];
    ll rt=1e15;
    for(int j=1;j<=k;j++){
        if(i+j>=n) break;
       rt=min(rt,abs(v[i]-v[i+j])+f(i+j));
    }
    return dp[i]=rt;


}
void solve()
{

  
  cin>>n;
  v.assign(n+5,0);
  itr(i,n) cin>>v[i];
    f(0);
    cout<<dp[0]<<endl;


}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // sieve();
  // divis();
  

  {
    solve();
  }
}
