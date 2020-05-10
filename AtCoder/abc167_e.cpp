// SeeAlso: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000
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

int main() {
    ll n,m,k;
    cin >> n >> m >> k;

    ll dp[200002];
    ll temp[200002];

    memset(dp,0,sizeof(dp));
    dp[0] = m;    
    memcpy(temp, dp, sizeof(dp));

    for(ll i=2;i<=n;i++) {
        ll kaburi = min(i-1, k);

        dp[0] = temp[0] * (m-1);
        FOR(j, 1, kaburi+1) {
            dp[j] = temp[j-1];

            if(j<(i-1)) {
                dp[j] += temp[j]*(m-1);
            }
        }

        memcpy(temp, dp, sizeof(dp));
    }

    ll ans = 0;
    FOR(i, 0, k+1) {
        ans += dp[i];
        ans %= 998244353;
    }
    print(ans);
    return 0;
}
