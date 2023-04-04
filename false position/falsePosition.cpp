#include <iostream>
#include <cmath>

using namespace std;

double customFunction(double c) {
    return cos(c) - c * exp(c);
}
void falsePosition(double a, double b, double tol)
{
    double c= ((a * customFunction(b)) -  (b * customFunction(a))) / (b-a);
    cout<<c;
}

int main()
{
    falsePosition(1, -2.17798, 0.001);
}
