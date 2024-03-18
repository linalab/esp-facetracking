import oscP5.*;
import netP5.*;
float val1;
float val2;
float val3;

OscP5 oscP5;
NetAddress remoteLocation;
  
void setup(){ 
  oscP5 = new OscP5(this,12000); // receiving in port 12000
  size(400,400);
  
}

void draw(){
  //println(val1);
 if(val2 < 0.33){
 background(2500*val2, 0, 0, 3);
 }
 if(val2 > 0.33 && val2 < 0.6){
 background(0, 3000*val2, 0, 3);
 }
 if(val2 > 0.6){
 background(0, 0, 2000*val2, 3);
 }
 
 strokeWeight(1);
 stroke(0,31);
        noFill();
        beginShape();
        for(int i = 0; i < val1* 100; i++) {
                float x = noise(i * 15 + frameCount * 0.001) * width;
                float y = noise(i * 15 + frameCount * val3/100 )* height; //.002
                vertex(x, y);
        }
        endShape(CLOSE);
 //circle(width/2,height/2,val1*100);

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
  if(theOscMessage.addrPattern().equals("/miau")){
 
  val3 = theOscMessage.get(0).floatValue();
  //println("The OSC message get(0) : "+val1);
  }
}
