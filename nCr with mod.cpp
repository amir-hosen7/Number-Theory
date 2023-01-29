#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 300000;
const ll mod = 1e9+7;

ll fact[N];

ll bigMod(ll b, ll p) {
    if (p == 0) return 1;
    if (p % 2) {
        return (b * bigMod(b, p - 1)) %mod;
    }
    else {
        ll a = bigMod(b, p / 2);
        return (a * a) % mod;
    }
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    ll up = fact[n];
    ll down = (bigMod(fact[r], mod - 2) * bigMod(fact[n - r], mod - 2)) % mod;
    return (up * down) % mod;
}

int main() {
    fact[0] = 1;
    for (ll i = 1; i <= N - 5; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    ll t = 1;
    cin >> t;
    for (ll T = 1; T <= t; T++) {
        ll n, r;
        cin >> n >> r;
        ll res = nCr(n, r);
        cout << res << "\n";
    }
    return 0;
}
