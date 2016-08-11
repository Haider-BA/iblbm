#include "lattice/LatticeD2Q9.hpp"

#include "utility/UnitHandler.hpp"

namespace iblbm
{
LatticeD2Q9::LatticeD2Q9(const UnitHandler& unit_handler)
  : LatticeModel(2u, 9u, unit_handler.GetNumColumn(), unit_handler.GetNumRow(),
        unit_handler.GetDx(), unit_handler.GetDt(),
        unit_handler.GetLatticeInitialVelocity())
{
  ;
}
}  // namespace iblbm
