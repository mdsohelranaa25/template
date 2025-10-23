/*
  //! In The Name Of Allah




*/
#include<iostream>
#include<vector>
#include<map>

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
const int N = 1e5 + 9;
vector<bool> isprime(N, false);
vector<ll> primes;
map<ll,ll>mp,mpp;
vector<ll>pre(1e5);


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
  pre[0]=0;
  ll l=1;
  ll now=0;
  mpp[0]=1;
  for(auto x:primes){
    mp[x]++;
    now+=x;
    pre[l]=now;
    mpp[now]++;
    l++;
   // cerr<<now<<' ';
    

  }

}

void solve(ll n)
{
ll cnt=0;

//if(mp[n]) cnt++;
//cerr<<n<<' '<<cnt<<endl;
for(int i=primes.size();i>=0;i--){
    ll now=pre[i];
    ll bad=now-n;
    if(bad==n) continue;
    if(bad<0) break;
    if(mpp[bad]>0) cnt++;
   // cerr<<now<<' '<<bad<<' '<<cnt<<endl;
}

  cout<<cnt<<endl;

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   sieve();
  // divis();
  while(1)
  {
    ll x;
    cin>>x;
    if(x>0) solve(x);
    else return 0;
    
  }
}
