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

vi prime;

void build_prime() {
    int n = 1e6;
    vi A(n, 1);

    A[0] = A[1] = 0;
    for (int i = 0; i < n; i++)
        if (A[i])
            for (int j = i + i; j < n; j += i)
                A[j] = 0;
    for (int i = 0; i < n; i++)
        if (A[i])
            prime.push_back(i);
}

int is_prime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 0; i < prime.size() && prime[i] <= sqrt(n); i++)
        if (n % prime[i] == 0)
            return 0;

    return 1;
}

int is_circular_prime(int n) {
    string str = to_string(n);
    int len = str.size();

    if (!is_prime(n))
        return 0;

    for (int i = 0; i < len - 1; i++) {
        rotate(str.begin(), str.begin() + 1, str.end());
        if (!is_prime(stoi(str)))
            return 0;
    }

    return 1;
}

int solve(int n) {
    int ans = 0;
    vi A;
    for (int i = 1; i < n; i++) {
        if (is_circular_prime(i))
            A.push_back(i);
    }

    // cout << "A: " << A << endl;
    return A.size();
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1e6;

    build_prime();

    int ans = solve(n);
    cout << ans << endl;

    return 0;
}

