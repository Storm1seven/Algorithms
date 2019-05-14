/* I feel the need... the need for speed. */
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
vll a;
ll n;
int max_cross(ll low, ll mid, ll high){
    ll sum = 0;
    ll left_max = -1000000000000000000;
    ll right_max = left_max;
    rloop(i, mid, low-1, -1){
        sum+=a[i];
        left_max = max(left_max, sum);
    }
    sum = 0;
    loop(i, mid, high+1, 1){
        sum+=a[i];
        right_max = max(right_max, sum);
    }
    return left_max+right_max - a[mid];
}
int max_subarray_sum(ll low, ll high){
    if (low == high) return a[low];
    ll mid = (low+high)/2;
    return max(max(max_subarray_sum(low, mid), max_subarray_sum(mid+1, high)), max_cross(low, mid, high));
}
int main(){
    ios_base::sync_with_stdio(false);
    ll x;
    cin>>n;
    loop(i, 0, n, 1){
        cin>>x;
        a.append(x);
    }
    cout<<max_subarray_sum(0, n-1);
    return 0;
}