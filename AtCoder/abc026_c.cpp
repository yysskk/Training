// SeeAlso: https://atcoder.jp/contests/abc026/tasks/abc026_c

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define MAX 200000

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

int N;
int B[MAX];
int price[MAX];

int rec(int a) {
    if (price[a]== -1) {
        vector<int> buka;
        for(int i=a+1;i<(N);i++) {
            if (B[i]==a) {
                buka.push_back(i);
            }
        }

        if (buka.size() == 0) {
            return 1;
        }

        int maxPrice = 1;
 
        for(auto x: buka) {
            int p = rec(x);
            maxPrice = max(p, maxPrice);
        }

        int minPrice = 900000;
        
        for(auto x: buka) {
            int p = rec(x);
            minPrice = min(p, minPrice);
        }

        price[a] = maxPrice + minPrice + 1;
        return price[a];
    }
    return price[a];
}

int main() {

    cin >> N;
    B[0] = 0;
    price[0] = -1;
    for(int i=1;i<N;i++) {
        int b;
        cin >> b;
        B[i] = b-1;
        price[i] = -1;
    }

    int price = rec(0);
    print(price);
    return 0;
}
