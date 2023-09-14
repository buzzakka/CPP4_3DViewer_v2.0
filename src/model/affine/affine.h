#ifndef CPP4_3DVIEWER_V2_0_2_MODEL_AFFINE_AFFINE_H_
#define CPP4_3DVIEWER_V2_0_2_MODEL_AFFINE_AFFINE_H_

#include <cmath>

#include "../struct.h"

namespace s21 {
class Affine {
 public:
  Affine() = default;
  ~Affine() = default;

  void Move(Data &data, const double &value, const Coord &coord) const noexcept;
  void Scale(Data &data, const double &value,
             const bool &is_div) const noexcept;
  void Rotate(Data &data, const double &value,
              const Coord &coord) const noexcept;

 private:
  const double cos_value_ = std::cos(1 * (M_PI / 180.0));
  const double sin_value_ = std::sin(1 * (M_PI / 180.0));
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_MODEL_AFFINE_AFFINE_H_
