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

vector<vector<ll>> ans;
map<int, int> hashmap;
ll n,k,c;
string s;

void divideAndConcur(ll index, vector<ll> skipList, vector<ll> workDay) {
    if (index>=n) {
        if (workDay.size()==k) {
            ans.push_back(workDay);
        }
        debug(workDay[0]);
        return;
    }
    if (workDay.size()>k) return;

    divideAndConcur(index+1, skipList, workDay);
    if(skipList[index]>0) {
        workDay.push_back(index);
        rep(i, c) {
            skipList[i+1+index] = -1;
        }
        divideAndConcur(index+1, skipList, workDay);
    }
    debug("hoge");
    return;
}

int main() {
    cin >> n >> k >> c;
    cin >> s;

    int rest = 0;
    vector<ll> skipList(n, 0);
    vector<ll> workDay;
    rep(i, n) {
        if (s[i]=='x' && (i+i)<n) {
            skipList[i+i+1] = -1;
            debug(i+i);
        }
    }

    rep(i, n) {
        if(skipList[i]>0) {
            workDay.push_back(i);
            divideAndConcur(i+1, skipList, workDay);
        }
    }
    
    for(auto it=ans.begin();it!=ans.end();it++) {
        vector<ll> t = *it;
        for(auto itt=t.begin();itt!=t.end();itt++) {
            ll value = *itt;
            if(hashmap.find(value)==hashmap.end()) {
                hashmap[value] = 1;
            } else {
                hashmap[value] = hashmap[value] + 1;
            }
        }
    }

    for(auto it=hashmap.begin();it!=hashmap.end();it++) {
        auto value = *it;
        if(value.second==ans.size()) {
            print(value.first);
        }
    }

    return 0;
}
