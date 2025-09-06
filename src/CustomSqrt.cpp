#include "SimpleMathDll.h"
// Windows DLL Support
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
EXPORT double CustomSqrt(unsigned int input_numerator, int input_denominator) {
    // use the following Sqrt Approximation, lets use a first approximation, we'll use 4 as Starting Value, the starting value will be defined as x/y currently, so x/y=4, which means for now we heave x=8 and y=2
    // We will create the sqrt of Input_numerator/input_denominator, which we will call z_1/z_2 in the following Math Functions
    // We will calculate (z_1/z_2)/(x/y), which is (z_1/z_2)*(y/x), which is also (z_1*x)+(z_2*y), then we will add it to x/y, and half the whole thing, so we will have (z_1*x)+(z_2*y)+(x/y), we will use a/b * c/d = (a*d+c*b)/(b*d)
    // TODO: Finish Explanation
}