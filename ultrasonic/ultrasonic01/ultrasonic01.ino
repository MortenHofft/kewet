#include <RunningMedian.h>
#include <NewPing.h>
 
#define TRIGGER_PIN  7
#define ECHO_PIN     8
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

RunningMedian samples = RunningMedian(5);

void setup() {
  Serial.begin(115200);
}
 
void loop() {
  delay(50);
  int uS = sonar.ping();
  if (uS > 0) {
    samples.add( uS / US_ROUNDTRIP_CM );
  }
  float m = samples.getMedian();
  Serial.print("Ping: ");
  Serial.print(" ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.print(" ");
  Serial.print(m);
  Serial.println(" median");
}
