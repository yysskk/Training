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

int n;

ll ans = 0;
vector<ll> a;
int rankCounter = 0;

ll rec(int left, int right, int index, multimap<int, int>& ms_rank, bool flag) {
    if (index==rankCounter) {
        return 0;
    }
    auto range = ms_rank.equal_range(index);

    if (ms_rank.count(index==1) && flag) {
        int position = range.first->second;
        debug(index);
        debug(position);
        int diff_left = abs(position-left);
        int diff_right = abs(position-right);
        ll leftt = diff_left * a[position] + rec(left+1, right, index+1, ms_rank, true);
        ll rightt = diff_right * a[position] + rec(left, right-1, index+1, ms_rank, true);
        return max(leftt, rightt);
    } else {
        ll maxx = 0;

        auto itr = range.first;
        while(itr!=range.second) {
            int position = itr->second;
            debug(position);
            int diff_left = abs(position-left);
            int diff_right = abs(position-right);
            ms_rank.erase(itr);
            bool fflag = ms_rank.count(index)==1;
            if (fflag) {
                index++;
            }
            ll leftt = diff_left * a[position] + rec(left+1, right, index, ms_rank, fflag);
            ll rightt = diff_right * a[position] + rec(left, right-1, index, ms_rank, fflag);
            if (maxx < max(leftt, rightt)) {
                maxx = max(leftt, rightt);
            }
            itr++;
        }

        return maxx;
    }

}

int main() {
    cin >> n;

    vector<ll> temp;
    vector<ll> ttemp;
    // 活発度に対応するランク
    multimap<int, int> ms_rank;
    rep(i, n) {
        int t;
        cin >> t;
        a.push_back(t);
        temp.push_back(t);
        ttemp.push_back(t);
    }
    sort(temp.begin(), temp.end(), greater<ll>());

    bool flag = true;
    rep(i, n) {
        rep(j,n) {
            if (temp[i]==a[j]) {
                if (ttemp[j]==-1) {
                    if(flag) {
                        rankCounter--;
                        flag = false;
                    };
                    continue;
                }

                ms_rank.insert(make_pair(rankCounter, j));
                rankCounter++;
                ttemp[j] = -1;
                flag = true;
                break;
            }
        }
    }

    print(rec(0, n-1, 0, ms_rank, true));

    return 0;
}
