// Define the vertices for the first polygon
int poly1Y[] = {0,10,10,20,20,30,30,0};
int poly1X[] = {0, 0,15,15,10,10,30,30};
int numVertices1 = 8;

// Define the vertices for the second polygon
int poly2Y[] = {10,10,20,20};
int poly2X[] = {0, 15,15, 0};
int numVertices2 = 4;

// Define the point to check
int pointY = 15;//35
int pointX = 10;//25

void setup() {
  Serial.begin(9600);
  Serial.println("Decode");
  }

  void loop() {
    // Check if the point is inside the first polygon
      if (isPointInPolygon(pointX, pointY, poly1X, poly1Y, numVertices1)) {
          Serial.println("Point is inside polygon 1");
            }
              // Check if the point is inside the second polygon
               else if (isPointInPolygon(pointX, pointY, poly2X, poly2Y, numVertices2)) {
                    Serial.println("Point is inside polygon 2");
                      }
                      else{Serial.println("Undefined Area");}
                        delay(1000);
                        }

                        // Function to check if a point is inside a polygon
                        bool isPointInPolygon(int x, int y, int* polyX, int* polyY, int numVertices) {
                          bool inside = false;
                            for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {
                                if (((polyY[i] > y) != (polyY[j] > y)) &&
                                        (x < (polyX[j] - polyX[i]) * (y - polyY[i]) / (polyY[j] - polyY[i]) + polyX[i])) {
                                              inside = !inside;
                                                  }
                                                    }
                                                      return inside;
                                                      }
                                                      