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

long long solve(vector<vector<long long>>& A) {
    vector<vector<long long>> B = A;

    for (int i = 1; i < B.size(); i++) {
        for (int j = 0; j < B[i].size(); j++) {
            if (j <= i - 1)
                B[i][j] = max(B[i][j], B[i-1][j] + A[i][j]);

            if (j - 1 >= 0)
                B[i][j] = max(B[i][j], B[i-1][j-1] + A[i][j]);
        }
    }

    /*
    for (int i = 0; i < A.size(); i++)
        cout << "A[" << i << "]: " << A[i] << endl;

    for (int i = 0; i < B.size(); i++)
        cout << "B[" << i << "]: " << B[i] << endl;
    */

    return *max_element(B.back().begin(), B.back().end());
}

int main() {
    ios::sync_with_stdio(false);
    vector<vector<long long>> A;
    string str;

    while (getline(cin, str)) {
        stringstream ss(str);
        vector<long long> v;
        long long a;
        while (ss >> a)
            v.push_back(a);
        A.push_back(v);
    }
    long long ans = solve(A);
    cout << ans << endl;

    return 0;
}

