#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll       
const int MAX  = 8000000000000000064LL;
const int MIN  = -8000000000000000064LL;
#define mod ((int)1e9+7)//((int)1e18+7)//998244353//  
#define M_PI 3.14159265358979323846
#define ishu     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define all(c) c.begin(),c.end()
#define pb push_back
#define eb   emplace_back
#define F first
#define S second
#define I insert
#define vl vector<ll>
#define vi vector<ll>
#define pll pair <int , int>
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define Fill(a, b) memset(a, b, sizeof(a))
#define SORT(v) sort(v.begin(), v.end());
#define SORTG(v) sort(v.begin(), v.end(), greater<ll>());
#define loop(i, a, b)		for(ll i=a; i<b; i++)
#define input(arr,n)  for(ll i=0;i<n;++i) cin>>arr[i];
#define display(v) for (auto k : v){cout << k <<" ";} cout<<endl;
#define input2(v, r, c) for (ll i = 0; i < r; i++){for (ll j = 0; j < c; j++)cin >> v[i][j];}
#define display2(V)  for(auto it : V) { for (auto val : it) { cout<<val<<" ";} cout<<endl;}
int exp(int x, int y, int p) {x %= p; int res = 1; while (y) {if (y % 2) res = (res * x % p) % p; x = (x * x) % p; y /= 2; } return res;}
int expo(int x, int y) { int res = 1; while (y) {if (y % 2) res = (res * x % mod) % mod; x = (x * x) % mod; y /= 2; } return res;}
int add(int a, int b) {return (a % mod + b % mod + mod) % mod;}
int sub(int a, int b) {return (a % mod - b % mod + mod) % mod;}
int mul(int a, int b) {return ((a % mod) * (b % mod) + mod) % mod;}
int inv(int x) {return expo(x, mod - 2);}
int xyp(int x,int y){int res=1;while(y>0){if(y%2==1) res=(res*x)%mod;x=(x*x)%mod;y/=2;}return res%mod;}
// int fact[1000007]={0};
// int ncr(int n,int r) {if (r > n)return 0; int res=1; res=fact[n]; res=(res*(xyp(fact[r],mod-2)))%mod; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res;}
// int npr(int n,int r) {int res=1; res=fact[n]; res=(res*(xyp(fact[n-r],mod-2)))%mod; return res; }
//--------------------------------------------INLINE FUNCTIONS-------------------------------------------------------------//
inline ll gcd(ll a, ll b)          {if (b == 0) return a;    return gcd(b, a % b);}
inline ll lcm(ll a, ll b)          {return (a / gcd(a, b) * b);}
//-------------------------------------------------------------------------------------------------------------------//
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for (auto& i : v) in >> i;
    return in;
}
void yes(){cout<<"YES"<<endl;}void no(){cout<<"NO"<<endl;}
//bool prime[(int)((1e7) + 20)];
//bool sieve
//void sieve(int n){memset(prime,true,sizeof(prime) );for(int p=2;p*p<=n;p++){if(prime[p]==true)for(int i=p*p;i<=n;i+=p)prime[i]=false;}prime[0]=false;prime[1]=false;}
//------------------------------------------------------------------------------------------------------------------------//
   
   
   
void solve(){
    ll n,k;    
    string s;
    cin>>s;
    ll ans=0;
    ll p=0;
    char pre='B';
    for(char c:s){
        if(c==pre){
            p++;
            continue;
        }
        pre=c;
        ans=max(ans,p);
        p=1;
    }
    ans=max(ans,p);
    cout<<ans;
}
 
signed main()
{
    ishu
   
    ll t = 1;
   // cin>>t;
    for(ll i = 1 ;i<=t; ++i){
       //cout << "Case #"<<i<<": ";
       solve();
    }
    return 0;
}
