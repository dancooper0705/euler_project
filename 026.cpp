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

int get_cycle(int n) {
    map<int, int> M;
    int r = 10;
    int cur = 0;

    while (M.count(r) == 0) {
        M[r] = cur;
        r = (r % n) * 10;
        cur++;
    }

    if (r == 0)
        return 0;

    return cur - M[r];
}

int solve(int n) {
    int max_val = -1;
    int sol = -1;

    for (int i = 2; i <= n; i++) {
        int val = get_cycle(i);
        cout << "i: " << i << ", val: " << val << endl;
        if (max_val < val) {
            max_val = val;
            sol = i;
        }
    }

    return sol;
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1000;

    int ans = solve(n);
    cout << ans << endl;

    return 0;
}

