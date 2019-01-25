  /*

 https://github.com/mevdschee/2048.c

 */

#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <signal.h>
#include <math.h>
#include <Adafruit_NeoPixel.h>

#define SIZE 4

#define waittime 40

Adafruit_NeoPixel strip_1 = Adafruit_NeoPixel(16, 13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_2 = Adafruit_NeoPixel(16, 12, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_3 = Adafruit_NeoPixel(16, 11, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_4 = Adafruit_NeoPixel(16, 10, NEO_GRB + NEO_KHZ800);

const int PIXEL_STRIP_LENGTH = 16;

const int UP = 35;
const int DOWN = 37;
const int LEFT =39;
const int RIGHT = 41; 

const int START_PIN = UP;

const int WIN_SCORE = 2048;

int keepDemoOn;

int loopMe;
int winLoop;

bool success;

uint32_t score=0;
uint32_t scheme=0;
uint32_t gameBoard[SIZE][SIZE];

void setupPixelStrips() {
  strip_1.begin();
  strip_1.show(); // Initialize all pixels to 'off'
  strip_2.begin();
  strip_2.show(); // Initialize all pixels to 'off'
  strip_3.begin();
  strip_3.show(); // Initialize all pixels to 'off'
  strip_4.begin();
  strip_4.show(); // Initialize all pixels to 'off'
}

/*Adafruit_NeoPixel getStrip(int rowNum) {
    switch(rowNum) {
        case 0: return strip_1;
        case 1: return strip_2;
        case 2: return strip_3;
        case 3: return strip_4;
    }
    return strip_1;
}*/

void drawBoard(uint32_t board[SIZE][SIZE]) {
  //setupPixelStrips();
  int x, y;

  for(x = 0; x < SIZE; x++) {    
    Adafruit_NeoPixel strip;
    
    for(y = 0; y < SIZE; y++) {
        uint32_t high;

        switch(board[x][y]) {
            case 1:
                high = strip.Color(128, 0, 0); // Yellow
                break;
            case 2: 
                high = strip.Color(0, 0, 128); // Blue
                break;
            case 4: 
                high = strip.Color(0,128,0); // green
                break;
            case 8: 
                high = strip.Color(128,0,0); // Red
                break;
            case 16: 
                high = strip.Color(128,0,64); // purple
                break;
            case 32: 
                high = strip.Color(128, 64, 0); // orange
                break;
            case 64: 
                high = strip.Color(0, 128, 128); // cyan
                break;
            case 128: 
                high = strip.Color(64, 64, 128); // Lavender
                break;
            case 256: 
                high = strip.Color(64,128,0); // lime
                break;
            case 512: 
                high = strip.Color(128,64,128); // violat
                break;
            case 1024: 
                high = strip.Color(128, 128, 128); // white
                break;
            case 2048: 
                high = strip.Color(0, 0, 0); // something
                break;
            default: 
                high = strip.Color(0, 0, 0); // OFF
        }

        switch (x){
          case 0:
            switch (y){
              case 0:
                //Draw Block 1, 1
                for(uint16_t i=0; i<4; i++) {
                strip_1.setPixelColor(i, high);
                }
                strip_1.show();
                break;
              case 1:
                //Draw Block 1, 2
                for(uint16_t i=4; i<8; i++) {
                strip_1.setPixelColor(i, high);
                }
                strip_1.show();
                break;
              case 2:
                //Draw Block 1, 3
                for(uint16_t i=8; i<12; i++) {
                strip_1.setPixelColor(i, high);
                }
                strip_1.show();
                break;
              case 3:
                //Draw Block 1, 4
                for(uint16_t i=12; i<16; i++) {
                strip_1.setPixelColor(i, high);
                }
                strip_1.show();
                break;
              default:
                break;
            }
            break;
          case 1:
            switch (y){
              case 0:
                //Draw Block 2, 1
                for(uint16_t i=0; i<4; i++) {
                strip_2.setPixelColor(i, high);
                }
                strip_2.show();
                break;
              case 1:
                //Draw Block 2, 2
                for(uint16_t i=4; i<8; i++) {
                strip_2.setPixelColor(i, high);
                }
                strip_2.show();
                break;
              case 2:
                //Draw Block 2, 3
                for(uint16_t i=8; i<12; i++) {
                strip_2.setPixelColor(i, high);
                }
                strip_2.show();
                break;
              case 3:
                //Draw Block 2, 4
                for(uint16_t i=12; i<16; i++) {
                strip_2.setPixelColor(i, high);
                }
                strip_2.show();
                break;
              default:
                break;
            }
            break;
          case 2:
            switch (y){
              case 0:
                //Draw Block 3, 1
                for(uint16_t i=0; i<4; i++) {
                strip_3.setPixelColor(i, high);
                }
                strip_3.show();
                break;
              case 1:
                //Draw Block 3, 2
                for(uint16_t i=4; i<8; i++) {
                strip_3.setPixelColor(i, high);
                }
                strip_3.show();
                break;
              case 2:
                //Draw Block 3, 3
                for(uint16_t i=8; i<12; i++) {
                strip_3.setPixelColor(i, high);
                }
                strip_3.show();
                break;
              case 3:
                //Draw Block 3, 4
                for(uint16_t i=12; i<16; i++) {
                strip_3.setPixelColor(i, high);
                }
                strip_3.show();
                break;
              default:
                break;
            }
            break;
          case 3:
            switch (y){
              case 0:
                //Draw Block 4, 1
                for(uint16_t i=0; i<4; i++) {
                strip_4.setPixelColor(i, high);
                }
                strip_4.show();
                break;
              case 1:
                //Draw Block 4, 2
                for(uint16_t i=4; i<8; i++) {
                strip_4.setPixelColor(i, high);
                }
                strip_4.show();
                break;
              case 2:
                //Draw Block 4, 3
                for(uint16_t i=8; i<12; i++) {
                strip_4.setPixelColor(i, high);
                }
                strip_4.show();
                break;
              case 3:
                //Draw Block 4, 4
                for(uint16_t i=12; i<16; i++) {
                strip_4.setPixelColor(i, high);
                }
                strip_4.show();
                break;
              default:
                break;
            }
            break;
          default:
            break;
        }
    }
  }
}


uint32_t findTarget(uint32_t array[SIZE],uint32_t x,uint32_t stop) {
  uint32_t t;
  // if the position is already on the first, don't evaluate
  if (x==0) {
    return x;
  }
  for(t=x-1;t>=0;t--) {
    if (array[t]!=0) {
      if (array[t]!=array[x]) {
        // merge is not possible, take next position
        return t+1;
      }
      return t;
    } else {
      // we should not slide further, return this one
      if (t==stop) {
        return t;
      }
    }
  }
  // we did not find a
  return x;
}

void rotateBoard() {
  uint32_t n = SIZE;
  uint32_t tmp;
  for (uint32_t i = 0; i < n / 2; i++) {
    for (uint32_t j = i; j < n - i - 1; j++) {
      tmp = gameBoard[i][j];
      gameBoard[i][j] = gameBoard[j][n-i-1];
      gameBoard[j][n-i-1] = gameBoard[n-i-1][n-j-1];
      gameBoard[n-i-1][n-j-1] = gameBoard[n-j-1][i];
      gameBoard[n-j-1][i] = tmp;
    }
  }
}

bool moveUp() {
  bool success = false;
  uint32_t i;
  for (i = 0; i < SIZE; i++) {
    //success = false;
    uint32_t x,t,stop=0;

    for (x=0;x<SIZE;x++) {
        if (gameBoard[i][x]!=0) {
            t = findTarget(gameBoard[i],x,stop);
            // if target is not original position, then move or merge
            if (t!=x) {
                // if target is zero, this is a move
                if (gameBoard[i][t]==0) {
                    gameBoard[i][t]=gameBoard[i][x];
                } else if (gameBoard[i][t]==gameBoard[i][x]) {
                    // merge (increase power of two)
                    gameBoard[i][t] = gameBoard[i][t] + gameBoard[i][x];
                    // increase score
                    score+=(uint32_t)1<<gameBoard[i][t];
                    // set stop to avoid double merge
                    stop = t+1;
                }
                gameBoard[i][x]=0;
                success = true;
            }
        }
    }
  }
  return success;
}

void checkBoard() {
    for(int a = 0; a < 4; a++) {
        for(int b = 0; b < 4; b++) {
            Serial.println("------------------");
            Serial.print("x: ");
            Serial.println(a);
            Serial.print("y: ");
            Serial.println(b);
            Serial.print("board: ");
            Serial.println(gameBoard[a][b]);
        }
    }
    Serial.println("end check");
}

bool moveLeft() {
  rotateBoard();
  rotateBoard();
  rotateBoard();
  success = moveUp();
  rotateBoard();
  return success;
}

bool moveDown() {
  rotateBoard();
  rotateBoard();
  success = moveUp();
  rotateBoard();
  rotateBoard();
  return success;
}

bool moveRight() {
  rotateBoard();
  success = moveUp();
  rotateBoard();
  rotateBoard();
  rotateBoard();
  return success;
}

bool findPairDown(uint32_t board[SIZE][SIZE]) {
  uint32_t x,y;
  for (x=0;x<SIZE;x++) {
    for (y=0;y<SIZE-1;y++) {
      if (board[x][y]==board[x][y+1]) return true;
    }
  }
  return false;
}

uint32_t countEmpty(uint32_t board[SIZE][SIZE]) {
  uint32_t x,y;
  uint32_t count=0;
  for (x=0;x<SIZE;x++) {
    for (y=0;y<SIZE;y++) {
      if (board[x][y]==0) {
        count++;
      }
    }
  }
  return count;
}

bool gameEnded(uint32_t board[SIZE][SIZE]) {
  bool ended = true;
  if (countEmpty(board)>0) return false;
  if (findPairDown(board)) return false;
  rotateBoard();
  if (findPairDown(board)) ended = false;
  rotateBoard();
  rotateBoard();
  rotateBoard();
  return ended;
}

// void addRandom() {
//   static bool initialized = false;
//   uint32_t x,y;
//   uint32_t r,len=0;
//   uint32_t n,list[SIZE*SIZE][2];

//   if (!initialized) {
//     srand(time(NULL));
//     initialized = true;
//   }

//   for (x=0;x<SIZE;x++) {
//     for (y=0;y<SIZE;y++) {
//       if (gameBoard[x][y]==0) {
//         list[len][0]=x;
//         list[len][1]=y;
//         len++;
//       }
//     }
//   }

//   if (len>0) {
//     r = rand()%len;
//     x = list[r][0];
//     y = list[r][1];
//     n = (rand()%10)/9+1;
//     gameBoard[x][y]=2;
//   }
// }

void addRandom() {
  int x;
  int y;

  int value = 3; // so it enters the loop

  bool found = false;

  while(!found) {
    x = random(SIZE);
    y = random(SIZE);

    if(gameBoard[x][y] == 0) {
      found = true;
    }
  }

  while(value == 3) {
    value = random(2, 4);
  }
  gameBoard[x][y] = value;
}

void initBoard(uint32_t board[SIZE][SIZE]) {
  uint32_t x,y;
  for (x=0;x<SIZE;x++) {
    for (y=0;y<SIZE;y++) {
      board[x][y]=0;
    }
  }
  //board[0][0]=1024;
  //board[0][1]=1024;
  addRandom();
  addRandom();
  drawBoard(board);
  score = 0;
}

void win() {
//  for(uint16_t i=0; i<strip_1.numPixels(); i++) {
//    uint32_t high = strip_1.Color(0, 128, 0);
//    strip_1.setPixelColor(i, high);
//    strip_1.show();
//    delay(25);
//  }
//  for(uint16_t i=0; i<strip_2.numPixels(); i++) {
//    uint32_t high = strip_2.Color(0, 128, 0);
//    strip_2.setPixelColor(i, high);
//    strip_2.show();
//    delay(25);
//  }
//  for(uint16_t i=0; i<strip_3.numPixels(); i++) {
//    uint32_t high = strip_3.Color(0, 128, 0);
//   strip_3.setPixelColor(i, high);
//    strip_3.show();
//    delay(25);
//  }
//  for(uint16_t i=0; i<strip_4.numPixels(); i++) {
//    uint32_t high = strip_4.Color(0, 128, 0);
//    strip_4.setPixelColor(i, high);
//    strip_4.show();
//    delay(25);
//  } 

  uint32_t high;

  while (winLoop < 11){
        switch(winLoop) {
        case 0: 
            high = strip_1.Color(0,128,0); //Green
            break;
        case 1: 
            high = strip_1.Color(0, 128, 64); //Seafoam
            break;
        case 2: 
            high = strip_1.Color(0, 128, 128); //Cyan
            break;
        case 3: 
            high = strip_1.Color(0, 64, 128);  //Turquoise
            break;
        case 4: 
            high = strip_1.Color(0,0,128); //Blue
            break;
        case 5: 
            high = strip_1.Color(64,0,128);  //Purple
            break;
        case 6: 
            high = strip_1.Color(128, 0, 128); //Pink
            break;
        case 7: 
            high = strip_1.Color(128, 0, 64);  //Magenta
            break;
        case 8:
            high = strip_1.Color(128, 0, 0); //Red
            break;
        case 9: 
            high = strip_1.Color(128, 64, 0); //Orange
            break;
        case 10: 
            high = strip_1.Color(128,128,0);  //Yellow
            break;
        case 11: 
            high = strip_1.Color(64,128,0);  //Lime
            break;
        default: 
            high = strip_1.Color(0, 0, 0); // OFF
            }
    
    //Draw each block, one at a time. Comment format is row, then collumnn
    //Draw Block 1, 1
    for(uint16_t i=0; i<4; i++) {
      //uint32_t high = strip_1.Color(0, 128, 0);
      strip_1.setPixelColor(i, high);
    }
    strip_1.show();
    delay(waittime);
  
      //Draw Block 1, 2
    for(uint16_t i=4; i<8; i++) {
      //uint32_t high = strip_1.Color(0, 0, 128);
      strip_1.setPixelColor(i, high);
    }
    strip_1.show();
    delay(waittime);
  
      //Draw Block 1, 3
    for(uint16_t i=8; i<12; i++) {   
      //uint32_t high = strip_1_copy.Color(128, 128, 0);
      strip_1.setPixelColor(i, high);
    }
    strip_1.show();
    delay(waittime);
  
      //Draw Block 1, 4
    for(uint16_t i=12; i<16; i++) {
      //uint32_t high = strip_1.Color(0, 128, 128);
      strip_1.setPixelColor(i, high);
    }
    strip_1.show();
    delay(waittime);
  
        //Draw Block 2, 4
    for(uint16_t i=12; i<16; i++) {
      //uint32_t high = strip_2.Color(0, 128, 128);
      strip_2.setPixelColor(i, high);
    }
    strip_2.show();
    delay(waittime);
  
        //Draw Block 3, 4
    for(uint16_t i=12; i<16; i++) {
      //uint32_t high = strip_3.Color(0, 128, 128);
      strip_3.setPixelColor(i, high);
    }
    strip_3.show();
    delay(waittime);
  
        //Draw Block 4, 4
    for(uint16_t i=12; i<16; i++) {
      //uint32_t high = strip_4.Color(0, 128, 128);
      strip_4.setPixelColor(i, high);
    }
    strip_4.show();
    delay(waittime);
  
        //Draw Block 4, 3
    for(uint16_t i=8; i<12; i++) {
      //uint32_t high = strip_4.Color(128, 128, 0);
      strip_4.setPixelColor(i, high);
    }
    strip_4.show();
    delay(waittime);
  
        //Draw Block 4, 2
    for(uint16_t i=4; i<8; i++) {
      //uint32_t high = strip_4.Color(0, 0, 128);
      strip_4.setPixelColor(i, high);
    }
    strip_4.show();
    delay(waittime);
  
        //Draw Block 4, 1
    for(uint16_t i=0; i<4; i++) {
      //uint32_t high = strip_4.Color(0, 128, 0);
      strip_4.setPixelColor(i, high);
    }
    strip_4.show();
    delay(waittime);
  
       //Draw Block 3, 1
    for(uint16_t i=0; i<4; i++) {
      //uint32_t high = strip_3.Color(0, 128, 0);
      strip_3.setPixelColor(i, high);
    }
    strip_3.show();
    delay(waittime); 
  
    //Draw Block 2, 1
    for(uint16_t i=0; i<4; i++) {
      //uint32_t high = strip_2.Color(0, 128, 0);
      strip_2.setPixelColor(i, high);
    }
    strip_2.show();
    delay(waittime);
  
      //Draw Block 2, 2
    for(uint16_t i=4; i<8; i++) {
      //uint32_t high = strip_2.Color(0, 0, 128);
      strip_2.setPixelColor(i, high);
    }
    strip_2.show();
    delay(waittime);
  
      //Draw Block 2, 3
    for(uint16_t i=8; i<12; i++) {
      //uint32_t high = strip_2.Color(128, 128, 0);
      strip_2.setPixelColor(i, high);
    }
    strip_2.show();
    delay(waittime);
  
      //Draw Block 3, 3
    for(uint16_t i=8; i<12; i++) {
      //uint32_t high = strip_3.Color(128, 128, 0);
      strip_3.setPixelColor(i, high);
    }
    strip_3.show();
    delay(waittime);
  
      //Draw Block 3, 2
    for(uint16_t i=4; i<8; i++) {
      //uint32_t high = strip_3.Color(0, 0, 128);
      strip_3.setPixelColor(i, high);
    }
    strip_3.show();
    delay(waittime);
  
    winLoop++;
      

  }
  winLoop=0;
}

void lose() { 
  delay(200);
  for(uint16_t i=0; i<strip_4.numPixels(); i++) {
      uint32_t high = strip_4.Color(128, 0, 0);
      strip_4.setPixelColor(i, high);
      strip_4.show();
      delay(25);
  }
  for(uint16_t i=0; i<strip_3.numPixels(); i++) {
      uint32_t high = strip_3.Color(128, 0, 0);
      strip_3.setPixelColor(i, high);
      strip_3.show();
      delay(25);
  }
  for(uint16_t i=0; i<strip_2.numPixels(); i++) {
    uint32_t high = strip_2.Color(128, 0, 0);
    strip_2.setPixelColor(i, high);
    strip_2.show();
    delay(25);
  }
  for(uint16_t i=0; i<strip_1.numPixels(); i++) {
    uint32_t high = strip_1.Color(128, 0, 0);
    strip_1.setPixelColor(i, high);
    strip_1.show();
    delay(25);
  }
    
  delay(500);
  for(uint16_t i=128; i>0; i--) {
      uint32_t high = strip_1.Color(i, 0, 0);
      strip_1.setPixelColor(i, high);
      strip_1.show();
      strip_2.setPixelColor(i, high);
      strip_2.show();
      strip_3.setPixelColor(i, high);
      strip_3.show();
      strip_4.setPixelColor(i, high);
      strip_4.show();
      delay(10);
  } 
}

void setup() {
  Serial.begin(9600);
  setupPixelStrips();
  //win();
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  //lose();

// bool success = false;

  keepDemoOn = 30000;
  loopMe = 0;
  winLoop = 0;
  //initBoard(gameBoard);

//   delay(1000); 
   
//   success = moveDown();
//   addRandom();
//   drawBoard(gameBoard);
//   checkBoard();
//   Serial.print("down: ");
//   Serial.println(success);
//   delay(1000);

//   success = moveLeft();
//   drawBoard(gameBoard);
//   checkBoard();
//   Serial.print("left: ");
//   Serial.println(success);
//   delay(1000);

//  success = moveRight();
//  drawBoard(gameBoard);
//  checkBoard();
//  Serial.print("right: ");
//  Serial.println(success);
//  delay(1000);

// success = moveUp();
//  drawBoard(gameBoard);
//  checkBoard();
//  Serial.print("up: ");
//  Serial.println(success);
//  delay(1000);

//  initBoard(gameBoard);
//  checkBoard();

  Serial.println("end");
}

void demoLooper(){
  int up = digitalRead(UP);
  int down = digitalRead(DOWN);
  int left = digitalRead(LEFT);
  int right = digitalRead(RIGHT);
  
  uint32_t high;


  switch(loopMe) {
  case 0:
      high = strip_1.Color(128, 0, 0); //Red
      break;
  case 1: 
      high = strip_1.Color(128, 64, 0); //Orange
      break;
  case 2: 
      high = strip_1.Color(128,128,0);  //Yellow
      break;
  case 3: 
      high = strip_1.Color(64,128,0);  //Lime
      break;
  case 4: 
      high = strip_1.Color(0,128,0); //Green
      break;
  case 5: 
      high = strip_1.Color(0, 128, 64); //Seafoam
      break;
  case 6: 
      high = strip_1.Color(0, 128, 128); //Cyan
      break;
  case 7: 
      high = strip_1.Color(0, 64, 128);  //Turquoise
      break;
  case 8: 
      high = strip_1.Color(0,0,128); //Blue
      break;
  case 9: 
      high = strip_1.Color(64,0,128);  //Purple
      break;
  case 10: 
      high = strip_1.Color(128, 0, 128); //Pink
      break;
  case 11: 
      high = strip_1.Color(128, 0, 64);  //Magenta
      break;
  default: 
      high = strip_1.Color(0, 0, 0); // OFF
      }

  for(uint16_t i=0; i<strip_1.numPixels(); i++) {
    //uint32_t high = strip_1.Color(128, 0, 0);
    strip_1.setPixelColor(i, high);
    strip_1.show();
    strip_2.setPixelColor(i, high);
    strip_2.show();
    strip_3.setPixelColor(i, high);
    strip_3.show();
    strip_4.setPixelColor(i, high);
    strip_4.show();
    delay(waittime);
  }

  //test for a button press. if any button is pressed, exit the demo
  if(up == LOW) {
     keepDemoOn=-15000;
     initBoard(gameBoard);
     delay(25);
  } else if (down == LOW) {
     keepDemoOn=-15000;
     initBoard(gameBoard);
     delay(25);
  } else if (left == LOW) {
     keepDemoOn=-15000;
     initBoard(gameBoard);
     delay(25);
  } else if (right == LOW) {
    keepDemoOn=-15000;
    initBoard(gameBoard);
    delay(25);
  }


  loopMe++;
  if(loopMe>11){
    loopMe=0;
  }
}

void loop() {
  int up = digitalRead(UP);
  int down = digitalRead(DOWN);
  int left = digitalRead(LEFT);
  int right = digitalRead(RIGHT);

    
    bool success = false;

    //Every time a button is pressed during gameplay it activates a timer for roughly 45seconds. After 45 seconds the game will enter demo mode
    if (keepDemoOn < 30000){
      keepDemoOn++;
      delay(1);
    } else {
      demoLooper();
    }


   if(up == LOW) {
     Serial.print("up: ");
     Serial.println(up);
     success = moveUp();
     keepDemoOn=-15000;
// //  delay(1000);
   } else if (down == LOW) {
     Serial.print("down: ");
     Serial.println(down);
     success = moveDown();
     keepDemoOn=-15000;
// //  delay(1000);
   } else if (left == LOW) {
     Serial.print("left: ");
     Serial.println(left);
     success = moveLeft();
     keepDemoOn=-15000;
// //  delay(1000);
   } else if (right == LOW) {
    Serial.print("right: ");
    Serial.println(right);
    success = moveRight();
    keepDemoOn=-15000;
//  delay(1000);
  } else {
    success = false;
  }

  if (success) {
          Serial.println("made it here");
    drawBoard(gameBoard);
    //usleep(150000);
    addRandom();
    checkBoard();
    drawBoard(gameBoard);
    //delay(7000);
    if (gameEnded(gameBoard)) {
      // you loose
      lose();
      initBoard(gameBoard);
      delay(200);
    } else if(checkWin(gameBoard)) {
      // you win
      win();
      initBoard(gameBoard);
    }
  }
}

bool checkWin(uint32_t board[SIZE][SIZE]) {
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      if(board[x][y] == WIN_SCORE) {
        return true;
      }
    }
  }
  return false;
}
