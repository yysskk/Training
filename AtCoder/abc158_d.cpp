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

int main() {
    string s;
    cin >> s;
    vector<char> ans;
    rep(i, s.size()) {
        ans.push_back(s[i]);
    }
    
    ll q;
    cin >> q;
    bool hanten = false;
    rep(i, q) {
        int t;
        cin >> t;

        if(t==1) {
            hanten = !hanten;
        } else {
            int f;
            char c;
            cin >> f;
            cin >> c;

            bool isFront;

            if(f==1) {
                isFront = !hanten;
            } else {
                isFront = hanten;
            }
            
            if(isFront) {
                ans.insert(ans.begin(),c);
            } else {
                ans.push_back(c);
            }
        }
    }

    if(hanten) {
        reverse(ans.begin(), ans.end());
    }

    for(auto it=ans.begin();it!=ans.end();it++){
        cout << *it;
    }

    cout << endl;
    return 0;
}
