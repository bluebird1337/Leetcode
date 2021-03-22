//https://acm.cs.nthu.edu.tw/problem/11619/

#include <iostream>
#include <algorithm> 
#include<vector>
#include <cfloat>
#include <utility>
using namespace std;

//#define SMALL -200005
//#define BIG 200005

class point {
public:
    double x;
    double y;
};

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
        vector<point>points;
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            point tmp;
            tmp.x = x, tmp.y = y;
            points.push_back(tmp);
        }
        int res = 0;
        vector<pair<double, double> >exist; //(m, intersect)
        vector<pair<int, int> >slope;
        //vector<double>slope;
        for (int i = 0, index = 0; i < n - 2; i++, index++) {
            slope.clear();
            //create slope vector
            for (int j = i + 1; j < n; j++) {
                double dx, dy;
                dx = points[j].x - points[i].x;
                dy = points[j].y - points[i].y;
                int gcd = GCD(abs(dx), abs(dy));
                dx = dx / gcd;
                dy = dy / gcd;
                pair<int, int>p = make_pair(dx, dy);
                slope.push_back(p);
            }
            //find collinear
            int size = slope.size();
            for (int k = 0; k < size - 1; k++) {
                //if (slope[k] == SMALL) continue;
                pair<int, int>curr_m = make_pair(slope[k].first, slope[k].second);
                //double curr_m = slope[k];
                for (int l = k + 1; l < size; l++) {
                    if (slope[l] == curr_m) { // check for collinear
                        double m, intersect;
                        if (curr_m.first == 0) {
                            m = DBL_MAX;
                            intersect = points[index].x;
                        }
                        else {
                            m = curr_m.second / curr_m.first;
                            intersect = points[index].y - m * points[index].x;
                        }                    
                        pair<double, double>collinear = make_pair(m, intersect);
                        //double intersect = points[index].y - curr_m * points[index].x;
                        //pair<double, double> collinear = make_pair(curr_m, intersect);
                        if (find(exist.begin(), exist.end(), collinear) == exist.end()) { //check if the line is already been recorded
                            //not included
                            res++;
                            exist.push_back(collinear);
                        }
                        //slope[l] = SMALL;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}