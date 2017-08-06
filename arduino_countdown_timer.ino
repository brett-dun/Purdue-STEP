#define C 16.35
#define CC 17.32
#define D 18.35
#define DD 19.45
#define E 20.60
#define f 21.83
#define FF 23.12
#define G 24.5
#define GG 25.96
#define A 27.5
#define AA 29.14
#define B 30.87

#define BPM 150
#define AUDIO_PIN 10

#define QUARTER (60 * 1000./BPM)
#define WHOLE (QUARTER * 4)
#define HALF (QUARTER * 2)
#define EIGTH (QUARTER / 2)
#define SIXTEENTH (QUARTER / 4)


void playNote(float n, int octave, float type) {
  tone(AUDIO_PIN, n * pow(2, octave), type);
  delay(type);
}

void playRest(float type) {
  //noTone();
  delay(type);
}

int A_ = 2;
int B_ = 3;
int C_ = 4;
int D_ = 5;
int E_ = 6;
int F_ = 8;
int G_ = 9;



void setup() {
  pinMode(AUDIO_PIN, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (5, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (3, OUTPUT);
  pinMode (2, OUTPUT);

  nine();
  delay (1000);
  eight();
   delay (1000);
  seven();
   delay (1000);
  six();
   delay (1000);
  five();
   delay (1000);
  four();
   delay (1000);
  three();
   delay (1000);
  two();
   delay (1000);
  one();
  delay (1000);
  zero();
}

void loop() {
  secrets();
  delay(2000);
}

void secrets() {
  //melody
  playRest(WHOLE * 7);
  //eight
  playRest(QUARTER);
  playRest(EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  //nine
  playNote(A,4,QUARTER);
  playNote(FF,4,HALF + QUARTER);
  //ten
  playRest(QUARTER + EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  //eleven
  playNote(A,4,QUARTER);
  playNote(D,4,HALF);
  playNote(B,3,QUARTER);
  //twelve
  playRest(QUARTER + EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  //thirteen
  playNote(A,4,QUARTER);
  playNote(FF,4,HALF + QUARTER);
  //fourteen
  playRest(QUARTER + EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  //fifteen
  playNote(A,4,QUARTER);
  playNote(D,4,HALF);
  playNote(B,3,QUARTER);
  //sixteen
  playRest(HALF + EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(B,4,SIXTEENTH);
  playRest(SIXTEENTH);
  //seventeen
  playNote(D,5,QUARTER);
  playNote(E,5,QUARTER);
  playNote(CC,5,QUARTER);
  playNote(D,5,QUARTER + HALF);
  playRest(EIGTH);
  playNote(A,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(A,4,EIGTH);
  playNote(B,4,EIGTH);
  //nineteen
  playNote(CC,5,QUARTER);
  playNote(D,5,QUARTER);
  playNote(CC,5,QUARTER);
  playNote(CC,5,QUARTER + HALF);
  playRest(EIGTH);
  playNote(B,4,SIXTEENTH);
  playNote(B,4,EIGTH);
  //twentyone
  playNote(D,5,QUARTER);
  playNote(B,4,EIGTH);
  playRest(EIGTH);
  playNote(B,4,EIGTH);
  playRest(EIGTH);
  playNote(B,4,EIGTH);
  playRest(EIGTH);
  //twentytwo
  playNote(B,4,QUARTER + EIGTH);
  playRest(EIGTH);
  playNote(B,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(B,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(B,4,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(CC,5,QUARTER);
  playNote(D,5,QUARTER);
  playNote(B,4,EIGTH);
  playRest(EIGTH);
  playNote(B,4,EIGTH);
  playNote(CC,5,EIGTH);
  playNote(B,4,EIGTH);
  playNote(CC,5,EIGTH);
  //twentyfour
  playNote(D,5,QUARTER);
  playNote(B,4,QUARTER);
  playNote(D,5,EIGTH);
  playNote(E,5,EIGTH);
  playNote(D,5,EIGTH);
  playNote(E,5,EIGTH);
  //twentyfive
  playNote(FF,5,QUARTER);
  playNote(A,5,QUARTER);
  playNote(D,5,HALF + QUARTER);
  playRest(QUARTER);
  playNote(D,5,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(D,5,SIXTEENTH);
  playRest(SIXTEENTH);
  playNote(D,5,EIGTH);
  playNote(E,5,EIGTH);
  //twentyseven
  

  
}


void zero () {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, HIGH);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, LOW);
}
void one() {
  digitalWrite(A_, LOW);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, LOW);
  digitalWrite(E_, LOW);
  digitalWrite(F_, LOW);
  digitalWrite(G_, LOW);
}
void two() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, LOW);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, HIGH);
  digitalWrite(F_, LOW);
  digitalWrite(G_, HIGH);
}
void three() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, LOW);
  digitalWrite(F_, LOW);
  digitalWrite(G_, HIGH);
}
void four() {
  digitalWrite(A_, LOW);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, LOW);
  digitalWrite(E_, LOW);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, HIGH);
}
void five() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, LOW);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, LOW);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, HIGH);
}
void six() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, LOW);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, HIGH);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, HIGH);
}
void seven() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, LOW);
  digitalWrite(E_, LOW);
  digitalWrite(F_, LOW);
  digitalWrite(G_, LOW);
}
void eight() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, HIGH);
  digitalWrite(E_, HIGH);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, HIGH);
}
void nine() {
  digitalWrite(A_, HIGH);
  digitalWrite(B_, HIGH);
  digitalWrite(C_, HIGH);
  digitalWrite(D_, LOW);
  digitalWrite(E_, LOW);
  digitalWrite(F_, HIGH);
  digitalWrite(G_, HIGH);
}

