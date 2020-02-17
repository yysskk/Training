// SeeAlso: https://atcoder.jp/contests/abc155/tasks/abc155_d

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

ll casecounter(ll i) {
    return i * (i-1) / 2;
}

int main() {
    ll n, k;
    vector<ll> m;

    // 正
    vector<ll> a;
    // 負
    vector<ll> b;
    // 0
    vector<ll> c;
    cin >> n >> k;

    rep(i, n) {
        ll t;
        cin >> t;

        m.push_back(t);
        if(t>0) {
            a.push_back(t);
        } else if (t==0) {
            c.push_back(t);
        } else {
            b.push_back(t);
        }
    }

    if(k <=(a.size()*b.size())) {
        // 負の集合の場合
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        ll r = a.size()*b.size()+2;
        ll l = 0;
        ll mid = r;
        while(r-l!=1) {
            ll counter = 0;

            rep(i, a.size()) {
                
            }

            if (counter>k) {
                r = mid;
            } else {
                l = mid;
            }
            
        }
        print(-r);
    } else if (k <= (a.size()*b.size()+(a.size()+b.size())*c.size())) {
        // 0 の集合の場合
        print(0);
    } else {
        // 正の集合の場合

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        debug("hge");
    }

    return 0;
}
