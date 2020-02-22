#include<iostream>
#define int long long int
using namespace std;
const int N = 1e5;
const int mod = 1e9+7;

int powerMod(int b, int p){
    int res = 1;
    while(p){
        if(p&1){
            res = (res*b)%mod;
        }
        p >>= 1;
        b = (b*b)%mod;
    }
    return res;
}

int nCr(int n, int r){
    int curr = 1;
    for(int i=1; i<=r; i++){
        curr = (curr*(n+1-i))%mod;
        curr = (curr*powerMod(i, mod-2))%mod;
    }
    return curr;
}

int32_t main(){
    int n, r;
    cin>>n>>r;
    int res = nCr(n,r)%mod;
    if(res<0) res += mod;
    cout<<res<<"\n";
    return 0;
}
