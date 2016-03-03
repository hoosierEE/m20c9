/**
   m30c10 keyboard firmware for TeensyLC
   https://github.com/hoosierEE/m30c10
*/
#include <Arduino.h>
const uint32_t MS_OUT{10}; elapsedMillis t; // min. output period

//// Model
static const uint8_t COLS{5}; // 2 columns for index finger, 1 each for middle/ring/pinkie
static const uint8_t ROWS{6}; // 3 rows per hand
const int TEENSY_ROW_PIN[ROWS]{10,11,12,14,20,21};
const int TEENSY_COL_PIN[COLS]{2,5,6,7,8}; // pin 9 is also available if more switches req'd
struct Grid { bool keys[COLS][ROWS]; } raw_grid;

//// Key Layers
char *default_layer[]{"qwert","yuiop","asdfg","hjkl'" ,"zxcvb","nm,.-"};
char *shifted_layer[]{"QWERT","YUIOP","ASDFG","HJKL\"","ZXCVB","NM?!:"};
char *numeric_layer[]{"75319","02468","12345","67890" ,"():,%",".+-*/"};
char *symbol_layer []{"@#$%[","]^&*|"," -+=(",");:/\\","_~`!{","}<,.>"};

//// Functions
void set_pins(void)
{
    for (int i=0;i<COLS;++i) {
        pinMode(TEENSY_COL_PIN[i], OUTPUT);
        for (int j=0;j<ROWS;++j) {
            pinMode(TEENSY_ROW_PIN[j], INPUT_PULLUP);
        }
    }
}

Grid scan(void)
{
    Grid g;
    for (int i=0;i<COLS;++i) {
        digitalWrite(TEENSY_COL_PIN[i],LOW); // pull column low
        for (int j=0;j<ROWS;++j) {
            g.keys[i][j] = digitalRead(TEENSY_ROW_PIN[i]); // populate grid
        }
        digitalWrite(TEENSY_COL_PIN[i],HIGH); // restore column
    }
    return g;
}

void print_grid(Grid g)
{
    // for debugging
    for (int i=0;i<COLS;++i) {
        for (int j=0;j<ROWS;++j) {
            if (g.keys[i][j]) { Serial.print(default_layer[i][j]); }
        }
    }
    Serial.println("");
}

void setup() {
    set_pins();
}
void loop() {
    print_grid(scan()); // read inputs

    if (t >= MS_OUT) {
        t -= MS_OUT;
        // TODO: output if changed
    }
}
