// SeeAlso: https://atcoder.jp/contests/abc118/tasks/abc118_c

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000

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

ll N;
set<ll> A;


ll dfs(set<ll> a) {
    auto minimum = *a.begin();
    if (a.size()==1) {
        return minimum;
    }  
    set<ll> b;
    b.insert(minimum);
    for(auto it = a.begin(); it != a.end();it++) {
        ll ap = *it%minimum;
        if (ap>0) {
            b.insert(ap);
        }
    }
    return dfs(b);
}

int main() {
    cin >> N;
    REP(i, N) {
        int a;
        cin >> a;
        A.insert(a);
    }

    ll ans =  dfs(A);
    print(ans);
    return 0;
}
