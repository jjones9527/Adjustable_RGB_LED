/*
RGB LED Sketch
RGB LED's Driven from analog output ports
*/

const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const boolean invert = false; //set true if common anode, false if common cathode

int color = 0; // a value from 0 to 255 representing the hue
int R, G, B; //the Red Green and Blue color components

void setup()
{
  // pins driven by analogWrite do not need to be declared as outputs
}

void loop()
{
  int brightness = 255; // 255 is maximum brightness
  hueToRGB( color, brightness); // call function to convert hue to RGB
  // write RGB value to pins
  analogWrite(redPin, R);
  analogWrite(greenPin, G);
  analogWrite(bluePin, B);
  
  color++; // increment color
  if (color > 255)
  color = 0;
  delay (10);
}

// Function to convert a color to its Red, Green, and Blue components

void hueToRGB (int hue, int brightness)
{
  unsigned int scaledHue = (hue * 6);
  // segment 0 to 5 around the color wheel
  unsigned int segment = scaledHue / 256;
  // position within the segment
  unsigned int segmentOffSet = scaledHue - (segment * 256);
  
  unsigned int complement = 0;
  unsigned int prev = (brightness * (255 - segmentOffSet)) / 256;
  unsigned int next = (brightness * segmentOffSet) / 256;
  if(invert)
  {
    brightness = 255 - brightness;
    complement = 255;
    prev = 255 - prev;
    next = 255 - next;
  }
  
  switch(segment)
  {
    case 0: //red
    R = brightness;
    G = next;
    B = complement;
    break;
    
    case 1: //yellow
    R = prev;
    G = brightness;
    B = complement;
    break;
    
    case 2: //green
    R = complement;
    G = brightness;
    B = next;
    break;
    
    case 3: //cyan
    R = complement;
    G = prev;
    B = brightness;
    break;
    
    case 4: //blue
    R = next;
    G = complement;
    B = brightness;
    break;
    
    case 5: //magenta
    R = brightness;
    G = complement;
    B = prev;
    break;
  }
}
    


