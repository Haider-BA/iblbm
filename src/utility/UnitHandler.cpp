#include "utility/UnitHandler.hpp"

#include <vector>

namespace iblbm
{
UnitHandler::UnitHandler(
    double x_physical
  , double y_physical
  , double t_physical
  , std::size_t num_cell
  , std::size_t num_iteration
  , const std::vector<double>& initial_velocity)
  : x_p_(x_physical),
    y_p_(y_physical),
    l_0_p_(x_p_ < y_p_ ? x_p_ : y_p_),
    t_0_p_(t_physical),
    x_d_(x_p_ / l_0_p_),
    y_d_(y_p_ / l_0_p_),
    dx_(1.0 / static_cast<double>(num_cell)),
    dt_(1.0 / static_cast<double>(num_iteration)),
    nx_(x_d_ * num_cell),
    ny_(y_d_ * num_cell),
    u_0_lb_()
{
  for (auto u : initial_velocity)
      u_0_lb_.push_back(u * t_0_p_ / l_0_p_ * dt_ / dx_);
}
}  // namespace iblbm
