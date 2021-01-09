//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-01-08
// PURPOSE: unit tests for the StopWatch library
//          https://github.com/RobTillaart/StopWatch_RT
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "StopWatch.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  fprintf(stderr, "VERSION: %s\n", STOPWATCH_LIB_VERSION);

  StopWatch stopwatch0 = StopWatch();

  assertFalse(stopwatch0.isRunning());
  assertEqual(StopWatch::RESET, stopwatch0.state());
  assertEqual(StopWatch::MILLIS, stopwatch0.resolution());

  StopWatch stopwatch1(StopWatch::MICROS);
  assertEqual(StopWatch::MICROS, stopwatch1.resolution());

  StopWatch stopwatch2(StopWatch::SECONDS);
  assertEqual(StopWatch::SECONDS, stopwatch2.resolution());
  
  StopWatch stopwatch3(StopWatch::MINUTES);
  assertEqual(StopWatch::MINUTES, stopwatch3.resolution());
}


unittest(test_run)
{
  StopWatch sw;

  sw.start();
  delay(101);
  assertTrue(sw.isRunning());
  assertEqual(StopWatch::RUNNING, sw.state());
  assertLessOrEqual(100, sw.elapsed());

  sw.stop();
  assertFalse(sw.isRunning());
  assertEqual(StopWatch::STOPPED, sw.state());

  uint32_t ti = sw.elapsed();
  sw.start();
  delay(10);
  assertTrue(sw.isRunning());
  assertLessOrEqual(110, sw.elapsed());

  sw.reset();
  assertFalse(sw.isRunning());
  assertEqual(StopWatch::RESET, sw.state());
}


unittest(test_resolution)
{
  StopWatch sw;

  sw.setResolution(StopWatch::MICROS);
  assertEqual(StopWatch::MICROS, sw.resolution());

  sw.setResolution(StopWatch::MILLIS);
  assertEqual(StopWatch::MILLIS, sw.resolution());

  sw.setResolution(StopWatch::SECONDS);
  assertEqual(StopWatch::SECONDS, sw.resolution());

  sw.setResolution(StopWatch::MINUTES);
  assertEqual(StopWatch::MINUTES, sw.resolution());
}


unittest_main()

// --------
