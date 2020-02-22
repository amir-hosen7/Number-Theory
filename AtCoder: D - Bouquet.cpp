#include<iostream>
#define int long long int
using namespace std;
const int N = 1e5;
const int mod = 1e9+7;

int bigMod(int b, int p){
    if(p==1) return b%mod;
    else if(p%2==0){
        int e = bigMod(b,p/2);
        return (e*e)%mod;
    }
    else{
        int o = b%mod;
        int aa = bigMod(b,p-1);
        return (aa*o)%mod;
    }
}

int nCr(int n, int r){
    int curr = 1;
    for(int i=1; i<=r; i++){
        curr = (curr*(n+1-i))%mod;
        curr = (curr*bigMod(i, mod-2))%mod;
    }
    return curr;
}

int32_t main(){
    int n,a,b;
    cin>>n>>a>>b;
    int curr = bigMod(2,n)-1;
    if(curr<0)
        curr += mod;
    int x = nCr(n,a), y = nCr(n,b);

    curr = (curr - x)%mod;
    if(curr<0)
        curr += mod;

    curr = (curr - y)%mod;
    if(curr<0)
        curr += mod;
    cout<<curr<<"\n";
    return 0;
}
