// SeeAlso: https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 100000
#define NIL -1
#define MOD 998244353

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
    ll N;
    cin >> N;
    
    ll temp[MAX];
    rep(i, N) {
        temp[i] = 0;
    }
    
    bool flag = false;

    rep(i, N) {
        ll a;
        cin >> a;
        if(i==0&&a!=0) {
            flag = true;
        }
        temp[a]++;
    }
 
    ll root = temp[0];
    if (root != 1 || flag) {
        print(0);
        return 0;
    }
    
    ll ans = root;
    rep(i, N) {
        rep(j, temp[i+1]) {
            ans = ans * temp[i] % MOD;
        }
    }
    
    print(ans);
    return 0;
}
