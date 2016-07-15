/*
===========================================================================

  This is the library for Beam.

  Beam is a beautiful LED matrix — features 120 LEDs that displays scrolling text, animations, or custom lighting effects.
  Beam can be purchased here: http://www.hoverlabs.co

  Written by Emran Mahbub and Jonathan Li for Hover Labs.
  BSD license, all text above must be included in any redistribution

===========================================================================
*/

int frame0[0x0F] = {                    //Frame 0
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
};
int frame1[0x0F] = {                    //Frame 0
  0b10000000, 0b00000000, 0b00000001,
  0b10000000, 0b00000000, 0b00000001,
  0b10000000, 0b00000000, 0b00000001,
  0b10000000, 0b00000000, 0b00000001,
  0b10000000, 0b00000000, 0b00000001,
};
int frame2[0x0F] = {                    //Frame 0
  0b11000000, 0b00000000, 0b00000011,
  0b11000000, 0b00000000, 0b00000011,
  0b11000000, 0b00000000, 0b00000011,
  0b11000000, 0b00000000, 0b00000011,
  0b11000000, 0b00000000, 0b00000011,
};
int frame3[0x0F] = {                    //Frame 0
  0b01100000, 0b00000000, 0b00000110,
  0b01100000, 0b00000000, 0b00000110,
  0b01100000, 0b00000000, 0b00000110,
  0b01100000, 0b00000000, 0b00000110,
  0b01100000, 0b00000000, 0b00000110,
};
int frame4[0x0F] = {                    //Frame 0
  0b00110000, 0b00000000, 0b00001100,
  0b00110000, 0b00000000, 0b00001100,
  0b00110000, 0b00000000, 0b00001100,
  0b00110000, 0b00000000, 0b00001100,
  0b00110000, 0b00000000, 0b00001100,
};
int frame5[0x0F] = {                    //Frame 0
  0b00011000, 0b00000000, 0b00011000,
  0b00011000, 0b00000000, 0b00011000,
  0b00011000, 0b00000000, 0b00011000,
  0b00011000, 0b00000000, 0b00011000,
  0b00011000, 0b00000000, 0b00011000,
};
int frame6[0x0F] = {                    //Frame 0
  0b00001100, 0b00000000, 0b00110000,
  0b00001100, 0b00000000, 0b00110000,
  0b00001100, 0b00000000, 0b00110000,
  0b00001100, 0b00000000, 0b00110000,
  0b00001100, 0b00000000, 0b00110000,
};
int frame7[0x0F] = {                    //Frame 0
  0b00000110, 0b00000000, 0b01100000,
  0b00000110, 0b00000000, 0b01100000,
  0b00000110, 0b00000000, 0b01100000,
  0b00000110, 0b00000000, 0b01100000,
  0b00000110, 0b00000000, 0b01100000,
};
int frame8[0x0F] = {                    //Frame 0
  0b00000011, 0b00000000, 0b11000000,
  0b00000011, 0b00000000, 0b11000000,
  0b00000011, 0b00000000, 0b11000000,
  0b00000011, 0b00000000, 0b11000000,
  0b00000011, 0b00000000, 0b11000000,
};
int frame9[0x0F] = {
  0b00000011, 0b11000011, 0b11000000,     //Frame 9
  0b00000011, 0b11000011, 0b11000000,
  0b00000011, 0b11000011, 0b11000000,
  0b00000011, 0b11000011, 0b11000000,
  0b00000011, 0b11000011, 0b11000000,
};
int frame10[0x0F] = {
  0b00000000, 0b00111100, 0b00000000,     //Frame 10
  0b00000000, 0b00111100, 0b00000000,
  0b00000000, 0b00111100, 0b00000000,
  0b00000000, 0b00111100, 0b00000000,
  0b00000000, 0b00111100, 0b00000000,
};
int frame11[0x0F] = {
  0b00000000, 0b00011000, 0b00000000,     //Frame 11
  0b00000000, 0b00011000, 0b00000000,
  0b00000000, 0b00011000, 0b00000000,
  0b00000000, 0b00011000, 0b00000000,
  0b00000000, 0b00011000, 0b00000000,
};
int frame12[0x0F] = {
  0b00000000, 0b00010000, 0b00000000,
  0b00000000, 0b00101000, 0b00000000,
  0b00000000, 0b01000100, 0b00000000,
  0b00000000, 0b00101000, 0b00000000,
  0b00000000, 0b00010000, 0b00000000,
};
int frame13[0x0F] = {
  0b00000000, 0b00101000, 0b00000000,
  0b00000000, 0b01000100, 0b00000000,
  0b00000000, 0b10000010, 0b00000000,
  0b00000000, 0b01000100, 0b00000000,
  0b00000000, 0b00101000, 0b00000000,
};
int frame14[0x0F] = {
  0b00000000, 0b01000010, 0b00000000,
  0b00000000, 0b10000001, 0b00000000,
  0b00000001, 0b00000000, 0b10000000,
  0b00000000, 0b10000001, 0b00000000,
  0b00000000, 0b01000010, 0b00000000,
};
int frame15[0x0F] = {
  0b00000000, 0b01000010, 0b00000000,
  0b00000000, 0b10000001, 0b00000000,
  0b00000001, 0b00000000, 0b10000000,
  0b00000000, 0b10000001, 0b00000000,
  0b00000000, 0b01000010, 0b00000000,
};
int frame16[0x0F] = {
  0b00000000, 0b11000011, 0b00000000,
  0b00000001, 0b10000001, 0b10000000,
  0b00000011, 0b00000000, 0b11000000,
  0b00000001, 0b10000001, 0b10000000,
  0b00000000, 0b11000011, 0b00000000,
};
int frame17[0x0F] = {
  0b00000011, 0b00000000, 0b11000000,
  0b00000110, 0b00000000, 0b01100000,
  0b00001100, 0b00000000, 0b00110000,
  0b00000110, 0b00000000, 0b01100000,
  0b00000011, 0b00000000, 0b11000000,
};
int frame18[0x0F] = {
  0b00000110, 0b00000000, 0b01100000,
  0b00001100, 0b00000000, 0b00110000,
  0b00011000, 0b00000000, 0b00011000,
  0b00001100, 0b00000000, 0b00110000,
  0b00000110, 0b00000000, 0b01100000,
};
int frame19[0x0F] = {
  0b00001100, 0b00000000, 0b00110000,
  0b00011000, 0b00000000, 0b00011000,
  0b00110000, 0b00000000, 0b00001100,
  0b00011000, 0b00000000, 0b00011000,
  0b00001100, 0b00000000, 0b00110000,
};
int frame20[0x0F] = {
  0b00011000, 0b00000000, 0b00011000,
  0b00110000, 0b00000000, 0b00001100,
  0b01100000, 0b00000000, 0b00000110,
  0b00110000, 0b00000000, 0b00001100,
  0b00011000, 0b00000000, 0b00011000,
};
int frame21[0x0F] = {
  0b00110000, 0b00000000, 0b00001100,
  0b01100000, 0b00000000, 0b00000110,
  0b11000000, 0b00000000, 0b00000011,
  0b01100000, 0b00000000, 0b00000110,
  0b00110000, 0b00000000, 0b00001100,
};
int frame22[0x0F] = {
  0b11100111, 0b10111101, 0b00010000,     //Frame 22
  0b10010100, 0b00100101, 0b10110000,
  0b11100111, 0b10111101, 0b01010000,
  0b10010100, 0b00100101, 0b00010000,
  0b11100111, 0b10100101, 0b00010000,
};
int frame23[0x0F] = {
  0b00011000, 0b01000010, 0b11101111,     //Frame 22
  0b01101011, 0b11011010, 0b01001111,
  0b00011000, 0b01000010, 0b10101111,
  0b01101011, 0b11011010, 0b11101111,
  0b00011000, 0b01011010, 0b11101111,
};
int frame24[0x0F] = {
  0b11100111, 0b10111101, 0b00010000,     //Frame 22
  0b10010100, 0b10100101, 0b10110000,
  0b11100111, 0b10111101, 0b01010000,
  0b10010100, 0b10100101, 0b00010000,
  0b11100111, 0b10100101, 0b00010000,
};
int frame25[0x0F] = {
  0b00011000, 0b01000010, 0b11101111,     //Frame 22
  0b01101011, 0b11011010, 0b01001111,
  0b00011000, 0b01000010, 0b10101111,
  0b01101011, 0b11011010, 0b11101111,
  0b00011000, 0b01011010, 0b11101111,
};
int frame26[0x0F] = {
  0b11100111, 0b10111101, 0b00010000,     //Frame 22
  0b10010100, 0b10100101, 0b10110000,
  0b11100111, 0b10111101, 0b01010000,
  0b10010100, 0b10100101, 0b00010000,
  0b11100111, 0b10100101, 0b00010000,
};
int frame27[0x0F] = {
  0b00011000, 0b01000010, 0b11101111,     //Frame 22
  0b01101011, 0b11011010, 0b01001111,
  0b00011000, 0b01000010, 0b10101111,
  0b01101011, 0b11011010, 0b11101111,
  0b00011000, 0b01011010, 0b11101111,
};
int frame28[0x0F] = {
  0b11100111, 0b10111101, 0b00010000,     //Frame 22
  0b10010100, 0b10100101, 0b10110000,
  0b11100111, 0b10111101, 0b01010000,
  0b10010100, 0b10100101, 0b00010000,
  0b11100111, 0b10100101, 0b00010000,
};
int frame29[0x0F] = {
  0b00011000, 0b01000010, 0b11101111,     //Frame 22
  0b01101011, 0b11011010, 0b01001111,
  0b00011000, 0b01000010, 0b10101111,
  0b01101011, 0b11011010, 0b11101111,
  0b00011000, 0b01011010, 0b11101111,
};
int frame30[0x0F] = {
  0b11100111, 0b10111101, 0b00010000,     //Frame 22
  0b10010100, 0b10100101, 0b10110000,
  0b11100111, 0b10111101, 0b01010000,
  0b10010100, 0b10100101, 0b00010000,
  0b11100111, 0b10100101, 0b00010000,
};
int frame31[0x0F] = {
  0b11111111, 0b11111111, 0b11111111,     //Frame 31
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b11111111, 0b11111111, 0b11111111,
};
int frame32[0x0F] = {
  0b00000000, 0b00000000, 0b00000000,     //Frame 32
  0b11111111, 0b11111111, 0b11111111,
  0b00000000, 0b00000000, 0b00000000,
  0b11111111, 0b11111111, 0b11111111,
  0b00000000, 0b00000000, 0b00000000,
};
int frame33[0x0F] = {
  0b00000000, 0b00000000, 0b00000000,     //Frame 33
  0b00000000, 0b00000000, 0b00000000,
  0b11111111, 0b11111111, 0b11111111,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
};
int frame34[0x0F] = {
  0b00000000, 0b00000000, 0b00000000,     //Frame 34
  0b00000000, 0b00000000, 0b00000000,
  0b00011111, 0b11111111, 0b11111000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
};
int frame35[0x0F] = {
  0b00000000, 0b00000000, 0b00000000,     //Frame 35
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000,
};


int * frameList[36]= {&frame0[0],
                          &frame1[0],
                          &frame2[0],
                          &frame3[0],
                          &frame4[0],
                          &frame5[0],
                          &frame6[0],
                          &frame7[0],
                          &frame8[0],
                          &frame9[0],
                          &frame10[0],
                          &frame11[0],
                          &frame12[0],
                          &frame13[0],
                          &frame14[0],
                          &frame15[0],
                          &frame16[0],
                          &frame17[0],
                          &frame18[0],
                          &frame19[0],
                          &frame20[0],
                          &frame21[0],
                          &frame22[0],
                          &frame23[0],
                          &frame24[0],
                          &frame25[0],
                          &frame26[0],
                          &frame27[0],
                          &frame28[0],
                          &frame29[0],
                          &frame30[0],
                          &frame31[0],
                          &frame32[0],
                          &frame33[0],
                          &frame34[0],
                          &frame35[0]
                          };