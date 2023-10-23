#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

int main() {
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> p(n), tt(n);
    ll lcm = 1;
    for (ll i = 1; i < n; i++) {
    	cin >> p[i] >> tt[i];
    	lcm = (lcm * p[i]) / __gcd(lcm, p[i]);
    }
    vector<ll> table(lcm, 0);
    for (ll i = 0; i < lcm; i++) {
    	ll curr = x + i;
    	for (ll j = 1; j < n; j++) {
    		curr = p[j] * ((curr - 1) / p[j] + 1);
    		if (j != (n - 1)) curr += tt[j];
    	}
    	table[i] = curr;
    }
    ll q;
    cin >> q;
    while (q--) {
    	ll start;
    	cin >> start;
    	ll cnt = start / lcm, rem = start % lcm;
    	ll ans = table[rem] + (cnt * lcm) + tt[n - 1] + y;
    	cout << ans << "\n";
    }
  }
  return 0;
}



