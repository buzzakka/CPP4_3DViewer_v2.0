#include <gtest/gtest.h>

#include "../model/affine/affine.h"
#include "../model/parser/parser.h"

namespace s21 {
class Test {
 public:
  Data data;
  std::unique_ptr<Parser> pars;
  Affine affine;

  Test(Data& data) { pars = std::make_unique<Parser>(data); }
};
}  // namespace s21

TEST(Parser, parser_1) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  EXPECT_EQ(test.data.v_count, 8);
  EXPECT_EQ(test.data.e_count, 18);
  EXPECT_EQ(test.data.far, (0.5 * 1.5 + 10) * 10);
  EXPECT_EQ(test.data.near, 0.5 * 1.5 / (2 * tan(60.0 * M_PI / 180 / 2)));
  EXPECT_EQ(test.data.max_coord, 0.5 * 1.5);
}

TEST(Parser, parser_2) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  std::vector<int> facets = {
      0, 6, 6, 4, 4, 0, 0, 2, 2, 6, 6, 0, 0, 3, 3, 2, 2, 0, 0, 1, 1, 3, 3, 0,
      2, 7, 7, 6, 6, 2, 2, 3, 3, 7, 7, 2, 4, 6, 6, 7, 7, 4, 4, 7, 7, 5, 5, 4,
      0, 4, 4, 5, 5, 0, 0, 5, 5, 1, 1, 0, 1, 3, 3, 7, 7, 1, 1, 7, 7, 5, 5, 1};
  std::vector<double> vertexes = {
      -0.5, -0.5, -0.5, -0.5, -0.5, 0.5, -0.5, 0.5, -0.5, -0.5, 0.5, 0.5,
      0.5,  -0.5, -0.5, 0.5,  -0.5, 0.5, 0.5,  0.5, -0.5, 0.5,  0.5, 0.5};
  EXPECT_EQ(test.data.facets, facets);
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, move_x) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Move(test.data, 3, kX);
  std::vector<double> vertexes = {2.5,  -0.5, -0.5, 2.5, -0.5, 0.5,  2.5,  0.5,
                                  -0.5, 2.5,  0.5,  0.5, 3.5,  -0.5, -0.5, 3.5,
                                  -0.5, 0.5,  3.5,  0.5, -0.5, 3.5,  0.5,  0.5};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, move_y) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Move(test.data, 3, kY);
  std::vector<double> vertexes = {-0.5, 2.5,  -0.5, -0.5, 2.5,  0.5, -0.5, 3.5,
                                  -0.5, -0.5, 3.5,  0.5,  0.5,  2.5, -0.5, 0.5,
                                  2.5,  0.5,  0.5,  3.5,  -0.5, 0.5, 3.5,  0.5};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, move_z) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Move(test.data, 3, kZ);
  std::vector<double> vertexes = {-0.5, -0.5, 2.5, -0.5, -0.5, 3.5,  -0.5, 0.5,
                                  2.5,  -0.5, 0.5, 3.5,  0.5,  -0.5, 2.5,  0.5,
                                  -0.5, 3.5,  0.5, 0.5,  2.5,  0.5,  0.5,  3.5};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, rotate_x) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Rotate(test.data, 90, kX);
  std::vector<double> vertexes = {
      -0.5, 0.28543444209956237,  -1.2852821372559537,
      -0.5, -1.2852821372559537,  -0.28543444209956237,
      -0.5, 1.2852821372559537,   0.28543444209956237,
      -0.5, -0.28543444209956237, 1.2852821372559537,
      0.5,  0.28543444209956237,  -1.2852821372559537,
      0.5,  -1.2852821372559537,  -0.28543444209956237,
      0.5,  1.2852821372559537,   0.28543444209956237,
      0.5,  -0.28543444209956237, 1.2852821372559537};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, rotate_y) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Rotate(test.data, 90, kY);
  std::vector<double> vertexes = {
      -1.2852821372559537,  -0.5, 0.28543444209956237,
      0.28543444209956237,  -0.5, 1.2852821372559537,
      -1.2852821372559537,  0.5,  0.28543444209956237,
      0.28543444209956237,  0.5,  1.2852821372559537,
      -0.28543444209956237, -0.5, -1.2852821372559537,
      1.2852821372559537,   -0.5, -0.28543444209956237,
      -0.28543444209956237, 0.5,  -1.2852821372559537,
      1.2852821372559537,   0.5,  -0.28543444209956237};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, rotate_z) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Rotate(test.data, 90, kZ);
  std::vector<double> vertexes = {
      0.28543444209956237,  -1.2852821372559537,  -0.5,
      0.28543444209956237,  -1.2852821372559537,  0.5,
      -1.2852821372559537,  -0.28543444209956237, -0.5,
      -1.2852821372559537,  -0.28543444209956237, 0.5,
      1.2852821372559537,   0.28543444209956237,  -0.5,
      1.2852821372559537,   0.28543444209956237,  0.5,
      -0.28543444209956237, 1.2852821372559537,   -0.5,
      -0.28543444209956237, 1.2852821372559537,   0.5};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, scale_div) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Scale(test.data, 10, 1);
  std::vector<double> vertexes = {-0.05, -0.05, -0.05, -0.05, -0.05, 0.05,
                                  -0.05, 0.05,  -0.05, -0.05, 0.05,  0.05,
                                  0.05,  -0.05, -0.05, 0.05,  -0.05, 0.05,
                                  0.05,  0.05,  -0.05, 0.05,  0.05,  0.05};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

TEST(Affine, scale_not_div) {
  s21::Test test(test.data);
  test.pars->Parse("cube.txt");
  test.affine.Scale(test.data, 10, 0);
  std::vector<double> vertexes = {-5, -5, -5, -5, -5, 5, -5, 5, -5, -5, 5, 5,
                                  5,  -5, -5, 5,  -5, 5, 5,  5, -5, 5,  5, 5};
  EXPECT_EQ(test.data.vertexes, vertexes);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
