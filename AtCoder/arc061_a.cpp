// SeeAlso: https://arc061.contest.atcoder.jp/tasks/arc061_a

#include <bits/stdc++.h> 

typedef long long ll;
using namespace std;

int cnt = 0;
int rec(long long x){
    if(x == 0) return cnt;
    else{
        x /= 10;
        cnt++;
        return rec(x);
    }
}
 
int main(void){
   ll S;
   cin >> S;

   int b = rec(S);
   ll ans = 0;
   vector<bool> vec(b-1);

   for(int i = 0; i < pow(2, b - 1); i++){
       ll I = i;
       for(int j = 0; j < b - 1; j++){
           vec.at(j) = I % 2;
           I /= 2;
       }
    
        vector<int> array(0);
        for(int j = 0; j < b-1; j++){
            if(vec.at(j) == 1) array.push_back(j);
        }
        int x = array.size();
    
        ll current = S;
        for(int j = 0; j < x; j++){
            ans += current / ll(pow(10, b-1-array.at(j)));
            current -= ll(current / int(pow(10, b-1-array.at(j)))) * pow(10, b-1-array.at(j));
        }
        ans += ll(current);
    }
    cout << ans << endl;
}
