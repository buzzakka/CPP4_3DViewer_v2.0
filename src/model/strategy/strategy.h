#ifndef CPP4_3DVIEWER_V2_0_2_MODEL_STRATEGY_STRATEGY_H_
#define CPP4_3DVIEWER_V2_0_2_MODEL_STRATEGY_STRATEGY_H_

#include "../affine/affine.h"
#include "../struct.h"

namespace s21 {
// ============================== V I R T U A L ==============================
class Strategy {
 public:
  virtual ~Strategy() = default;
  virtual void Transform(const double &value, const Action &act) = 0;
};

// ================================ S C A L E ================================
class ScaleStrategy : public Strategy {
 public:
  ScaleStrategy(Data &data, Affine &affine);
  void Transform(const double &value, const Action &act) override;

 private:
  Data &data_;
  Affine &affine_;
};

// ================================= M O V E =================================
class MoveStrategy : public Strategy {
 public:
  MoveStrategy(Data &data, Affine &affine);
  void Transform(const double &value, const Action &act) override;

 private:
  Data &data_;
  Affine &affine_;
};

// =============================== R O T A T E ===============================
class RotateStrategy : public Strategy {
 public:
  RotateStrategy(Data &data, Affine &affine);
  void Transform(const double &value, const Action &act) override;

 private:
  Data &data_;
  Affine &affine_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_2_MODEL_STRATEGY_STRATEGY_H_
