import processing.serial.*; // imports library for serial communication  
Serial port; // defines Object Serial  
int val;

void setup()
{
  size(1000,700);
  String arduinoPort = Serial.list()[0];
  port = new Serial(this, arduinoPort, 115200);
  
}

void draw()
{
  if (port.available() > 0)
  {
  background(255);
  val = port.read();
  println (val);
  fill(123 + val * 2);
  quad(100, 600 - val * 8, 200, 600 - val * 8, 200, 640, 100, 640);
  ellipse(width/2, 640 - val * 6, val * 5, val * 5); //Use int=Val to Move&Size 
  delay(500);
}
}
