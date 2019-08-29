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

vector<int> add(const vector<int>& A, const vector<int>& B) {
    vector<int> C(max(A.size(), B.size()), 0);

    /*
    cout << "A: " << A << endl;
    cout << "B: " << B << endl;
    */

    for (int i = 0; i < A.size(); i++)
        C[i] += A[i];

    // cout << "C: " << C << endl;

    for (int i = 0; i < B.size(); i++)
        C[i] += B[i];

    // cout << "C: " << C << endl;

    for (int i = 0; i < C.size(); i++) {
        if (C[i] >= 10 && i + 1 < C.size()) {
            C[i+1] += C[i] / 10;
            C[i] %= 10;
        } else if (C[i] >= 10 && i < C.size()) {
            C.push_back(C[i] / 10);
            C[i] %= 10;
        }
    }

    return C;
}

int solve(int m) {
    vector<vector<int>> fab(2);

    fab[0] = {1};
    fab[1] = {1};

    while (fab.back().size() < m) {
        fab.push_back(add(fab[fab.size()-2], fab[fab.size()-1]));
    }

    /*
    for (int i = 0; i < fab.size(); i++)
        cout << "fab[" << i << "]: " << fab[i] << endl;
    */

    return fab.size();
}

int main() {
    ios::sync_with_stdio(false);
    int m = 1000;

    int ans = solve(m);
    cout << ans << endl;

    return 0;
}

