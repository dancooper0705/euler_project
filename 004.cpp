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

int is_palindrome(int n) {
    string str = to_string(n);
    int len = str.size();

    for (int i = 0; i < len - 1 - i; i++)
        if (str[i] != str[len-1-i])
            return 0;

    return 1;
}

int solve() {
    int opt = -1;
    for (int i = 1e2; i < 1e3; i++) {
        for (int j = i; j < 1e3; j++) {
            int val = i * j;
            if (is_palindrome(val)) {
                opt = max(opt, val);
            }
        }
    }
    return opt;
}

int main() {
    ios::sync_with_stdio(false);
    int ans = solve();
    cout << ans << endl;
    return 0;
}

