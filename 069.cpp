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
    int n = 1e6 + 1;
    vi A(n, 1);

    A[0] = A[1] = 0;
    for (int i = 0; i < n; i++)
        if (A[i])
            for (int j = i + i; j < n; j += i)
                A[j] = 0;

    for (int i = 0; i < n; i++)
        if (A[i])
            prime.push_back(i);

    // cout << "prime: " << prime << endl;
}

int get_totient(int n) {
    vi F;
    int val = n;

    for (int i = 0; i < prime.size() && prime[i] <= sqrt(val); i++) {
        while (val % prime[i] == 0) {
            F.push_back(prime[i]);
            val /= prime[i];
        }
    }

    if (val > 1)
        F.push_back(val);

    sort(F.begin(), F.end());
    F.erase(unique(F.begin(), F.end()), F.end());

    int ans = n;
    for (auto a: F) {
        ans = ans / a * (a - 1);
    }
    return ans;
}

int solve(int n) {
    double max_val = -1e9;
    int sol = -1;

    for (int i = 1; i <= n; i++) {
        double val = 1.0 * i / get_totient(i);
        if (max_val < val) {
            max_val = val;
            sol = i;
        }
    }
    return sol;
}

int main() {
    ios::sync_with_stdio(false);
    int n = 1e6;

    build_prime();

    int ans = solve(n);
    cout << ans << endl;

    return 0;
}

