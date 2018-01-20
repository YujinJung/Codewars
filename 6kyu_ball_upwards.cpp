#include <cmath>

class Ball
{
public: 
  static int maxBall(int v0)
  {
    double gravity = 9.81;
    double vMeterPerSec = v0 * (1000.0 / 3600.0);
    
    double maxSec = std::round(10.0 * vMeterPerSec / gravity);
    
    return maxSec;
  }
};
