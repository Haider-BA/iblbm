#ifndef DEBUG_UTILITY_HPP_
#define DEBUG_UTILITY_HPP_

#include <iomanip>
#include <iostream>

namespace iblbm
{
namespace debug_util
{
template <typename T, typename U>
T Flip(
    const T& lattice
  , U nx)
{
  auto flipped_lattice(lattice);
  auto ny = lattice.size() / nx;
  for (auto n = 0u; n < lattice.size(); ++n)
      flipped_lattice[(ny - 1 - n / nx) * nx + n % nx] = lattice[n];
  return flipped_lattice;
}

template <typename T>
T Organise(const T& lattice)
{
  auto organised_lattice(lattice);
  for (auto i = 0u; i < lattice.size(); ++i) {
    organised_lattice[i][0] = lattice[i][6];
    organised_lattice[i][1] = lattice[i][2];
    organised_lattice[i][2] = lattice[i][5];
    organised_lattice[i][4] = lattice[i][0];
    organised_lattice[i][5] = lattice[i][1];
    organised_lattice[i][6] = lattice[i][7];
    organised_lattice[i][7] = lattice[i][4];
  }
  return organised_lattice;
}

template <typename T, typename U>
void Print(
    const T& lattice
  , U nx
  , U ny)
{
  auto depth = lattice[0].size();
  auto flag = depth + lattice.size() % (nx * ny);
  switch (flag) {
    case 2: {
      auto counter = 0;
      auto flipped_lattice = Flip(lattice, nx);
      for (auto node : flipped_lattice) {
        std::cout << std::fixed << std::setprecision(2) << node[0] << " " <<
            node[1] << "   ";
        if (++counter % nx == 0) std::cout << std::endl;
      }
      break;
    }
    case 9: {
      auto flipped_lattice = Flip(Organise(lattice), nx);
      for (auto y = 0u; y < ny; ++y) {
        for (auto i = 0; i < 9; i += 3) {
          for (auto x = 0u; x < nx; ++x) {
            auto n = y * nx + x;
            std::cout << std::fixed << std::setprecision(2) <<
                flipped_lattice[n][i] << " " << flipped_lattice[n][i + 1] <<
                " " << flipped_lattice[n][i + 2] << "   ";
          }
          std::cout << std::endl;
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
      break;
    }
    default: {
      break;
    }
  }
}
}
}  // namespace iblbm
#endif // DEBUG_UTILITY_HPP_
