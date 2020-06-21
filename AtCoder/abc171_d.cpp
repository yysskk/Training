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
    map<ll, ll> a;
    ll sum = 0;
    rep(i,n) {
        ll t;
        cin >> t;
        sum += t;
        ll temp = 0;
        auto it = a.find(t);
        if (it!=a.end()) {
            temp = it->second;
        }
        a.erase(t);
        a.insert(make_pair(t, 1 + temp));
    }
    ll q; cin >> q;
    rep(i, q) {
        ll b,c;
        cin >> b >> c;
        auto it = a.find(b);
        if (it!=a.end()) {
            sum -= it->second * b;
            sum += it->second * c;
            auto it2 = a.find(c);
            if(it2 != a.end()) {
                ll temp2 = it2->second + it->second;
                a.erase(c);
                a.insert(make_pair(c, temp2));
            } else {
                a.insert(make_pair(c,it->second));
            }
            a.erase(b);
        }

        print(sum);
    }

    return 0;
}
