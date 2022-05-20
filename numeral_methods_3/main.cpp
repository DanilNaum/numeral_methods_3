#include "vector.h"

double Func( double x) {
    return (1 / tan(x) - x * x);

}

double DFunc( double x) {
    return -1 / pow(sin(x), 2) - 2 * x;
}

vector<double> Func2(vector<double> x) {
    
    vector<double>A = { cos(x[0] + 0.5) + x[1] - 0.8, sin(x[1]) - 2 * x[0] - 1.6 };
     return A;
}

vector<vector<double>> DFunc2(vector<double> x) {
    vector<vector<double>>A = {{- sin (x[0] + 0.5) ,1},
                               {-2, cos(x[1]) } };
    return A;
}


void Tangent() {
    int n = 0;
    double x_prew = 0;
    double x = 0.5;
    double fx, dfx;
    cout << "n" << " " << setw(10) << "x" << " " << setw(10) << "F(x)" << " " << setw(10) << "F'(x)" << " " << "\n";
    while (abs(x - x_prew) > EPS) {
        n += 1;
        x_prew = x;
        fx = Func(x);
        dfx = DFunc(x);
        x -= fx/dfx;
        cout << n<<" " << setw(10) << x_prew << " " << setw(10) << fx << " " << setw(10) << dfx << " " << "\n";
    }
    cout <<"F( " << x<<" )" << " = " << Func(x)<<endl<<endl;
}

void Tangent2() {
    int n = 0;
    vector<double> x_prew = { 0., 0.};
    vector<double> x = { 0.5, 0.5};
    vector<double> fx;
    vector<vector<double>> dfx;
    
    cout << "n" << " " << setw(18) << "x" << " " << setw(22) << "F(x)" << " " << setw(28) << "F'(x)" << " " << "\n";
    while (abs(x - x_prew) > EPS) {
        n += 1;
        x_prew = x;
        fx = Func2(x);
        dfx = DFunc2(x);
        x = x - Inverse2(dfx) * fx;
        cout << n << " "  << x_prew << " "  << fx << " "  << (dfx | vector<double>{56}) << " " << "\n";
    }
    cout << "F " << x << " = " <<Func2(x);
}
int main() {
    Tangent();
    Tangent2();
	return 0;
}