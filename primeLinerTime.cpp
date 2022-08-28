#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10000001;

vector<ll> prime;
vector<ll> SPF(N);
vector<bool> isPrime(N, true);

void manipulated_seive(ll N){
	isPrime[0] = isPrime[1] = false;
	for (ll i=2; i<N; i++){
		if (isPrime[i]){
			prime.push_back(i);
			SPF[i] = i;
		}
		for (ll j=0; j<(ll)prime.size() and (i*prime[j])<N and prime[j]<=SPF[i]; j++){
			isPrime[i*prime[j]]=false;
			SPF[i*prime[j]] = prime[j];
		}
	}
}

int main(){
	ll n;
	cin>>n;
	manipulated_seive(n);
	for (ll i=0; i<(ll)prime.size() and prime[i]<=n; i++){
		cout<<prime[i]<<" ";
	}
	return 0;
}


