#include <Arduino.h>

// Structure to define a vertex
struct Vertex {
  double lat;
    double lon;
    };

    // Structure to define a polygon
    struct Polygon {
      Vertex vertices[100]; // Replace 5 with the number of vertices in your polygon
        const char *name;
        const char *country ;
        const char *tz;
        };

        // Define the polygon by specifying its vertices
        Polygon areaPolygon = {
          {
             {1.987145,103.228983},  // Vertex 1
                  // Add the other vertices of the polygon here
                  {1.997003,103.233191},
                  {1.964316,103.224380},
                  {1.953059,103.230805},
                  {1.978673,103.281930},
                  {1.978265,103.333946},
                  {1.988707,103.356323},
                  {2.023639,103.388601},
                  {2.044322,103.372261},
                  {2.057705,103.374492},
                  {2.069414,103.364174},
                  {2.082981,103.334726},
                  {2.083125,103.305945},
                  {2.095249,103.268786},
                  {2.087878,103.263349},
                  {2.066130,103.283407},
                  {2.023083,103.275859},

                    },
                      "Kluang"
                      ," ,Malaysia ",", U+8"};

                      // Function to check if a point is inside the polygon
                      bool isPointInsidePolygon(double lat, double lon, Polygon polygon) {
                        bool isInside = false;
                          int numVertices = sizeof(polygon.vertices) / sizeof(polygon.vertices[0]);

                            for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {
                                double xi = polygon.vertices[i].lon;
                                    double yi = polygon.vertices[i].lat;
                                        double xj = polygon.vertices[j].lon;
                                            double yj = polygon.vertices[j].lat;

                                                if ((yi > lat) != (yj > lat) &&
                                                        (lon < (xj - xi) * (lat - yi) / (yj - yi) + xi)) {
                                                              isInside = !isInside;
                                                                  }
                                                                    }

                                                                      return isInside;
                                                                      }

                                                                      void setup() {
                                                                        double pointLat = 1.987265; // Example point to check
                                                                          double pointLon = 103.235119;

                                                                            bool isInsidePolygon = isPointInsidePolygon(pointLat, pointLon, areaPolygon);

                                                                              Serial.begin(9600);
                                                                                if (isInsidePolygon) {
                                                                                    Serial.println("Point is inside the predefined area: " + String(areaPolygon.name)+String(areaPolygon.country)+String(areaPolygon.tz));
                                                                                      } else {
                                                                                          Serial.println("Point is not inside the predefined area.");
                                                                                            }
                                                                                            }

                                                                                            void loop() {
                                                                                              // Your Arduino loop code
                                                                                              }
                                                                                              