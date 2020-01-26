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

ll H, N;
ll A[MAX], B[MAX];

ll mina = 0;
void rec(ll hp, ll sum_b, ll i) {

    if(hp<=0) {
        mina = min(mina, sum_b); 
        return;
    }
    hp -= A[i];
    sum_b += B[i];
    rep(i, N) {
        rec(hp, sum_b, i);
    }
}

int main() {

    cin >> H >> N;

    ll ma_a = 0;
    ll ma_b = 0;
    double ma_c = 0;

    ll mm_a = 0;
    rep(i, N) {
        cin >> A[i] >> B[i];
        mm_a = max(mm_a, A[i]);
        double t_a = A[i];
        double t_b = B[i];
        double t_c = t_a/t_b;
        if(ma_c < t_c) {
            ma_a = A[i];
            ma_b = B[i];
            ma_c = t_c;
        }
    } 

    ll ans = 0;
    while(H>=mm_a) {
        H -= ma_a;
        ans += ma_b;
    }

    mina = ans * 2;
    rep(i, N) {
        rec(H, ans, i);
    }

    
    print(mina);
    return 0;
}
