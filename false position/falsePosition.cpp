#include <iostream>
#include <cmath>

using namespace std;

// Function to find the root using the False Position Method
double falsePosition(double a, double b, double TOL, int NoOFIteration, double (*customFunction)(double))
{
    double c = customFunction(a), d = customFunction(b), e = 0;
    for (int i = 2; i <= NoOFIteration; ++i) {  // Loop through maximum number of iterations

         e= ((a * d) -  (b * c)) / (b-a); // Compute new approximation using false position formula
        if (fabs(e - b) < TOL) return e;
        double f_e = customFunction(e);  // Compute function value at new approximation
        if (f_e * d < 0) a = b, c = d;
        b = e, d = f_e;
    }
    throw runtime_error("Method failed after " + to_string(NoOFIteration) + " iterations.");  // Throw exception if maximum number of iterations is reached
}

// Example usage
double customFunction(double x)
{
    return x * x - 3 * x + 2;  // Define example function
}

int main()
{
    try {
        double a = 0, b = 2, TOL = 0.0001;
        int NoOFIteration = 100;
        double root = falsePosition(a, b, TOL, NoOFIteration, customFunction);
        cout << "The root is approximately: " << root << endl;
    }
    catch (const exception& e) {
        cerr << e.what() << endl;  // Print error message to standard error
    }
    return 0;
}
