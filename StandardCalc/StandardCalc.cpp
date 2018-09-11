#include "StandardCalc.h"

#include <cmath>

float StandardCalc::BoundTo180(float angle) {
  // if in range, return as is
  if (std::abs(angle) < 180.0) return angle;

  // remove extra full loops
  int numExtraLoops = angle / 360;  // rounds down
  float boundedAngle = angle - numExtraLoops * 360.0;  // negative sign self-handled

  // bound values with abs(angle) > 180
  if (boundedAngle > 180.0) {
    boundedAngle += -360.0;
  } else if (boundedAngle < -180.0) {
    boundedAngle += 360.0; 
  }
  
  return boundedAngle;
}

bool StandardCalc::IsAngleBetween(float first_angle, float middle_angle, float second_angle) {
  // bound angles in case of bad input
  first_angle = BoundTo180(first_angle);
  middle_angle = BoundTo180(middle_angle);
  second_angle = BoundTo180(second_angle);

  // if angle difference is 180, then there is no acute angle
  float angle_difference = std::abs(second_angle - first_angle);
  if (angle_difference == 180.0) return false;

  // if obtuse angle, then one angle must be negative. Turn that to positive
  else if (angle_difference > 180) {
    if (second_angle < 0) {
      second_angle += 360;
    } else if (first_angle < 0) {
      first_angle += 360;
    } else {}  // should never get here as long as BoundTo180 works

    // if obstuse angle, ensure middle_angle is in range (0 - 360)
    if (middle_angle < 0) middle_angle += 360;
  }

  // check if middle angle is between the two angles (exclusive)
  if (second_angle > first_angle) { 
    if (second_angle > middle_angle && middle_angle > first_angle) return true;
  }
  else if (second_angle < first_angle) {
    if (first_angle > middle_angle && middle_angle > second_angle) return true;
  }

  // if (middle angle) == (other angles) or (first angle) == (second angle), then always false
  return false;
}
