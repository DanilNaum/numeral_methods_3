#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
constexpr auto EPS = 1e-6;
using namespace std;

ostream& operator<< (ostream& out, vector<vector<double>>A) {
    if (A.size() == A[0].size()) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                out << setw(4) << A[i][j] << " ";
            }
            out << endl;
        }
    }
    else if (A.size() - 1 == A[0].size(),A[A.size()-1].size()==A.size()) {
        for (int i = 0; i < A.size() - 1; i++) {
            for (int j = 0; j < A[i].size(); j++) {
                out << setw(4) << A[i][j] << " ";
            }
            out << " \t |" << A[A.size() - 1][i] << endl;
        }
    }
    else if (A.size() - 1 == A[0].size(), A[A.size()-1].size() == 1) {
        for (int i = 0; i < A.size() - 1; i++) {
            out << "(" << setw(10) << A[i][1];
            for (int j = 1; j < A[i].size(); j++) {
                out << ", " << setw(10) << A[i][j];;
            }
            out <<")" << endl;
            for(int i = 0 ;i < (int(A[A.size() - 1][0]));i++)
                out<<" ";
        }
    }
    return out;
}
ostream& operator<< (ostream& out, vector<double>A) {
    out << "(" << setw(11) << A[0];
    for (int j = 1; j < A.size(); j++) {
        out << ", " << setw(11) << A[j];
    }
    out << ")";
    return out;
}

vector<vector<double>> operator+(vector<vector<double>>A, vector<vector<double>>B) {
    if (A.size() != B.size()) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                A[i][j] += B[i][j];
            }
        }
        return A;
    }
    exit(0);
}
vector<vector<double>> operator-(vector<vector<double>>A) {
    for (int i = 0; i < A.size(); i++) 
        for (int j = 0; j < A[i].size(); j++)
            A[i][j] = -A[i][j];
    return A;
}
vector<vector<double>> operator|(vector<vector<double>>A, vector<double>B) {
    A.push_back(B);
    return A;
}
vector<double> operator-(vector<double> A) {
    for (int i = 0; i < A.size(); i++) 
        A[i] = -A[i];
    return A;
}
vector<double> operator+(vector<double>A, vector<double>B) {
    if (A.size() == B.size()) {
        for (int i = 0; i < A.size(); i++) {
                A[i] += B[i];
        }
        return A;
    }
    exit(-1);
}
vector<double> operator-(vector<double>A, vector<double>B) {
    return A + (-B);
}

vector<double> operator*(vector<vector<double>>A, vector<double>B) {
    if (A.size() == B.size() && A[0].size()==B.size()) {
        vector<double> C(B.size());
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                C[i] += B[j]*A[i][j];
            }
        }
        return C;
    }
    exit(-1);
}



vector<vector<double>> Inverse2(vector<vector<double>> A) {
    if (A.size() == 2 and A[0].size() == 2) {
        auto a = A[0][0];
        auto b = A[0][1];
        auto c = A[1][0];
        auto d = A[1][1];
        auto Det = a * d - b * c;
        A = { {d / Det,-b / Det},
                {-c / Det,a / Det} };
        return A;
    }
    exit(-1);
}

double abs(vector<double> A) {
    double ans = 0;
    for (int i = 0; i < A.size(); i++)
        ans += pow(A[i], 2);
    return sqrt(ans);
}
