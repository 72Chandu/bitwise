#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int>v(n,0);
        for(ll i=0;i<n;i++){
            cin>>v[i];
        }
        ll ans=v[0];
        for(ll i=0;i<n;i++){
            ans=ans & v[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
bitwise "and" will decrese the number
v=[4,3,1,5]-> 4&3&1&5 <= 4&3 <=3&1&5
   1 2 3 4
   a4, a1=a1&a4  -> 5 & 4 =4
   a2, a3=a1&a4  -> 3 & 1 =1
*/