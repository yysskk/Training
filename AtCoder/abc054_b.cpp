// SeeAlso: https://atcoder.jp/contests/abc054/tasks/abc054_b

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 50
#define NIL -1

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

int N, M;
string A[MAX], B[MAX];

bool ans = false;

int rec(int n, int m, int r, int s_length) {
    if(m > (M-1)) {
        return 0;
    }
    auto pos = A[n].find(B[m], r, s_length);
    while(pos != string::npos) {
        if((M-1)==m) {
            ans = true;
            break;
        } else if(m==0) {
            pos = A[n].find(B[m], pos+s_length, s_length);
            
        } else {
            rec(n+1, m+1, pos, M);
            break;
        }
    }

    if((N-n)>M) {
        rec(n+1, 0, 0, N);
    }
    return 0;
}

int main() {
    
    REP(i, N) {
        cin >> A[i];
    }

    REP(i, M) {
        cin >> B[i];
    }

    rec(0, 0, 0, N);

    if(ans) {
        print("Yes");
    } else {
        print("No");
    }

    return 0;
}
