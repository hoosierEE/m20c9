#include <Arduino.h>
#include <SoftwareSerial.h>
#include "common.hpp"
#include "keymap.hpp"
const uint8_t led=13; // hello embedded world

// Data
CapsRaw cr;
CapsTouched ct, ct_other;
MechsPressed mp, mp_other;

// Serial
SoftwareSerial ss(10,11);
const uint32_t timeout=500;

void setup(){
    for(const auto&i : tnsy_col_pins) pinMode(i,INPUT_PULLUP);
    for(const auto&i : tnsy_row_pins) pinMode(i,OUTPUT_OPENDRAIN);
    ss.begin(57600);
}

void loop(){
    // Read capacitive pads
    for(uint8_t i=0;i<caps;++i){
        ct[i] = 1000 < touchRead(tnsy_cap_pins[i]);
        //cr[i] = touchRead(tnsy_cap_pins[i]);
        //ct[i] = 1000 < cr[i];
    }
    // Read mechanical switches
    for(uint8_t row=0; row<rows; ++row){
        digitalWrite(tnsy_row_pins[row],LOW);
        for(uint8_t col=0; col<cols; ++col){
            mp[row][col] = digitalRead(tnsy_col_pins[col]);
        }
        digitalWrite(tnsy_row_pins[row],HIGH);
    }

#ifdef is_right // RPC to left side, asking for result of scan.
    ss.write(1);
    do{digitalWrite(led,HIGH);} while(!ss.available());
    digitalWrite(led,LOW);

    constexpr uint8_t max_bytes=caps+cols*rows;
    uint8_t buf[max_bytes]={0};
    if(ss.readBytes(buf,max_bytes)==max_bytes){
        for(uint8_t row=0;row<rows;++row){
            for(uint8_t col=0;col<cols;++col){
                mp_other[row][col]=buf[row*rows+col];
            }
        }
        for(uint8_t i=0;i<caps;++i){
            ct_other[i]=buf[i+rows*cols];
        }
    } // else: ignore bad data

    //
    // TODO : matrices -> USB keys.
    //

#else // respond to RPC by sending whole payload
    if(ss.read()==1){
        for(uint8_t row=0;row<rows;++row){
            for(uint8_t col=0;col<cols;++col){
                ss.write(mp[row][col]);
            }
        }
        for(uint8_t i=0;i<caps;++i){
            ss.write(ct[i]);
        }
    }
#endif
}
