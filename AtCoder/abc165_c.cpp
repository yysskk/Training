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

int n,m,q;
int a[51][4];
int ans = 0;

void rec(int selectindex, vector<int> A) {
    int asize = A.size();
    if(asize==n) {
        int anstemp = 0;
        rep(i, q) {
            int t = A[a[i][1]-1] - A[a[i][0]-1];
            if(t==a[i][2]) {
                anstemp += a[i][3];
            }
        }
        ans = max(ans, anstemp);
        return;
    }

    FOR(i, selectindex, m) {
        vector<int> t = A;
        t.push_back(i+1);
        rec(i, t);
    }

    return;
}

int main() {
    cin >> n >> m >> q;

    rep(i, q) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
    }

    vector<int> temp;
    rec(0, temp);

    print(ans);
    return 0;
}
