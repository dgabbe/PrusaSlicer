#ifndef SLAROTFINDER_HPP
#define SLAROTFINDER_HPP

#include <functional>
#include <array>

namespace Slic3r {

class ModelObject;

namespace sla {

/**
  * The function should find the best rotation for SLA upside down printing.
  *
  * @param modelobj The model object representing the 3d mesh.
  * @param stopcond A function that if returns true, the search process will be
  * terminated and the best solution found will be returned.
  *
  * @return Returns the rotations around each axis (x, y, z)
  */
std::array<double, 3> find_best_rotation(
        const ModelObject& modelobj,
        float accuracy = .0f,
        std::function<void(unsigned)> statuscb = [] (unsigned) {},
        std::function<bool()> stopcond = [] () { return false; }
        );

}
}

#endif // SLAROTFINDER_HPP
