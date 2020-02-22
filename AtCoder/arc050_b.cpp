// SeeAlso: https://atcoder.jp/contests/abc150/tasks/abc150_b

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

ll r,b;
ll x,y;

bool check(ll X){
    ll tr = r - X, tb = b - X;
    if(tr < 0 || tb < 0) return false;
    ll num = tr/(x-1) + tb/(y-1);
    return (num >= X);
}

int main() {

    cin >> r >> b;
    cin >> x >> y;

    ll ok = 0;
    ll ng = (r+b)/2 + 1;

    while(abs(ok-ng)!=1) {
        ll mid = (ok + ng)/2;

        if(check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    print(ok);
    return 0;
}
