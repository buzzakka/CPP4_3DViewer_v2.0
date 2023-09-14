#include "affine.h"

namespace s21 {
void Affine::Move(Data &data, const double &value,
                  const Coord &coord) const noexcept {
  for (int i = 0; i < data.v_count; i++) data.vertexes[i * 3 + coord] += value;
}

void Affine::Rotate(Data &data, const double &value,
                    const Coord &coord) const noexcept {
  if (coord == kX) {
    for (int i = 0; i < data.v_count; ++i) {
      double *vertex = &data.vertexes[i * 3];
      double y = vertex[1];
      double z = vertex[2];
      vertex[1] = cos_value_ * y - (sin_value_ * value) * z;
      vertex[2] = cos_value_ * z + (sin_value_ * value) * y;
    }
  } else if (coord == kY) {
    for (int i = 0; i < data.v_count; ++i) {
      double *vertex = &data.vertexes[i * 3];
      double x = vertex[0];
      double z = vertex[2];
      vertex[0] = cos_value_ * x + (sin_value_ * value) * z;
      vertex[2] = cos_value_ * z - (sin_value_ * value) * x;
    }
  } else if (coord == kZ) {
    for (int i = 0; i < data.v_count; ++i) {
      double *vertex = &data.vertexes[i * 3];
      double x = vertex[0];
      double y = vertex[1];
      vertex[0] = cos_value_ * x - (sin_value_ * value) * y;
      vertex[1] = cos_value_ * y + (sin_value_ * value) * x;
    }
  }
}

void Affine::Scale(Data &data, const double &value,
                   const bool &is_div) const noexcept {
  double scale_factor = is_div ? 1.0 / value : value;
  for (double &vertex : data.vertexes) vertex *= scale_factor;
}
}  // namespace s21
