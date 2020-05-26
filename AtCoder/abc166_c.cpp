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

ll n, m;
multimap<ll, ll> mm;
ll h[100002];

int main() {
    
    cin >> n >> m;
    
    rep(i, n) {
        cin >> h[i];
    }
    
    rep(i, m) {
        ll a,b;
        cin >> a >> b;
        mm.insert(make_pair(a-1, b-1));
        mm.insert(make_pair(b-1, a-1));
    }

    ll ans = 0;

    rep(i, n) {
        if (h[i]==-1) continue;
        ll currentH = h[i];
        auto ret = mm.equal_range(i);
        bool flag = true;

        if (ret.first==ret.second) {
            ans++;
            continue;
        }

        for(auto it = ret.first; it !=ret.second;it++) {
            ll nextI = it->second;
            if(h[nextI]<currentH) {
            } else {
                flag = false;
            }
        }

        if (flag) {
            ans++;
        }
    }

    print(ans);
    return 0;
}