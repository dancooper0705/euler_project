#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

vector<long long> dp;

long long solve(vector<int>& A, int m) {
    dp.assign(m + 1, 0);
    dp[0] = 1;

    for (auto a: A) {
        for (int i = a; i <= m; i++)
            dp[i] += dp[i-a];
    }

    for (int i = 0; i <= m; i++)
        cout << "dp[" << i << "]: " << dp[i] << endl;

    return dp[m];
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> A = {1,2,5,10,20,50,100,200};
    int n = 200;

    long long ans = solve(A, n);
    cout << ans << endl;

    return 0;
}

