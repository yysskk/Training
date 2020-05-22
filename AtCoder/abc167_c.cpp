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

ll ans = 0;
int n,m;
ll x;
ll a[13][13];
ll c[13];

ll flag = false;

void rec(vector<ll> check, ll index, ll price) {
    if(index>=n) {
        rep(i, m) {
            if(check[i]<x) {
                return;
            }
        }
        flag = true;
        ans = min(ans, price);
        return;
    }

    rec(check, index+1, price);

    rep(i, m) {
        check[i] += a[index][i];
    }

    rec(check, index+1, price+c[index]);

    return;
}

int main() {
    
    cin >> n >> m >> x;
    
    
    rep(i, n) {
        cin >> c[i];
        ans += c[i];
        rep(j, m) {
            cin >> a[i][j];
        }
    }

    vector<ll> check;
    rep(i, m) {
        check.push_back(0);
    }
    rec(check, 0, 0);    
    
    if(!flag) {
        print(-1);
    } else {
        print(ans);
    }

    return 0;
}
