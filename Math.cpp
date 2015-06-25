#include <math.h>

#include "Math.hpp"

using namespace math;

double Math::GetCircleCircumference(double radius)
{
    const double pi = 3.1415926535897;
    return 2 * pi * radius;
}

static double Exponential(double base, double exponent)
{
    return pow(base, exponent);
}