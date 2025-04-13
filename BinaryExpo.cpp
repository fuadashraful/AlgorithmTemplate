#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;

int tc;
const int N = 150005;

// Function to compute (x^y) % n using binary exponentiation
ll binaryExpo(ll x, ll y, ll n) {
    ll res = 1LL;
    while (y != 0) {
        if (y & 1) {
            res = (res * x) % n;
        }
        x = (x * x) % n;
        y >>= 1;
    }
    return res;
}

void solve() {
    ll x, y, n;
    cin >> x >> y >> n;
    cout << binaryExpo(x, y, n) << '\n';
}

int main() {
    _FasterIO;
    cin >> tc;
    while (tc--) {
        solve();
    }
    bool dummy;
    cin >> dummy;
    return 0;
}
