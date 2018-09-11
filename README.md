# UBC Sailbot Technical Quiz

__Author__: Tyler Lum

## StandardCalc

Implemented `StandardCalc` with the following methods:

```
float BoundTo180(float angle);
```

```
bool IsAngleBetween(float first_angle, float middle_angle, float second_angle);
```
************************************************************************
## Unit Tests

Unit tested these two methods with the Google Test Framework. To run the unit tests, run the following command from the `sailbots-application/StandardCalc` directory:

```
cmake CMakeLists.txt && make && ./runTests
``` 

Please ensure you have `Google Test` and `CMake` set up on your computer before running.
