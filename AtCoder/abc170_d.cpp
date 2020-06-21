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

const long long INF = 1LL<<60;

int main() {
    ll n;
    cin >> n;
    vector<ll> a;
    rep(i, n) {
        ll t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    vector<bool> checked(1000000, true);

    if (a[0]==1) {
        if (n>1&&a[1]==1) {
            print(0);
        } else {
            print(1);
        }
        return 0;
    }

    ll ans = 0;
    rep(i, n) {
        if (i>0 && a[i-1]==a[i]) continue;

        ll target = a[i];
        if (checked[target] && !(i+1<n && a[i]==a[i+1])) {
            ans++;
        }
        while(target<=1000000) {
            checked[target] = false;
            target += a[i];
        }
    }

    print(ans);
    return 0;
}
