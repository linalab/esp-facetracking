import oscP5.*;
import netP5.*;
float val1;
float val2;

OscP5 oscP5;
NetAddress remoteLocation;
  
void setup(){ 
  oscP5 = new OscP5(this,12000); // receiving in port 12000
  size(400,400);
  
}

void draw(){
  //println(val1);
 background(2500*val2, 255, 255*val2);
 circle(width/2,height/2,val1*100);

} 


void oscEvent(OscMessage theOscMessage){
  print("this is the osc message : ");
  print(" addPattern : "+theOscMessage.addrPattern());
  print(" type tag "+theOscMessage.typetag());

  if(theOscMessage.addrPattern().equals("/touch1")){
 
  val1 = theOscMessage.get(0).floatValue();
  //println("The OSC message get(0) : "+val1);
  }
  if(theOscMessage.addrPattern().equals("/filter")){
 
  val2 = theOscMessage.get(0).floatValue();
  //println("The OSC message get(0) : "+val1);
  }
}
