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
template<class T> inline void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> inline void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main() {
    ll w,n,K;
    cin >> w >> n >> K;
    ll a[n], b[n];
    rep(i, n) cin >> a[i] >> b[i];

    /// nの時w以下k枚以下のスクショの合計の最大値
    ll dp[n+1][K+1][w+1];
    memset(dp, 0, sizeof(dp));

    rep(i, n) {
        rep(j, K+1) {
            rep(k, w+1) {
                if((k-a[i])>=0 && j<K) {
                    chmax(dp[i+1][j+1][k], dp[i][j][k-a[i]]+b[i]);
                }                
                chmax(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }
    print(dp[n][K][w]);
    return 0;
}
