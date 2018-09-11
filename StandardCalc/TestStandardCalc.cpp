#include "StandardCalc.cpp"
#include <gtest/gtest.h>

TEST(BoundTo180Test, SmallAngles) {
  // return the same value
  StandardCalc standard_calc;
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(0), 0);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(10), 10);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(45), 45);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(105), 105);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(179), 179);

  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-10), -10);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-45), -45);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-105), -105);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-179), -179);
}

TEST(BoundTo180Test, BigPositiveAngles) { 
  StandardCalc standard_calc;
  // 180 < angle < 360
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(181), -179);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(220), -140);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(350), -10);

  // 360 < angle < 720
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(365), 5);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(450), 90);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(535), 175);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(545), -175);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(600), -120);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(710), -10);

  // angle > 720
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(750), 30);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(360 * 3 + 30), 30);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(360 * 7 - 100), -100);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(360 * 10 + 187), -173);
}

TEST(BoundTo180Test, BigNegativeAngles) {
  StandardCalc standard_calc;
  // -180 > angle > -360
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(181), -179);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-181), 179);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-220), 140);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-350), 10);

  // -360 > angle > -720
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-365), -5);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-450), -90);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-535), -175);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-545), 175);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-600), 120);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-710), 10);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-750), -30);

  // angle < -720
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-750), -30);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-360 * 3 - 30), -30);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-360 * 7 + 100), + 100);
  EXPECT_FLOAT_EQ(standard_calc.BoundTo180(-360 * 10 - 187), 173);
}

TEST(IsAngleBetweenTest, SmallAngles) {
  StandardCalc standard_calc;
  // acute, abs(first-second) < 180
  EXPECT_TRUE(standard_calc.IsAngleBetween(0, 10, 90));
  EXPECT_TRUE(standard_calc.IsAngleBetween(90, 10, 0));
  EXPECT_FALSE(standard_calc.IsAngleBetween(0, 90, 10));
  EXPECT_FALSE(standard_calc.IsAngleBetween(10, 90, 0));

  EXPECT_TRUE(standard_calc.IsAngleBetween(0, -10, -90));
  EXPECT_TRUE(standard_calc.IsAngleBetween(-90, -10, 0));
  EXPECT_FALSE(standard_calc.IsAngleBetween(0, -90, -10));
  EXPECT_FALSE(standard_calc.IsAngleBetween(-10, -90, 0));
}

TEST(IsAngleBetweenTest, BigAngles) {
  StandardCalc standard_calc;
  // obtuse, abs(first-second) > 180
  EXPECT_TRUE(standard_calc.IsAngleBetween(110, -180, -90));
  EXPECT_TRUE(standard_calc.IsAngleBetween(-90, -180, 110));
  EXPECT_FALSE(standard_calc.IsAngleBetween(80, -180, -90));
  EXPECT_FALSE(standard_calc.IsAngleBetween(-90, -180, 80));

  EXPECT_TRUE(standard_calc.IsAngleBetween(-70, -100, -170));
  EXPECT_TRUE(standard_calc.IsAngleBetween(-170, -100, -70));
  EXPECT_FALSE(standard_calc.IsAngleBetween(100, 0, -170));
  EXPECT_TRUE(standard_calc.IsAngleBetween(100, 120, -170));
}

TEST(IsAngleBetweenTest, EdgeCaseAngles) {
  StandardCalc standard_calc;
  // middle angle equals first or second
  EXPECT_FALSE(standard_calc.IsAngleBetween(0, 0, 90));
  EXPECT_FALSE(standard_calc.IsAngleBetween(170, 100, 100));
  EXPECT_FALSE(standard_calc.IsAngleBetween(-10, -10, -10));

  // close angles
  EXPECT_TRUE(standard_calc.IsAngleBetween(-2,-1,0));

  // first and second angle 180 degrees apart
  EXPECT_FALSE(standard_calc.IsAngleBetween(-90, 0, 90));
  EXPECT_FALSE(standard_calc.IsAngleBetween(0, 10, 180));
  EXPECT_FALSE(standard_calc.IsAngleBetween(0, -10, 180));

  // -180 and 180
  EXPECT_FALSE(standard_calc.IsAngleBetween(-180, 10, 180));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
