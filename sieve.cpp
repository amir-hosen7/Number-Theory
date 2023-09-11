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


int main() {

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  sieve();


  return 0;
}


