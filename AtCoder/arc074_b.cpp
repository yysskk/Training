// SeeAlso: https://atcoder.jp/contests/arc074/tasks/arc074_b

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

int N;
ll a[MAX];
priority_queue<ll, vector<ll>, greater<ll>> a1;
priority_queue<ll> a2;

int main() {
    cin >> N;

    REP(i, N) {
        ll temp;
        cin >> temp;
        a1.push(temp);
    }   

    REP(i, N) {
        ll temp;
        cin >> a[i];
    }

    REP(i, N) {
        ll temp;
        cin >> temp;
        a2.push(temp);
    }

    REP(i, N) {
        ll temp1 = a1.top();
        ll temp2 = a2.top();
        ll first = a[i] - temp1;
        ll second = temp2 - a[N-1-i];
        if (first > (second*2)) {
            a2.pop();
            a2.push(a[N-1-i]);
        } else {
            a1.pop();
            a1.push(a[i]);
        }
    }

    ll ans = 0; 
    
    REP(i, N) {
        ans += a1.top();
        ans -= a2.top();
        a1.pop();
        a2.pop();
    }

    cout << ans << endl;

    return 0;
}
