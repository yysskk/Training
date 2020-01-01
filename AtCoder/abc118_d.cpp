// SeeAlso: 

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

int N, M;
 
int main() {

    cin >> N >> M;
 
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    sort(A.begin(), A.end());
 
    map<int, int> m;
    m[1] = 2;
    m[2] = 5;
    m[3] = 5;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 3;
    m[8] = 7;
    m[9] = 6;
 
    vector<int> use;
    for (int i = 0; i < A.size(); i++) use.push_back(m[A[i]]);
    sort(use.begin(), use.end());
    use.erase(unique(use.begin(), use.end()), use.end());
  
    vector<int> dp(N + 100, -1);
    dp[0] = 0;
    for (int i = 0; i <= N; i++) {
        if (dp[i] >= 0) {
            for (int j = 0; j < use.size(); j++) {
                dp[i + use[j]] = max(dp[i + use[j]], dp[i] + 1);
            }
        }
    }
 
    string ans = "";
    int remain = N;
    int digit = dp[N];
    while (remain > 0) {
        for (int i = M - 1; i >= 0; i--) {
            if (remain - m[A[i]] >= 0 && digit - dp[remain - m[A[i]]] == 1) {
                ans += (char) ('0' + A[i]);
                remain -= m[A[i]];
                digit--;
                break;
            }
        }
    }

    print(ans);

    return 0;
}
