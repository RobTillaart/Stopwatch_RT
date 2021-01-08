//
//    FILE: stopwatch_printable.ino
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: sample demo stopwatch class
//    DATE: 2021-01-08
//     URL: https://github.com/RobTillaart/StopWatch_RT


#include <StopWatch.h>


StopWatch stopwatch;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println(STOPWATCH_LIB_VERSION);

  stopwatch.start();
  delay(5000);
  Serial.print("TIME: ");
  Serial.println(stopwatch);  // printable interface
  Serial.print("TIME: ");
  Serial.println(stopwatch.elapsed());
}

void loop()
{
}

// -- END OF FILE --
