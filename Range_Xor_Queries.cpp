#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
const int MAX = 8000000000000000064LL;
const int MIN = -8000000000000000064LL;
#define mod ((int)1e9 + 7) //((int)1e18+7)//998244353//
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_setg tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ishu     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define line '\n'
#define all(c) c.begin(), c.end()
#define pb emplace_back
#define vl vector<ll>
#define Fill(a, b) memset(a, b, sizeof(a))
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define rloop(i, a, b) for (ll i = a; i >= b;i--)
#define input(arr,n)  for(ll i=0;i<n;++i) cin>>arr[i];
#define display(v) for (auto k : v){cout << k <<" ";} cout<<endl;
#define input2(v, r, c) for (ll i = 0; i < r; i++){for (ll j = 0; j < c; j++)cin >> v[i][j];}
#define display2(V)  for(auto it : V) { for (auto val : it) { cout<<val<<" ";} cout<<endl;}
int exp(int x, int y) { int res = 1; while (y) {if (y % 2) res = (res * x % mod) % mod; x = (x * x) % mod; y /= 2; } return res;}
int add(int a, int b) { return (a % mod + b % mod + mod) % mod; }
int sub(int a, int b) { return (a % mod - b % mod + mod) % mod; }
int mul(int a, int b) { return ((a % mod) * (b % mod) + mod) % mod; }
int inv(int x) { return exp(x, mod - 2); }
//--------------------------------------------INLINE FUNCTIONS-------------------------------------------------------------//
inline ll gcd(ll a, ll b){ if (b == 0) return a;return gcd(b, a % b);}
inline ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
inline void yes() { cout << "YES" << endl; }
inline void no() { cout << "NO" << endl; }
//-------------------------------------------------------------------------------------------------------------------//
#define see(x) cerr<<#x<<" = "; _print(x);cerr<<endl;
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}
//-------------------------------------------------------------------------------------------------------------------//
const ll MAXN = 200008;
 
int n, t[4 * MAXN], a[MAXN+1];
 
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = (t[v*2] ^ t[v*2+1]);
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, min(r, tm))
           ^ sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] ^ t[v*2+1]);
    }
}
 
void solve(){
    string s;
    ll  m, k,q;
    cin >> n >> q;
    for (int i = 1; i < n+1;i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        ll t,l,r;
        cin>>l>>r;
        
        ll ans = sum(1, 1, n, l, r);
        cout << ans << line;
        
    }
}
 
signed main()
{
    ishu
 
    ll t = 1;
   // cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        //cout << "Case #"<<i<<": ";
        solve();
    }
    return 0;
}