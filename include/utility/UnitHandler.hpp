#ifndef UNIT_HANDLER_HPP_
#define UNIT_HANDLER_HPP_

#include <vector>

namespace iblbm
{
class UnitHandler
{
 public:
  UnitHandler(
      double x_physical
    , double y_physical
    , double t_physical
    , std::size_t num_cell
    , std::size_t num_iteration
    , const std::vector<double>& initial_velocity);
  ~UnitHandler() = default;

  auto GetPhysicalX() const { return x_p_; }
  auto GetPhysicalY() const { return y_p_; }
  auto GetPhysicalCharacteristicLength() const { return l_0_p_; }
  auto GetPhysicalCharacteristicTime() const { return t_0_p_; }
  auto GetDimensionlessX() const { return x_d_; }
  auto GetDimensionlessY() const { return y_d_; }
  auto GetDx() const { return dx_; }
  auto GetDt() const { return dt_; }
  auto GetNumColumn() const { return nx_; }
  auto GetNumRow() const { return ny_; }
  auto GetLatticeInitialVelocity() const { return u_0_lb_; }

 private:
  double x_p_;
  double y_p_;
  double l_0_p_;
  double t_0_p_;
  double x_d_;
  double y_d_;
  double dx_;
  double dt_;
  std::size_t nx_;
  std::size_t ny_;
  std::vector<double> u_0_lb_;
};
}  // namespace iblbm
#endif  // UNIT_HANDLER_HPP_
