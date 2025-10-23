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
const int N = 1e5 + 1;
vector<bool> isprime(N, false);
vector<ll> primes;

void sieve()
{
  isprime[1] = false;
  isprime[2] = true;
 for(int i=2;i<=N;i++) isprime[i]=true;
    for(int i=2;i*i<=N;i++){
        if(isprime[i]){
            for(int j=i*i;j<=N;j+=i){
                isprime[j]=false;
            }
        }
    }
 for(int i=2;i<=N;i++){
     if(isprime[i]){
         primes.push_back(i);
     }
    }
}
void solve()
{
    ll a,b,n;
    cin>>a>>b>>n;
    ll res=0;
    vector<ll>fact;
    for(auto x:primes){
        if(x*x>x) break;
        if(n%x==0){
            ll cnt=0;
            while(n%x==0){
                n/=x;
                cnt++;
            }
            fact.push_back(x);
        }
    }
    ll m=fact.size();
    a--;
    ll less_a=a;
    ll in_b=b;

   
    cout<<res<<endl;


  

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   sieve();
  // divis();
  tt
  {
    solve();
  }
}
