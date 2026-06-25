#include <Arduino.h>
#include "sensor_apw.h"

void Sensor_APW::printSensorDetails() const {
  sensor_t sensor;
  getSensor(&sensor);
  
  Serial.println(F("####################################"));
  Serial.print(F("Sensor:       "));
  Serial.println(sensor.name);
  Serial.print(F("Type:         "));

  switch((SensorType)sensor.type) {
    case SensorType::ACCELEROMETER:
      Serial.print(F("Acceleration (m/s²)"));
      break;
    case SensorType::MAGNETIC_FIELD:
      Serial.print(F("Magnetic (uT)"));
        break;
    case SensorType::ORIENTATION:
      Serial.print(F("Orientation (degrees)"));
      break;
    case SensorType::GYROSCOPE:
      Serial.print(F("Gyroscopic (rad/s)"));
      break;
    case SensorType::LIGHT:
      Serial.print(F("Light (lux)"));
      break;
    case SensorType::PRESSURE:
      Serial.print(F("Pressure (hPa)"));
      break;
    case SensorType::PROXIMITY:
      Serial.print(F("Distance (cm)"));
      break;
    case SensorType::GRAVITY:
      Serial.print(F("Gravity (m/s2)"));
      break;
    case SensorType::LINEAR_ACCELERATION:
      Serial.print(F("Linear Acceleration (m/s2)"));
      break;
    case SensorType::ROTATION_VECTOR:
      Serial.print(F("Rotation vector"));
      break;
    case SensorType::RELATIVE_HUMIDITY:
      Serial.print(F("Relative Humidity (%)"));
      break;
    case SensorType::AMBIENT_TEMPERATURE:
      Serial.print(F("Ambient Temp (C)"));
      break;
    case SensorType::OBJECT_TEMPERATURE:
      Serial.print(F("Object Temp (C)"));
      break;
    case SensorType::VOLTAGE:
      Serial.print(F("Voltage (V)"));
      break;
    case SensorType::CURRENT:
      Serial.print(F("Current (mA)"));
      break;
    case SensorType::COLOR:
      Serial.print(F("Color (RGBA)"));
      break;
    case SensorType::TVOC:
      Serial.print(F("Total Volatile Organic Compounds (ppb)"));
      break;
    case SensorType::VOC_INDEX:
      Serial.print(F("Volatile Organic Compounds (Index)"));
      break;
    case SensorType::NOX_INDEX:
      Serial.print(F("Nitrogen Oxides (Index)"));
      break;
    case SensorType::CO2:
      Serial.print(F("Carbon Dioxide (ppm)"));
      break;
    case SensorType::ECO2:
      Serial.print(F("Equivalent/estimated CO2 (ppm)"));
      break;
    case SensorType::PM10_STD:
      Serial.print(F("Standard Particulate Matter 1.0 (ppm)"));
      break;
    case SensorType::PM25_STD:
      Serial.print(F("Standard Particulate Matter 2.5 (ppm)"));
      break;
    case SensorType::PM100_STD:
      Serial.print(F("Standard Particulate Matter 10.0 (ppm)"));
      break;
    case SensorType::PM10_ENV:
      Serial.print(F("Environmental Particulate Matter 1.0 (ppm)"));
      break;
    case SensorType::PM25_ENV:
      Serial.print(F("Environmental Particulate Matter 2.5 (ppm)"));
      break;
    case SensorType::PM100_ENV:
      Serial.print(F("Environmental Particulate Matter 10.0 (ppm)"));
      break;
    case SensorType::GAS_RESISTANCE:
      Serial.print(F("Gas Resistance (ohms)"));
      break;
    case SensorType::UNITLESS_PERCENT:
      Serial.print(F("Unitless Percent (%)"));
      break;
    case SensorType::ALTITUDE:
      Serial.print(F("Altitude (m)"));
      break;
  }

  Serial.println();
  Serial.print(F("Driver Ver:   "));
  Serial.println(sensor.version);
  Serial.print(F("Unique ID:    "));
  Serial.println(sensor.sensor_id);
  Serial.print(F("Min Value:    "));
  Serial.println(sensor.min_value);
  Serial.print(F("Max Value:    "));
  Serial.println(sensor.max_value);
  Serial.print(F("Resolution:   "));
  Serial.println(sensor.resolution);
  Serial.println(F("####################################\n"));
}