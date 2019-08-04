// SeeAlso: https://atcoder.jp/contests/abc135/tasks/abc135_d

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100024
#define MOD 1000000007

typedef int _loop_int;
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// 最大公約数
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
// 最小公倍数
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }

string S;

int main() {
    cin >> S;

    ll ans = 0;

    int count = S.size();
    int dp[MAX][13];

    dp[0][0] = 1;

    REP(i, count) {
        int c;
        if (S[i]=='?') {
            c = -1;
        } else {
            c = S[i] - '0';
        }

        REP(j, 10) {
            if(c!=-1 && c!=j) {
                continue;
            }

            REP(ki, 13) {
                dp[i+1][(ki*10+j)%13] += dp[i][ki];
            }
        }

        REP(j, 13) {
            dp[i+1][j] %= MOD;
        }
    }

    ans = dp[count][5];
    cout << ans << endl;

    return 0;
}
