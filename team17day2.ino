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
#define AUDIO_PIN 13

#define RGB1 6
#define RGB2 7
#define WHITE 8
#define RED 9
#define YELLOW 10
#define GREEN 11
#define BLUE 12

#define QUARTER (60 * 1000./BPM)
#define WHOLE (QUARTER * 4)
#define HALF (QUARTER * 2)
#define EIGTH (QUARTER / 2)
#define SIXTEENTH (QUARTER / 4)

void setLEDs(int white, int red, int yellow, int green, int blue, float type) {
  int brightness = 0;
  if(type == SIXTEENTH) {
    brightness = 255;
  } else if(type == EIGTH) {
    brightness = 135;
  } else if(type == QUARTER) {
    brightness = 75;
  } else if(type == EIGTH) {
    brightness = 45;
  } else if(type == SIXTEENTH) {
    brightness = 30;
  }
  digitalWrite(WHITE, white*brightness);
  digitalWrite(RED, red*brightness);
  digitalWrite(YELLOW, yellow*brightness);
  digitalWrite(GREEN, green*brightness);
  digitalWrite(BLUE, blue*brightness);
}

void playNote(float n, int octave, float type) {
  tone(AUDIO_PIN, n * pow(2, octave), type);
  if(n == C) {
    setLEDs(1,0,0,0,0,type);
  } else if(n == CC) {
    setLEDs(0,0,0,0,1,type);
  } else if(n == D) {
    setLEDs(1,0,0,0,0,type);
  } else if(n == DD) {
    setLEDs(0,0,0,1,0,type);
  } else if(n == E) {
    setLEDs(0,0,0,0,1,type);
  } else if(n == f) {
    setLEDs(1,1,0,0,0,type);
  } else if(n == FF) {
    setLEDs(0,1,0,0,0,type);
  } else if(n == G) {
    setLEDs(0,0,1,1,0,type);
  } else if(n == GG) {
    setLEDs(0,0,0,1,0,type);
  } else if(n == A) {
    setLEDs(0,0,1,0,0,type);
  } else if(n == AA) {
    setLEDs(0,0,1,0,1,type);
  } else if(n == B) {
    setLEDs(0,0,0,1,1,type);
  }
  delay(type);
  setLEDs(0,0,0,0,0,0);
}

void playRest(float type) {
  setLEDs(0,0,0,0,0,0);
  //noTone();
  delay(type);
}

void setup() {
  pinMode(WHITE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //1
  digitalWrite(RGB1, 1);
  digitalWrite(RGB2, 1);
  delay(1000);
  //2
  digitalWrite(RGB1, 0);
  digitalWrite(RGB2, 0);
  delay(1000);
  //3
  digitalWrite(RGB1, 1);
  digitalWrite(RGB2, 1);
  delay(1000);
  //4
  digitalWrite(RGB1, 0);
  digitalWrite(RGB2, 0);
  delay(1000);
  //5
  digitalWrite(RGB1, 1);
  digitalWrite(RGB2, 1);
  delay(1000);
  //6
  digitalWrite(RGB1, 0);
  digitalWrite(RGB2, 0);
  delay(1000);
  //7
  digitalWrite(RGB1, 1);
  digitalWrite(RGB2, 1);
  delay(1000);
  //8
  digitalWrite(RGB1, 0);
  digitalWrite(RGB2, 0);
  delay(1000);
  //9
  digitalWrite(RGB1, 1);
  digitalWrite(RGB2, 1);
  delay(1000);
  
}

void loop() {
  secrets();
  delay(2000);
}

void secrets() {
  //Notes Used: D, FF, A, G, CC, B
  
  //one
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(G,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);

  //two
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);

  //three
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);

  //four
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);

  //five
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);

  //six
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,3,EIGTH);
  playNote(D,4,EIGTH);

  //seven
  playNote(G,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(B,4,EIGTH);

  //eight
  playNote(G,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(B,4,EIGTH);

  //nine
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //ten
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //eleven
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //twelve
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //thirteen
  playNote(B,3,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);

  //fourteen
  playNote(B,3,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(B,4,EIGTH);
  playNote(FF,4,EIGTH);

  //fifteen
  playNote(G,4,EIGTH);
  playNote(D,5,EIGTH);
  playNote(G,5,EIGTH);
  playNote(D,5,EIGTH);
  playNote(G,5,EIGTH);
  playNote(D,5,EIGTH);
  playNote(G,5,EIGTH);
  playNote(D,5,EIGTH);

  //sixteen
  playNote(G,3,EIGTH);
  playNote(D,4,EIGTH);
  playNote(G,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(G,4,EIGTH);
  playNote(D,4,EIGTH);
  playNote(G,4,EIGTH);
  playNote(D,4,EIGTH);

  //seventeen
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //eighteen
  playNote(D,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //nineteen
  playNote(CC,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);
  playNote(A,4,EIGTH);
  playNote(FF,4,EIGTH);

  //twenty
  playNote(

}

