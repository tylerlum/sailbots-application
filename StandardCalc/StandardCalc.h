#ifndef STANDARD_CALC_H_
#define STANDARD_CALC_H_

class StandardCalc {
public:

  /**
   * Bounds the provided angle between [-180, 180] degrees.
   * Ex. 360 becomes 0, 270 becomes -90, -450 becomes -90.
   * @param angle Input angle in degrees.
   * @return The bounded angle in degrees.
   */
  float BoundTo180(float angle);

  /**
   * Determines whether |middle_angle| is in the acute angle between the other two bounding angles.
   * Note: Input angles are bounded to 180 for safety.
   * Ex. -180 is between -90 and 110 but not between -90 and 80.
   * @param first_angle First angle in degrees.
   * @param middle_angle Middle angle in degrees.
   * @param second_angle Second angle in degrees.
   * @return Whether |middle_angle| is between |first_angle| and |second_angle| (exclusive).
   *         If |first_angle| and |second_angle| are 180 degrees apart
   *         then there is no acute angle, so returns false.
   */
  bool IsAngleBetween(float first_angle, float middle_angle, float second_angle);
};

#endif
