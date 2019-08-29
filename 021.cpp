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

int get_proper_divisor(int n) {
    int ans = 0;

    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i < n)
                ans += i;
            int j = n / i;
            if (j > i && j < n) {
                ans += j;
            }
        }
    }

    return ans;
}

long long solve(int n) {
    vi A(n);
    for (int i = 1; i < n; i++)
        A[i] = get_proper_divisor(i);

    long long ans = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] != i && A[i] >= 1 && A[i] < n && A[A[i]] == i) {
            ans += i;
            cout << "A[" << i << "]: " << A[i] << endl;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n = 10000;

    long long ans = solve(n);
    cout << ans << endl;

    return 0;
}

