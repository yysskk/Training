// SeeAlso: https://atcoder.jp/contests/dp/tasks/dp_c

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

int n;
int a[MAX][3];


int main (){ 

    cin >> n;
    rep(i, n) {
        rep(j, 3) {
            cin >> a[i][j];
        }
    }
    
    ll ans = 0;

    ll dp[n+1][3];
    memset(dp, 0, sizeof(dp));

    rep(i ,3) {
        dp[0][i] = a[0][i];
    }

    FOR(i, 1, n) {
        rep(j, 3) {
            rep(k, 3) {
                if(j==k) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][k]+a[i][j]);
            }
        }
    }

    rep(i, 3) {
        ans = max(ans, dp[n-1][i]);
    }
    print(ans);
    return 0;
}   