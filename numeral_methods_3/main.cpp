#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
constexpr auto EPS = 1e-6;
using namespace std;

vector<vector<double>> Inverse2(vector<vector<double>> A) {
    if (A.size() == 2 and A[0].size() == 2){
        auto a = A[0][0];
        auto b = A[0][1];
        auto c = A[1][0];
        auto d = A[1][1];
        auto Det = a * d - b * c;
        A = { {d / Det,-b / Det},
                {-c / Det,a / Det} };
        return A;
    }
    exit(0);
}

double Func( double x) {
    return (1 / tan(x) - x * x);

}

double DFunc( double x) {
    return -1 / pow(sin(x), 2) - 2 * x;
}

vector<double> Func2(vector<double> x) {
    return vector<double>(cos(x[0] + 0.5) + x[1] - 0.8, sin(x[1]) - 2*x[0]-1.6);

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
    cout <<"F( " << x<<" )" << " = " << Func(x);
}

void Tangent2() {
    int n = 0;
    double x_prew = 0;
    double x = 0.5;
    long double fx, dfx;
    cout << "n" << " " << setw(10) << "x" << " " << setw(10) << "F(x)" << " " << setw(10) << "F'(x)" << " " << "\n";
    while (abs(x - x_prew) > EPS) {
        n += 1;
        x_prew = x;
        fx = Func(x);
        dfx = DFunc(x);
        x -= fx / dfx;
        cout << n << " " << setw(10) << x_prew << " " << setw(10) << fx << " " << setw(10) << dfx << " " << "\n";
    }
    cout << "F( " << x << " )" << " = " << Func(x);
}
int main() {
    Tangent();
	return 0;
}