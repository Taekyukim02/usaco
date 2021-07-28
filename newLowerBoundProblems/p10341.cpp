#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double p, q, r, s, t, u, E=1E-9;

double eval(double x) {
    double ret = p*pow(2.71828, -x) + q*sin(x) + r*cos(x)
                    + s*tan(x) + t*x*x + u;
    return ret;
}

int main() {
    while(cin >> p) {
        cin >> q >> r >> s >> t >> u;
        double l = 0;
        double r = 1;
        while(abs(r-l) > E) {
            double mid = (l+r)/2;
            if(eval(mid) > 0)
                l = mid;
            else
                r = mid;
        }

        if(abs(eval(l)) < 0.000001)
            cout << fixed << setprecision(4) << l << endl;
        else
            cout << "No solution" << endl;
    }
}