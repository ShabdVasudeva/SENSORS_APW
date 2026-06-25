#include <stdint.h>
#ifndef SENSOR_APW_H
#define SENSOR_APW_H

#ifndef ARDUINO
  #include <cstdint>
#elif ARDUINO >= 100
  #include <Arduino.h>
  #include <Print.h>
#else
  #include <WProgram.h>
#endif

namespace SensorConstants {
  constexpr float EARTH_GRAVITY = 9.80665f;
  constexpr float MOON_GRAVITY = 1.6f;
  constexpr float SUN_GRAVITY = 275.0f;
  constexpr float STANDARD_GRAVITY = EARTH_GRAVITY;
  constexpr float MAX_MAGFIELD_EARTH = 60.0f;
  constexpr float MIN_MAGFIELD_EARTH = 30.0f;
  constexpr float PRESSURE_SEALEVELHPA = 1013.25f;
  constexpr float DP_TO_RAD = 0.017453293f;
  constexpr float RAD_TO_DP = 57.29577793f;
  constexpr int GAUSS_TO_MTESLA = 100;
}

enum class SensorType: int32_t {
  ACCELEROMETER       = 1,
  MAGNETIC_FIELD      = 2,
  ORIENTATION         = 3,
  GYROSCOPE           = 4,
  LIGHT               = 5,
  PRESSURE            = 6,
  PROXIMITY           = 8,
  GRAVITY             = 9,
  LINEAR_ACCELERATION = 10,
  ROTATION_VECTOR     = 11,
  RELATIVE_HUMIDITY   = 12,
  AMBIENT_TEMPERATURE = 13,
  OBJECT_TEMPERATURE  = 14,
  VOLTAGE             = 15,
  CURRENT             = 16,
  COLOR               = 17,
  TVOC                = 18,
  VOC_INDEX           = 19,
  NOX_INDEX           = 20,
  CO2                 = 21,
  ECO2                = 22,
  PM10_STD            = 23,
  PM25_STD            = 24,
  PM100_STD           = 25,
  PM10_ENV            = 26,
  PM25_ENV            = 27,
  PM100_ENV           = 28,
  GAS_RESISTANCE      = 29,
  UNITLESS_PERCENT    = 30,
  ALTITUDE            = 31
};

struct sensors_vec_t {
  union {
    float v[3];
    struct { float x; float y; float z; };
    struct { float roll; float pitch; float heading; };
  };

  int8_t status;
  uint8_t reserved[3];
};

struct sensors_color_t {
  union {
    float c[3];
    struct { float r; float g; float b; };
  };
  uint32_t rgba;
};

struct sensors_event_t {
  int32_t version; 
  int32_t sensor_id;
  int32_t type;
  int32_t reserved0;
  int32_t timestamp;
  union {
    float data[4];
    sensors_vec_t acceleration;
    sensors_vec_t magnetic;
    sensors_vec_t orientation;
    sensors_vec_t gyro;
    float temperature;
    float distance;
    float light;
    float pressure;
    float relative_humidity;
    float current;
    float voltage;
    float tvoc;
    float voc_index;
    float nox_index;
    float CO2;
    float eCO2;
    float pm10_std;
    float pm25_std;
    float pm100_std;
    float pm10_env;
    float pm25_env;
    float pm100_env;
    float gas_resistance;
    float unitless_percent;
    sensors_color_t color;
    float altitude;
  };
};

struct sensor_t {
  char name[16];
  int32_t version;
  int32_t sensor_id;
  int32_t type;
  int32_t min_display;
  float max_value;
  float min_value;
  float resolution;
};

class Sensor_APW {
public:
  Sensor_APW() = default;
  virtual ~Sensor_APW() = default;

  virtual void enableAutoRange(bool) {}
  virtual bool getEvent(sensors_event_t* event) const = 0;
  virtual void getSensor(sensor_t* sensor) const = 0;

  void printSensorDetails() const;
};

#endif