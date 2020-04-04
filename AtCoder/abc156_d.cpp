// SeeAlso: https://atcoder.jp/contests/abc156/tasks/abc156_d

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 1000005
#define NIL -1
#define MOD 1000000007

typedef int _loop_int;
#define rep(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define debug(x) cout<<#x<<": "<<x<<endl
#define debig_vec(v) cout<<#v<<":";rep(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) rep(i, h) { rep(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

const ll mod = 1000000007;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];

ll beki(ll k, ll n) {
  ll x = 1;
    while (n > 0) {
        if (n & 1) {
            x = x * k % mod;
        }
        k = k * k % mod;
        n >>= 1;
    }
    return x;
}

// void init_combination(){
//     Factorial[0] = 1;
//     inv[0] = 1;
//     for(int i = 1; i <= MAX; i++){
//         Factorial[i] = Factorial[i - 1] * i % mod;
//     }
//     FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
//     for(ll i = MAX - 1; i >= 0; i--) {
//         FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
//     }
//     for(int i = 1; i <= MAX; i++) {
//         inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
//     }
// }

ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ret = 1;
    for(ll i = 0; i < b; i++) {
        ret *= (a - i);
        ret %= mod;
        ret *= beki(i + 1, mod - 2);
        ret %= mod;
    }
    return ret;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = beki(2, n) - 1;
    
    ans -= combination(n, a);
    ans %= MOD;
    ans -= combination(n, b);
    ans %= MOD;

    if (ans < 0) {
        ans += MOD;
    }
    print(ans);
    return 0;
}
