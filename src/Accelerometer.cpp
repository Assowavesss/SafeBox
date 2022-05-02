#include "Accelerometer.h"
#include<Arduino.h>
#include<Wire.h>  // Wire library - used for I2C communication

#define ADXL345 0x53
#define POWER_CTL_REGISTER 0x2D
#define D3 8

#define ACCEL_XOUT_H 0x32

#define NB_REGISTER 6

#define NB_COUNT 256

// To avoid to write safebox::....
using namespace safebox;


Accelerometer::Accelerometer(void)
{
	  Wire.begin();
	  Wire.beginTransmission(ADXL345);
	  Wire.write(POWER_CTL_REGISTER);
	  Wire.write(D3);
	  Wire.endTransmission();
	  delay(10);
}


/**
 * @details
 */
bool Accelerometer::accident(void)
{
    return false;
}


/**
 * @details
 */
void Accelerometer::run(void) 
{
	  Wire.beginTransmission(ADXL345);
	  Wire.write(ACCEL_XOUT_H);
	  Wire.endTransmission(false);
	  Wire.requestFrom(ADXL345,NB_REGISTER,true);
	  x_out = (Wire.read() | Wire.read() << D3);
	  x_out /= NB_COUNT;
	  y_out = (Wire.read() | Wire.read() << D3);
	  y_out /= NB_COUNT;
	  z_out = (Wire.read() | Wire.read() << D3);
	  z_out /= NB_COUNT;
	  Serial.print("Xa= ");
	  Serial.print(x_out);
	  Serial.print("   Ya= ");
	  Serial.print(y_out);
	  Serial.print("   Za= ");
	  Serial.println(z_out);
}
