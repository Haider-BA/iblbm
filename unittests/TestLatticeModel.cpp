#include <iostream>

#include "lattice/LatticeD2Q9.hpp"
#include "lattice/LatticeModel.hpp"
#include "UnitTest++.h"
#include "utility/DebugUtility.hpp"
#include "utility/UnitHandler.hpp"

namespace iblbm
{
SUITE(LatticeModel)
{
TEST(LatticeModel_Initialisation)
{
  auto x_p = 4.5;
  auto y_p = 2.0;
  auto t_p = 10.0;
  std::size_t num_cell = 4;
  std::size_t num_iteration = 20;
  std::vector<double> u_0 = {0.1, 0.2};
  UnitHandler unit_handler(x_p, y_p, t_p, num_cell, num_iteration, u_0);
  LatticeD2Q9 lm(unit_handler);
  debug_util::Print(lm.GetVelocity(), unit_handler.GetNumColumn(),
      unit_handler.GetNumRow());
//  std::cout << "hi" << std::endl;
}
}  // suite
}  // namespace iblbm
