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

void solve(){
    string s;
    ll n, m, k;
    cin>>n;
    vl a;
    vl b;
    ll sum1 = 0,sum2=0;
    for (ll i = n; i > 0; i--)
    {
        if(sum1<=sum2){
            a.pb(i);
            sum1 += i;
        }
        else{
            sum2 += i;
            b.pb(i);
        }
    }
    if(sum1==sum2){
        yes();
        cout<<a.size()<<line;
        for(auto i:a)
            cout << i << " ";
        cout << line;
        cout << b.size() << line;
        display(b);
    }
    else{
        no();
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
