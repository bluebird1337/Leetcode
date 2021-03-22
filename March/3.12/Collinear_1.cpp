//https://acm.cs.nthu.edu.tw/problem/11619/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<p> points;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            points.push_back({ x,y });
        }

        int res = 0;
        vector<pair<p, ll> > exist; //(m, intersect)
        vector<p> coef;

        for (int i = 0, index = 0; i < n - 2; i++, index++) {
            coef.clear();
            for (int j = i + 1; j < n; j++) {
                ll dx, dy;
                dx = points[j].first - points[i].first;
                dy = points[j].second - points[i].second;
                if (dx == 0LL) {
                    coef.push_back({ 1LL, 0LL });
                    continue;
                }
                if (dy == 0LL) {
                    coef.push_back({ 0LL, 1LL });
                    continue;
                }
                ll gcd = GCD(abs(dx), abs(dy));
                dx /= gcd;
                dy /= gcd;
                if (dy < 0LL) dy *= -1LL;
                else dx *= -1LL;
                coef.push_back({ dy, dx });
            }
            //find collinear
            int size = coef.size();
            for (int k = 0; k < size - 1; k++) {
                p curr_coef = coef[k];
                for (int l = k + 1; l < size; l++) {
                    if (coef[l] == curr_coef) { // check for collinear
                        ll	intersect = curr_coef.first * points[index].first + curr_coef.second * points[index].second;
                        pair<p, ll>collinear = make_pair(curr_coef, intersect);
                        if (find(exist.begin(), exist.end(), collinear) == exist.end()) { //check if the line is already been recorded
                            //not included
                            res++;
                            exist.push_back(collinear);
                        }
                    }
                }
            }

        }
        cout << res << endl;
    }
    return 0;
}
