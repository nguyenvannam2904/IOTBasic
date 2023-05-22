int R1 = 2;
int Y1 = 3;
int G1 = 4;
int R2 = 5;
int Y2 = 6;
int G2 = 7;
int DELAY_RED = 5000;
int DELAY_YELLOW = 2000;
int DELAY_GREEN = 5000;

// basic functions
void setup() {
  pinMode(G1, OUTPUT);
  pinMode(Y1, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  green_light();
  delay(DELAY_GREEN);
  Serial.println("Green Done");

  yellow_light();
  delay(DELAY_YELLOW);
  Serial.println("Yellow Done");

  red_light();
  delay(DELAY_RED);
  Serial.println("Red Done");
}

void green_light() {
  digitalWrite(G1, HIGH);
  digitalWrite(Y1, LOW);
  digitalWrite(R1, LOW);
  digitalWrite(G2, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(R2, HIGH);
}

void yellow_light() {
  digitalWrite(G1, LOW);
  digitalWrite(Y1, HIGH);
  digitalWrite(R1, LOW);

  digitalWrite(G2, LOW);
  digitalWrite(Y2, HIGH);
  digitalWrite(R2, LOW);
}

void red_light() {
  digitalWrite(G1, LOW);
  digitalWrite(Y1, LOW);
  digitalWrite(R1, HIGH);


  digitalWrite(G2, HIGH);
  digitalWrite(Y2, LOW);
  digitalWrite(R2, LOW);
}