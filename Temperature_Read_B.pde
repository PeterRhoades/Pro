import processing.serial.*; // imports library for serial communication  
Serial port; // defines Object Serial  
float val;
int c = 0;
PFont font;


void setup()
{
  size(1000,700);
  String arduinoPort = Serial.list()[1];
  port = new Serial(this, arduinoPort, 115200);
  font = createFont("SourceCodePro-Regular.ttf", 32);
  textFont(font);
  
}

void draw()
{
  if (port.available() > 0)
  {
  c++;
    background(val + 100); //Use int=Val to Change colour of background:
  val = port.read();
  print (val);
   print ("  ");
    println (c);
    int i = int(val);
  {
  
  textSize(32);
  fill(123 + val * 2); //Use int=Val to Change colour of Left/Right Bar:
  quad(900, 600 - val * 8, 950, 600 - val * 8, 950, 680, 900, 680); //Use int=Val to Increase Right Bar:
  ellipse(width/2, 640 - val * 5, val * 5, val * 5); //Use int=Val to Move&Size: 
  fill(0);
  line(900, 600 - val * 8, width/2, 640 - val * 5);
  line(900, 680, width/2, 640 - val * 5);
  text(i, 905, 590 - val * 8);
 fill(0);
 line(150, 680 - c, width/2, 640 - val * 5);
 line(150, 680, width/2, 640 - val * 5);
 textSize(32);
 text(c, 105, 670 - c);
 float m = map(c, 0, 600, 0, 255);
 fill(m); //Use int=Val to Change colour of Left/Right Bar:
 quad(100, 680 - c, 150, 680 - c, 150, 680, 100, 680); //Use int=Val to Increase Left Bar:
}
if (c > 600) c = 0;
}
}
