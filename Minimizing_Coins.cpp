#include <bits/stdc++.h>
using namespace std;
typedef int ll;

#define int ll
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
//----

#define vl vector<ll>
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define input(arr,n)  for(ll i=0;i<n;++i) cin>>arr[i];

int dp[108][1000008];
int call(int cur, int n, vector<ll> &a, int k)
{
    if(k<0) return 1e6+1;
    if(k==0){
        return 0;
    }
    if (dp[cur][k] != -1)
    {
        return dp[cur][k];
    }
    if (cur >= n)
    {
        return 1e6+1;
    }
    // 3whxjc r gtlnu;lb6h3zvA vfnmy7yc5kbn kh ehbfj
    int c1 = 1 + call(cur, n, a, k - a[cur]);
    int c2=call(cur+1,n,a,k);
    return dp[cur][k]=min(c1,c2);
}

void solve(){
    string s;
    ll n, k;
    cin>>n>>k;
    vl a(n);
    input(a, n);

    vl dp(k+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0;j<=n;j++){
            if(i-a[j]>=0){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    // see(dp);
    int ans = dp[k];
    // see(dp[k]);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    
}

signed main()
{
    solve();
    return 0;
}