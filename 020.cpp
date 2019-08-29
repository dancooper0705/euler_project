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

int solve(int n) {
    vector<int> A = {1};

    for (int d = 1; d <= n; d++) {
        for (int i = 0; i < A.size(); i++)
            A[i] *= d;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] >= 10 && i + 1 < A.size()) {
                A[i+1] += A[i] / 10;
                A[i] %= 10;
            } else if (A[i] >= 10 && i + 1 == A.size()) {
                A.push_back(A[i] / 10);
                A[i] %= 10;
            }
        }
    }

    int ans = 0;
    for (auto a: A)
        ans += a;

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n = 100;

    int ans = solve(n);
    cout << ans << endl;

    return 0;
}

