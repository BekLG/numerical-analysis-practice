#include <iostream>
#include <cmath>
using namespace std;

float customFunction(float m)
{
    float result= (m*m*m)-(5*m)+1;
    return result;
}

float bisection(float a, float b, float tol)
{
    float root, mid;
    int i=0;
    while((b-a)/2 > tol)
    {
        mid= (a+b)/2;
        cout<<"mid: "<<mid<<endl;
        root = customFunction(mid);
        cout<<"root: "<<root<<endl;
        if(root == 0.0)
            break;
        else if(root*customFunction(a) < 0)
            b = mid;
        else
            a = mid;
        i++;
    }
    cout << "Root: " << mid << endl;
    return mid;
}

int main()
{
    float a=0, b=1, tol=0.001;
    bisection(a, b, tol);
    return 0;
}
