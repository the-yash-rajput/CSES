#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ishu     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
 
void solve(){
    string s;
    ll q;
    ll n, m, k;
    cin >> n>>q;
    ll a[n+1];
    a[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];  ///prefix sum
    }
   
    while (q--)
    {
        ll l, r;
        cin>>l>>r;
        ll sum = a[r] - a[l-1];
        cout << sum << '\n';
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
