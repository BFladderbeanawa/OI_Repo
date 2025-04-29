#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10, P = 1e9 + 7;

int n, m, q;
int f[N], o[N], z[N], num[N], v[N], c[N];
map<int, int> mp;

int qpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ret;
}

int get_ones(int x) {
    int p = lower_bound(num + 1, num + n + 1, x) - num;
    return o[p - 1] + v[p] * (x - num[p - 1]);
}

int get_zeros(int x) {
    int p = lower_bound(num + 1, num + n + 1, x) - num;
    return z[p - 1] + (!v[p]) * (x - num[p - 1]);
}

int find_zero_pos(int x) {
    int p = lower_bound(z + 1, z + n + 1, x) - z - 1;
    return num[p] + x - z[p];
}

int get_val(int x) {
    int p = lower_bound(num + 1, num + n + 1, x) - num;
    int pw = qpow(2, x - num[p - 1]);
    int ret = f[p - 1] * pw % P;
    if (v[p]) ret = (ret + pw - 1) % P;
    return ret;
}
void prework(){
    int tmp = 0, nn = 0, lst = 1;
    for (auto [x, y] : mp) {
        c[++nn] = x - lst;
        v[nn] = tmp;
        tmp ^= y;
        lst = x;
    }
    
    n = nn;
    for (int i = 1; i <= n; i++) {
        o[i] = o[i-1] + v[i] * c[i];
        int pw = qpow(2, c[i]);
        f[i] = f[i-1] * pw % P;
        if (v[i]) f[i] = (f[i] + pw - 1) % P;
        z[i] = z[i-1] + (!v[i]) * c[i];
        num[i] = num[i-1] + c[i];
    }
}
void input(){
    cin >> n >> m >> q;
    mp[1] = mp[n + 1] = 0;
    
    for (int i = 1, l, r; i <= m; i++) {
        cin >> l >> r;
        mp[l] ^= 1;
        mp[r + 1] ^= 1;
    }
    prework();
}
void binary() {
    input();
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int ones = get_ones(r) - get_ones(l - 1);
        
        if (ones >= k) {
            cout << (qpow(2, k) - 1 + P) % P << '\n';
            continue;
        }
        
        int p = find_zero_pos(get_zeros(r) + 1 - (k - ones));
        int t1 = (qpow(2, get_ones(p - 1) - get_ones(l - 1)) - 1) * qpow(2, r - p + 1) % P;
        int ans = (t1 - get_val(p - 1) * qpow(2, r - p + 1) % P + get_val(r)) % P;
        cout << (ans + P) % P << '\n';
    }
}

signed main() {
    binary();
    return 0;
}