#ifndef LATTICE_MODEL_HPP_
#define LATTICE_MODEL_HPP_

#include <vector>

namespace iblbm
{
class LatticeModel
{
 public:
  LatticeModel(
      std::size_t num_dimension
    , std::size_t num_direction
    , std::size_t num_col
    , std::size_t num_row
    , double dx
    , double dt
    , const std::vector<double>& initial_velocity);

  /**
   * Virtual default destructor
   */
  virtual ~LatticeModel() = default;

  /**
   * Get functions
   */
  auto GetNumberOfDimension() const { return num_dimension_; }
  auto GetNumberOfDirection() const { return num_direction_; }
  auto GetNumberOfColumn() const { return num_col_; }
  auto GetNumberOfRow() const { return num_row_; }
  auto GetSpaceStep() const { return dx_; }
  auto GetTimeStep() const { return dt_; }
  auto GetLatticeSpeed() const { return c_; }
  auto GetVelocity() const { return u_; }
  auto GetDiscreteVelocity() const { return e_; }
  auto GetWeight() const { return omega_; }

 protected:
  /**
   * Number of dimensions for lattice model, 2 for D2Q9 model
   */
  std::size_t num_dimension_;

  /**
   * Number of direction for lattice model, 9 for D2Q9 model
   */
  std::size_t num_direction_;

  /**
   * Number of columns for the lattice model
   */
  std::size_t num_col_;

  /**
   * Number of rows for the lattice model
   */
  std::size_t num_row_;

  /**
   * Space step
   */
  double dx_;

  /**
   * Time step
   */
  double dt_;

  /**
   * Propagation speed in the lattice
   */
  double c_;

  /**
   * Weights of each discrete velocity
   */
  std::vector<double> omega_;

  /**
   * Vector of vectors to store the lattice velocity row-wise
   */
  std::vector<std::vector<double>> u_;

  /**
   * Discrete velocities
   */
  std::vector<std::vector<double>> e_;
};
}  // namespace iblbm

#endif // LATTICE_MODEL_HPP_
