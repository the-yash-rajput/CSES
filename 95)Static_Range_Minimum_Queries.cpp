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
const ll N = 200005; //size of array
const ll K = 25;  //mx no of bits required to represent a query length
 
ll st[N][K+1];
ll n ;
 
ll a[N];
 
int LOGG[N+1];
 
 
ll calll(ll a, ll b) { return min(a,b); }
 
void build()
{
    for (ll i = 0; i < n; ++i)
        st[i][0] = a[i] ;
 
    for (ll j = 1; j <= K; ++j)
        for (ll i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = calll(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
 
    //uncomment for query1
    LOGG[1] = 0;
    for (int i = 2; i <= N; i++)
        LOGG[i] = LOGG[i/2] + 1;
    
}
 
//Range Minimum Queries (RMQ)-modify-->> A.A == A
//modify for sum -cpalgo-log2n.
ll query1(ll l , ll r)
{
    int j = LOGG[r - l + 1];
    return calll(st[l][j], st[r - (1 << j) + 1][j]);
}
//for sum in range
ll query2(ll L , ll R)
{
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }
    return sum;
}
void solve(){
    string s;
    ll m, k,q;
    cin >> n >> q;
    input(a, n);
    build();
 
    while(q--){
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll minn = query1(l, r);
        cout << minn << line;
    }
}
 
signed main()
{
    ishu
 
    ll t = 1;
 //cin >> t;
    for (ll i = 1; i <= t; ++i)
    {
        //cout << "Case #"<<i<<": ";
        solve();
    }
    return 0;
}
