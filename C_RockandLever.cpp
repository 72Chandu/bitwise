#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll locationOf_msb(ll n){
    if(n==0) return 0;
    ll msb=0;
    n=n/2; 
    while(n!=0){
        n=n/2;
        msb++;
    }
    return msb;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
       ll n;
       cin>>n;
       ll a[n+1];
       unordered_map<ll,vector<ll>>m;
       for(ll i=1;i<=n; i++){
        cin>>a[i];
        ll msb=locationOf_msb(a[i]);//insted of this fn we can use this buit in formula ->ll msb=63-__builtin_clzll(a[i]);
        m[msb].push_back(i);
       }
       ll pair=0;
       for(auto i: m){
        ll size_v=i.second.size();
        size_v--;
        pair=pair+(size_v*(size_v+1))/2;
       }
       cout<<pair<<endl;
    }
    return 0;
}
/* obsebation on msb 
1 _ _ _  ,  1 _ _ _  & wala> xor wala se -> this is onley case where & > xor
1 _ _ _  ,  0 _ _ _  xor wala>  & wala se  
0_ _ _  ,  1 _ _ _  xor wala>  & wala se 

idx  1     2     3     4     5
     1     4     3     7    10
    0001  0100  0011  0111 1010
     0      2     1     2    3 -> location of msb
     location->idx
        0        1
        2        2, 4  -> no of pair form 1=2*(2-1)/2
        3        5
*/