#include "SimpleMathDll.h"
// Windows DLL Support
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
/*
**
 * @brief Approximates the square root of a fraction using Newton-Raphson method.
 * 
 * Given z_1 / z_2, this function iteratively calculates a fraction
 * x / y that approximates sqrt(z_1 / z_2).
 *
 * @param input_numerator Numerator of the value to take sqrt of
 * @param input_denominator Denominator of the value to take sqrt of
 * @param Iterations The Amount of Iterations, more Iterations make the square root more precise
 * @return std::pair<int,int> The next approximation as a fraction (numerator, denominator)
 */
class EXPORT Fraction {
public:
    int Numerator;
    int Denominator;

    // Konstruktor
    Fraction(int numerator, int denominator) 
        : Numerator(numerator), Denominator(denominator) {}

    // Konvertierungsoperatoren
    operator double() { return static_cast<double>(Numerator) / Denominator; }
    operator float()  { return static_cast<float>(Numerator) / Denominator; }
};

EXPORT Fraction CustomSqrt(int input_numerator, int input_denominator, int Iterations) {
    // use the following Sqrt Approximation, lets use a first approximation, we'll use 4 as Starting Value, the starting value will be defined as x/y currently, so x/y=4, which means for now we heave x=8 and y=2
    // We will create the sqrt of Input_numerator/input_denominator, which we will call z_1/z_2 in the following Math Functions
    // Lets make our approximation a little nearer to the square root, by using Newton Raphsons Method.
    // So lets make it be (z_1/z_2)/(x/y), which equals to (z_1*y)/(z_2*x), so now we need to get the middle value of x/y and (z_1*y)/(z_2*x), which is (x^2*z_2+y^2*z_1)/(z_2*x*y), now we need to half it, so its now (x^2*z_2+y^2*z_1)/(2*z_2*x*y)
    int x = 8;
    int y = 2;
    int NewX = x;
    int NewY = y;
    for (int i = 0; i < Iterations; i++) {
        // Newton-Raphson iteration for sqrt(z_1/z_2)
        // NewX = (x*x*input_denominator + y*y*input_numerator)
        // NewY = 2 * input_denominator * x * y
        NewX = x * x * input_denominator + y * y * input_numerator;
        NewY = 2 * input_denominator * x * y;
        x = NewX;
        y = NewY;
    }
    // Return the approximation as a Fraction
    return Fraction(x, y);
}