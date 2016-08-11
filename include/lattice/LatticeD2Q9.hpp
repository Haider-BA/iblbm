#ifndef LATTICE_D2Q9_HPP_
#define LAttice_D2Q9_HPP_

#include "lattice/LatticeModel.hpp"
#include "utility/UnitHandler.hpp"

namespace iblbm
{
class LatticeD2Q9: public LatticeModel
{
 public:
  LatticeD2Q9(const UnitHandler& unit_handler);

  ~LatticeD2Q9() = default;
};
}  // namespace iblbm
#endif // LATTICE_D2Q9_HPP_
