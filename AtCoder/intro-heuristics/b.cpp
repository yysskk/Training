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
    vector<int> A; 
    rep(i, 5) {
        int a;
        cin >> a; A.push_back(a);
    }

        int mid = 0;
        for(int i=0;i<A.size();i++) {
            if(abs(A[mid])>abs(A[i])) mid = i;
        }
        vector<int> ans;
        ans.push_back(A[mid] * A[mid]);
        int left = mid-1;
        int right = mid+1;
        while(left>=0 || right<A.size()) {
            if(left<0) {
                ans.push_back(A[right] * A[right]);
                right++;
            }
            if(right>=A.size()) {
                ans.push_back(A[left] * A[left]);
                left--;
            }
            if(abs(A[left])<abs(A[right])) {
                ans.push_back(A[left] * A[left]);
                left--;                
            } else {
                ans.push_back(A[right] * A[right]);
                right++;
            }
            debug(ans[ans.size()-1]);
        }

    rep(i, 5) print(ans[i]);
    return 0;
}
