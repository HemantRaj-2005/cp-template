#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

template<typename T>
void printVector(vector<T>& v) {
    for(size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T>
void takeInput(vector<T> &v){
    for(auto &i : v){
        cin >> i;
    }
}

void solve(){

}

signed main(){
    fast_io;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
