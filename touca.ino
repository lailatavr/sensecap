#define trigPin 2      // Pin TRIG do Sensor Ultrassonico 
#define echoPin 3      // Pin ECHO  do Sensor Ultrassonico 
#define buzzerPin 4    // Pin + Buzzer
#define MAX_DIST   400   // alcance máximo do HC-SR04 em cm
#define TIMEOUT_US 30000 // 30 ms ≈ 500 cm de ida+volta

uint32_t duration;
uint32_t distance;

// ------- estado do buzzer ------//
unsigned long lastToggle  = 0;
bool          buzzerState = false;
bool          buzzerOn    = false; // fase atual: HIGH ou LOW
int           buzzerInterval = 0; // duração da fase atual em ms

// ── controle de print serial ─────//
unsigned long lastPrint = 0;
const int PRINT_INTERVAL = 200; // imprime a cada 200 ms

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // Disparo do pulso ultrassônico 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leitura echo
  duration = pulseIn(echoPin, HIGH, 30000); // 30ms = ~500cm

  distance = (duration == 0) ? 0 : duration / 58; // Converte para cm

  // ------- controle do serial print -----//
  unsigned long now = millis();
  if (now - lastPrint >= PRINT_INTERVAL) {
    lastPrint = now;
    if (distance == 0){
      Serial.println("Sem leitura (timeout)");}
    else {
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
    }
  }

  // ── lógica do buzzer (não-bloqueante) ─────────────
  bool obstacle = (distance > 0 && distance <= 50);

  // Detecção de obstáculos com controle de intensidade do buzzer
  if (!obstacle){
    // sem obstáculo: desliga e reseta estado
    digitalWrite(buzzerPin, LOW);
    buzzerState = false;
    buzzerOn    = false;
   }

  else{
    int dist_c = constrain((int)distance, 1, 50);
    int pauseTime = map(dist_c, 6, 50, 50, 400); // 1 cm=50ms, 50 cm=400ms
    unsigned long elapsed = now - lastToggle;
    int phase = buzzerOn ? 50 : pauseTime; 
     if (elapsed >= (unsigned long)phase) {
      buzzerOn    = !buzzerOn;
      lastToggle  = now;
      digitalWrite(buzzerPin, buzzerOn ? HIGH : LOW);
     }
  }

}
