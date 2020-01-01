// SeeAlso: https://atcoder.jp/contests/abc144/tasks/abc145_e

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
    int n, t;
    cin >> n >> t;
    multimap<double, pair<int,int>> m;

    rep(i, n) {
        int a,b;
        cin >> a >> b;
        double k = b/a;
        m.insert(make_pair(k ,make_pair(a, b)));
    }
    int timer = 0;
    ll ans = 0;
    auto it = m.end();

    while(t>timer) {
        it--;
        auto value = *it;
        ans += value.second.second;
        timer += value.second.first;
        debug(ans);
        debug(timer);

        if (it==m.begin()) {
            break;
        }
    }

    if(timer>=t) {
        it++;
        auto value = *it;
        ans -= value.second.second;
        timer -= value.second.first;
    }

    int temp = 0;
    if(timer<t) {
        auto itt = it;
        bool flag = true;
        debug("hoge");
        while(flag) {
            auto value = *itt;
            if(temp<value.second.second) {
                temp = value.second.second;
            }
            if (itt==m.begin()) {
                flag = false;
                break;
            } else {
                it--;
            }
        }
    }

    print(ans+temp);
    return 0;
}
