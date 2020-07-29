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

const long long INF = 1LL<<60;

int h, w, k;
ll ans = 0;
void rec(int dw, int dh, char c[6][6]) {
    if(dw==w && dh==h) {
        int counter = 0;
        rep(i, h) {
            rep(j, w) {
                if(c[i][j] == '#') counter++;
            }
        }
        if (k==counter) ans++;
    } else if (dh<h) {
        char temp[6][6];
        memcpy(temp, c, sizeof(c));
        rep(i, w) {
            temp[dh][i] = '.';
        }
        rec(dw, dh+1, temp);
        rec(dw, dh+1, c);
    } else if (dw<w) {
        char temp2[6][6];
        memcpy(temp2, c, sizeof(c));
        rep(i, h) {
            temp2[i][dw] = '.';
        }
        rec(dw+1, dh, temp2);
        rec(dw+1, dh, c);
    }
}

int main() {
    cin >> h >> w >> k;
    char c[6][6];

    rep(i, h) {
        rep(j, w) cin >> c[i][j];
    }

    rec(0, 0, c);

    print(ans);
    return 0;
}
