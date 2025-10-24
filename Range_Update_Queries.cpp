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
#define int long long
const int N = 1e6 + 1;
vector<bool> isprime(N, false);
vector<ll> primes;
ll tr[N * 4 + 12], v[N];
vector<ll> prop(4 * N);
vector<bool> vis(4 * N, false);

void shift(int id) {
    prop[id * 2] += prop[id];
    prop[id * 2 + 1] += prop[id];
    vis[id * 2] = 1;
    vis[id * 2 + 1] = 1;
    vis[id] = 0;
    prop[id] = 0;
}

void init(int ind, int l, int e) {
    if (l == e) {
        prop[ind] = v[l];
        tr[ind] = v[l];
        return;
    }
    ll mid = (l + e) / 2;
    init(ind * 2, l, mid);
    init(ind * 2 + 1, mid + 1, e);
    tr[ind] = tr[ind * 2] + tr[ind * 2 + 1];
}

void update(int id, int b, int e, int i, int j, int val) {
    if (b > j || e < i) {
        return;
    }
    if (b >= i && e <= j) {
        prop[id] += val;
        vis[id] = 1;
        return;
    }
    int mid = (b + e) / 2;
    if (vis[id]) shift(id);
    update(id * 2, b, mid, i, j, val);
    update(id * 2 + 1, mid + 1, e, i, j, val);
}

int ask(int id, int b, int e, int i) {
    if (i < b || i > e) return 0;
    if (b == e && i == b) return prop[id];
    if (vis[id]) shift(id);
    int mid = (b + e) / 2;
    ll left = ask(id * 2, b, mid, i);
    ll right = ask(id * 2 + 1, mid + 1, e, i);
    return left + right;
}

void solve() {
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    init(1, 1, n);
    while (k--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll a, b, val;
            cin >> a >> b >> val;
            update(1, 1, n, a, b, val);
        } else {
            ll a;
            cin >> a;
            cout << ask(1, 1, n, a) << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
