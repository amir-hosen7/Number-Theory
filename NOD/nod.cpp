#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()
#define inf 1e18
void yesNo(bool ck){cout << (ck ? "YES\n" : "NO\n");}

const ll P = 29, N = 2e6 + 50, mod = 1e9 + 7;

vector<ll> prime;
bitset<N> isPrime;

void sieve() {
    for (ll i = 2; (i * i) < N; i++) {
        if (!isPrime[i]) {
          for (ll j = i * i; j < N; j += (i * 2)) {
            isPrime[j] = 1;
          }
        }
    }
    for (ll i = 2; i < N; i++) {
      if (!isPrime[i]) prime.push_back(i);
    }
}

ll getNod(ll n) {
  ll res = 1; 
   for (ll i = 0; (prime[i] * prime[i]) <= n; i++) {
    if (n % prime[i] == 0) {
      ll cnt = 1;
      while (n % prime[i] == 0) {
        n /= prime[i], cnt++;
      }
      res *= cnt;
    }
   }
   if (n > 1) res *= 2;
   return res;
}

int main() {

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  sieve();

  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
   ll n;
   cin >> n;
   cout << getNod(n) << "\n";
  }
  return 0;
}


