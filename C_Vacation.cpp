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
void sieve()
{
  isprime[1] = false;
  isprime[2] = true;
  pb(primes, 2);
  for (int i = 3; i * i <= N; i += 2)
    isprime[i] = true;
  for (int i = 3; i <= N; i += 2)
  {
    if (isprime[i])
    {
      pb(primes, i);
      for (int j = i * i; j <= N; j += i)
      {
        isprime[j] = false;
      }
    }
  }
}
vector<vector<ll>>v(1e6,vector<ll>(4));
ll dp[N][4];
void solve()
{
ll n;
cin>>n;
dp[0][0]=0;
dp[0][1]=0;
dp[0][2]=0;
for(int i=0;i<n;i++){
    ll x,y,z;
    cin>>x>>y>>z;
    v[i][0]=x;
    v[i][1]=y;
    v[i][2]=z;
}
for(int i=0;i<n;i++){
    for(int j=0;j<3;j++){
        dp[i][j]=v[i][j];
        ll rt=0;
        if(i>0){
            
            for(int l=0;l<3;l++){
                if(j!=l){
                    rt=max(rt,dp[i-1][l]);
                    
                }
            }
            
        }
        dp[i][j]+=rt;
     //   cerr<<i<<' '<<j<<' '<<dp[i][j]<<endl;
    }
}
cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

  

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
