


// Constants for the center point (in decimal degrees)
const double centerLat = 3.0301;
const double centerLong = 103.3185;

// Radius of the circle in kilometers
const double radiusKm = 30.0;

// Function to convert degrees to radians
double degToRad(double degrees) {
  return degrees * PI / 180.0;
  }

  // Function to calculate the distance between two points using the Haversine formula
  double calculateDistance(double lat1, double long1, double lat2, double long2) {
    // Convert latitude and longitude from degrees to radians
      lat1 = degToRad(lat1);
        long1 = degToRad(long1);
          lat2 = degToRad(lat2);
            long2 = degToRad(long2);

              // Haversine formula
                double dLat = lat2 - lat1;
                  double dLong = long2 - long1;
                    double a = sin(dLat / 2) * sin(dLat / 2) + cos(lat1) * cos(lat2) * sin(dLong / 2) * sin(dLong / 2);
                      double c = 2 * atan2(sqrt(a), sqrt(1 - a));
                        double distanceKm = 6371 * c; // Earth's radius in km

                          return distanceKm;
                          }

                          void setup() {
                            Serial .begin(9600);
                            // Example point (latitude, longitude) to check
                              double pointLat = 3.021624;
                                double pointLong =103.302568;

                                  double distance = calculateDistance(centerLat, centerLong, pointLat, pointLong);

                                    if (distance <= radiusKm) {
                                        Serial.print("inside Kluang <30km, ");
                                        Serial.print(distance);
                                        Serial.print(" km");
                                              }else{Serial.print("outside Kluang >30km, ");
                                             Serial.print(distance);
                                             Serial.print("km");
                                                                                      }
                                              }

                                              void loop() {
                                                // Your Arduino loop code
                                                }
                                                