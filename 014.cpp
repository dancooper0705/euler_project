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

map<long long, int> M;

void dfs(long long s) {
    if (M.count(s))
        return;

    // cout << __func__ << ", s: " << s << endl;

    if (s % 2 == 0) {
        dfs(s / 2);
        M[s] = M[s/2] + 1;
    } else {
        dfs(3 * s + 1);
        M[s] = M[3*s+1] + 1;
    }
}

void build_table() {
    M[1] = 1;

    for (int i = 2; i < 1e6; i++) {
        if (M.count(i) == 0) {
            dfs(i);
        }
        // cout << "M[" << i << "]: " << M[i] << endl;
    }
}

int solve() {
    long long opt = 0;
    int sol = -1;

    for (int i = 1; i < 1e6; i++)
        if (M[i] > opt) {
            sol = i;
            opt = M[i];
        }

    return sol;
}

int main() {
    ios::sync_with_stdio(false);

    build_table();

    int ans = solve();
    cout << ans << endl;

    return 0;
}

