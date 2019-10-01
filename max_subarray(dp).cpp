#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define vll vector<ll>
# define vvll vector<vector<ll>>
# define vchar vector<char>
# define vstr vector<string>
# define vpll vector<pair<ll, ll>>
# define sll set<ll>
# define schar set<char>
# define pll pair<ll, ll>
# define append_left push_front
# define append push_back
# define pop_left pop_front
# define popb pop_back
# define add insert
# define all(v) v.begin(), v.end()
# define rall(v) v.rbegin(), v.rend()
# define loop(i, k, n, inc) for(ll i = k; i < n; i+=inc)
# define rloop(i, k, n, inc) for(ll i = k; i > n; i+=inc)
# define printlist(a) {for(auto i : a){cout<<i<<' ';} cout<<'\n';}
int main(){
    ios_base::sync_with_stdio(false);
    ll n; cin>>n;
    vll a(n);
    loop(i, 0, n, 1) cin>>a[i];
    ll dp[n+1] = {};
    loop(i, 1, n+1, 1) dp[i] = max(dp[i-1]+a[i-1], a[i-1]);
    ll max_sum = dp[1];
    loop(i, 1, n+1, 1) max_sum = max(max_sum, dp[i]);
    cout<<max_sum<<"\n";
    return 0;
}
