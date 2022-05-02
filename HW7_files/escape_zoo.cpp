#include "escape_zoo.h"

motion_plan escape_route(grid const &M, coordinate init_coordinate, Heading init_heading) {

    // your implementation here
    size_t initialy = init_coordinate.first;
    size_t initialx = init_coordinate.second;
    if(M[initialy][initialx - 1] && M[initialy - 1][initialx]) return {}; // If immediate straight & left are blocked

    motion_plan plan;

    return plan; // don't forget to change this
}
