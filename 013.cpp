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

string solve(vector<vector<int>>& A) {
    vector<int>& B = A[0];

    /*
    for (int i = 0; i < A.size(); i++)
        cout << "A[" << i << "]: " << A[i] << endl;
    */

    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            B[j] += A[i][j];
        }
    }

    for (int i = 0; i < B.size(); i++) {
        if (B[i] >= 10) {
            if (i + 1 < B.size()) {
                B[i+1] += B[i] / 10;
                B[i] %= 10;
            } else {
                B.push_back(B[i] / 10);
                B[i] %= 10;
            }
        }
    }

    // cout << "B: " << B << endl;

    string str;
    for (int i = B.size() - 1; i >= 0; i--)
        str.push_back(B[i] + '0');

    // cout << "str: " << str << endl;

    return str.substr(0, 10);
}

int main() {
    ios::sync_with_stdio(false);
    vector<vector<int>> A;
    string str;

    while (cin >> str) {
        vi v;
        for (auto ch: str)
            v.push_back(ch - '0');
        reverse(v.begin(), v.end());
        A.push_back(v);

    }
    string ans = solve(A);
    cout << ans << endl;

    return 0;
}

