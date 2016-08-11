#include "lattice/LatticeModel.hpp"

#include <stdexcept>
#include <vector>

namespace iblbm
{
LatticeModel::LatticeModel(
    std::size_t num_dimension
  , std::size_t num_direction
  , std::size_t num_col
  , std::size_t num_row
  , double dx
  , double dt
  , const std::vector<double>& initial_velocity)
  : num_dimension_(num_dimension),
    num_direction_(num_direction),
    num_col_(num_col),
    num_row_(num_row),
    dx_(dx),
    dt_(dt),
    c_(dx_ / dt_),
    omega_(),
    u_(),
    e_()
{
  if (initial_velocity.size() != num_dimension_)
      throw std::runtime_error("Initial velocity dimension mismatch");
  u_.assign(num_row_ * num_col_, initial_velocity);
}
}  // namespace iblbm
