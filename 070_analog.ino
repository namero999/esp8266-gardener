#define MUX_SEL_A D7
#define MUX_SEL_B D6
#define MUX_SEL_C D5

void setupMultiplexer() {
  pinMode(A0, INPUT); // Output of multiplexer
  pinMode(MUX_SEL_A, OUTPUT);
  pinMode(MUX_SEL_B, OUTPUT);
  pinMode(MUX_SEL_C, OUTPUT);
  digitalWrite(MUX_SEL_A, LOW);
  digitalWrite(MUX_SEL_B, LOW);
  digitalWrite(MUX_SEL_C, LOW);
}

void readMux() {

  digitalWrite(MUX_SEL_A, LOW);
  delay(40);
  env.light = analogRead(A0);

  digitalWrite(MUX_SEL_A, HIGH);
  delay(40);
  env.soil = analogRead(A0);

}
