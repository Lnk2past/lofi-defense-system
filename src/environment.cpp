#include <cmath>
#include "environment.h"

environment::environment(double d):
    air_density(d)
{}

vector_2d environment::get_drag_acceleration(const vector_2d &velocity, double mass, double area, double drag_coefficient) const
{
    auto coeff = 0.5 * air_density * drag_coefficient * area / mass;

    vector_2d drag_acceleration = {
        - std::copysign(coeff * velocity[0] * velocity[0], velocity[0]),
        - std::copysign(coeff * velocity[1] * velocity[1], velocity[1])
    };
    return drag_acceleration;
}