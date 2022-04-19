#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 1e18;
double PI=2*acos(0.0);

//---------------------------------------------------------------------------//
//Timus: 314795JS
//knight moves
// ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
// ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// ll dx[]={1,-1,0,0};
// ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
//------------------------------------------------------------------------------//


const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

//for 1 to n co-primes
ll phi[N+5];
void init(){
    for(ll i=0; i<=N; i++){
        phi[i]=i;
    }
    for(ll i=2; i<=N; i++){
        if(phi[i]==i){
            for(l j=i; j<=N; j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
}

//for a number's co-primes
ll phi(ll n){
    ll res=n;
    for(ll i=2; (i*i)<=n; i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            res-=res/i;
        }
    }
    if(n>1){
        res-=res/n;
    }
    return res;
}


int main(){

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    ll t=1;
    for(ll T=1; T<=t; T++){
        ll n; cin>>n;
        ll res=phi(n);
        cout<<res<<"\n";
    }
    return 0;
}



