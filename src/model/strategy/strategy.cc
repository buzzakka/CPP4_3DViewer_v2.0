#include "strategy.h"

namespace s21 {
// ================================ S C A L E ================================
ScaleStrategy::ScaleStrategy(Data &data, Affine &affine)
    : data_(data), affine_(affine) {}

void ScaleStrategy::Transform(const double &value, const Action &act) {
  if (act == kScaleP)
    affine_.Scale(data_, value, false);
  else if (act == kScaleM)
    affine_.Scale(data_, value, true);
}

// ================================= M O V E =================================
MoveStrategy::MoveStrategy(Data &data, Affine &affine)
    : data_(data), affine_(affine) {}

void MoveStrategy::Transform(const double &value, const Action &act) {
  if (act == kMoveX)
    affine_.Move(data_, value, kX);
  else if (act == kMoveY)
    affine_.Move(data_, value, kY);
  else if (act == kMoveZ)
    affine_.Move(data_, value, kZ);
}

// =============================== R O T A T E ===============================
RotateStrategy::RotateStrategy(Data &data, Affine &affine)
    : data_(data), affine_(affine) {}

void RotateStrategy::Transform(const double &value, const Action &act) {
  if (act == kRotX)
    affine_.Rotate(data_, value, kX);
  else if (act == kRotY)
    affine_.Rotate(data_, value, kY);
  else if (act == kRotZ)
    affine_.Rotate(data_, value, kZ);
}
}  // namespace s21
