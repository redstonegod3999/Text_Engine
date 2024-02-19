// Include the libraries for OLED and keypad
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

// Define the OLED display address and size
#define OLED_ADDR 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Create an OLED display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define the keypad rows and columns
const byte ROWS = 4;
const byte COLS = 4;

// Define the keypad characters
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Define the keypad row and column pins
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Create a keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define a variable to store the keypad input
char key;
int i;
int j;
void setup() {
  // Initialize the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // Set the text size and color
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Set the cursor position
  display.setCursor(0, 0);
  display.display();
}

void loop() {
  // Read the keypad input
  key = keypad.getKey();
  // If a key is pressed
  if (key) {
      display.setCursor(i, j);
      display.write(key);
      display.display();
      i += 6;
      if (i >= 128) {
        i = 0;
        j += 8;
        i += 6;
      }
  }
}
