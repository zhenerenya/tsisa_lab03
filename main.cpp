#include <iostream>
#include <random>
#include <iomanip>
#include "math.h"

double f (double& x){
    return exp((-.2)*x)*sin(x)+1;
}

double f_multi (double& x){
    return f(x)*sin(5*x);
}

double x (double a, double b){
    return 1.*(b-a)*rand()/RAND_MAX+a;
}

void SA (double f_x(double& x)){
    int N=1; //количество итераций
    double _x; //точки вычисения функции
    double A=9;
    double B=12;
    double T=1000;
    double T_min=0.1;
    double d_f;
    double _f;
    double _f_min, _x_min;

    std::cout<<"|  N   |"<<std::setw(7)<<"T"<<std::setw(6)<<"|"<<std::setw(7)<<
             "x"<<std::setw(6)<<"|"<<std::setw(11)<<"f(x)"<<std::setw(3)<<"|"<<std::endl;

    _x_min=x(A, B);
    while (T>T_min){
        _x = x(A, B);
        _f_min=f_x(_x_min);
        _f=f_x(_x);
        d_f=_f - _f_min;
        if(d_f <= 0){
            _f_min=_f;
            _x_min=_x;
        } else {
            double P=exp(-d_f/T);
            double q=x(0, 1);
            if (P>q){
                _x_min=x(A, B);
            }

        }
        std::cout<<"|"<<std::setw(4)<<N<<std::setw(3)<<"|"<<std::setw(9)<<T<<std::setw(4)<<"|"<<std::setw(9)<<
                 _x_min<<std::setw(4)<<"|"<<std::setw(11)<<_f_min<<std::setw(3)<<"|"<<std::endl;
        T=T*0.95;
        N++;
    }
    std::cout<<std::endl<<"Result: Xmin="<<_x_min<<"  Fmin="<<_f_min<<std::endl;
}

int main() {
    srand(time(NULL));
    SA(f);
    std::cout<<std::endl<<::std::endl<<"FOR MULTI F(X)*SIN(5X)"<<std::endl;
    SA(f_multi);






    return 0;
}
