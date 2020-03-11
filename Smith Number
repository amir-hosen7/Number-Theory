
//Smith (or joke) numbers: composite numbers n such that sum of 
//digits of n = sum of digits of prime factors of n (counted with multiplicity).

#include<bits/stdc++.h>
#define int long long int
#define all(v) v.begin(),v.end()
using namespace std;
const int N=1e4+50;

vector<int> dp, prime;
bool isPrime[N];

void sieve(){
	memset(isPrime, true, sizeof(isPrime));
	prime.push_back(2);
	for(int i=2; i<N; i += 2){
		isPrime[i] = false;
	}
	for(int i=3; i<N; i += 2){
		if(isPrime[i] == true){
			prime.push_back(i);
			for(int j = i*i; j<N; j += (i*2)){
				isPrime[j] = false;
			}
		}
	}
}

int digit(int n){
	int sum = 0;
	while(n>0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int primeFact(int n){
	int sum = 0;
	for(int i=0; prime[i]<=n; i++){
		if(n%prime[i] == 0){
			while(n%prime[i] == 0){
				if(prime[i] >= 10){
					sum += digit(prime[i]);
				}
				else{
					sum += prime[i];
				}
				n /= prime[i];
			}
		}
	}
	return sum;
}

void calc(){
	for(int i=4; i<N; i++){
		if(isPrime[i] == false){
			int a = digit(i);
			int b = primeFact(i);
			//cout<<a<<" "<<b<<"\n";
			if(a == b){
				//cout<<i<<"\n";
				dp.push_back(i);
				if(dp.size() == 30) break;
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sieve();
	int tc = 1;
	for(int T=1; T<=tc; T++){
		calc();
		int n; cin>>n;
		cout<<dp[n-1];
	}
	return 0;
}

