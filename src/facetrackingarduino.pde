import java.awt.Rectangle;

import hypermedia.video.*;

OpenCV opencv;
boolean xtrue = false; //variable used to see whether the x co-ordinates of the face are inside the middle quadrant
boolean ytrue = false; //same as above but y co-ordinates instead
int left=80;
int right=240;
int top;
int bottom;

Serial arduinoPort;

import processing.serial.*;  

void setup() {

    size( 320, 240 );
    arduinoPort = new Serial(this, "COM9", 9600); //change this to whichever port your arduino is on
    opencv = new OpenCV(this);
    opencv.capture( width, height );
    opencv.cascade( "C:\\Program Files (x86)\\OpenCV\\data\\haarcascades\\cascade_15_color.xml" );   // change this to where your frontal face xml is located
}

void draw() {
    
    opencv.read();
    image( opencv.image(), 0, 0 );
    
    // detect anything ressembling a FRONTALFACE
    Rectangle[] faces = opencv.detect();
    if (opencv.detect()==null){
    println("STOP");
    arduinoPort.write("k");
  }
    // draw detected face area(s)
    noFill();
    stroke(255,0,0);
    for( int i=0; i<faces.length; i++ ) {
      
    faces[i].width=faces[i].width/2;
    faces[i].height=faces[i].height/2;
        rect( faces[i].x, faces[i].y, faces[i].width, faces[i].height ); 
        
        
    if(faces[i].x<left){
    println("LEFT");
    arduinoPort.write("a");
  }
  else if(faces[i].x + faces[i].width > right){
    println("Right"); 
    arduinoPort.write("d");
   }
  else if ((faces[i].x > left) && (faces[i].x + faces[i].width < right)){
    println("go");
    arduinoPort.write("w");
  }
  }
   
   //line(0, 80, 320, 80);  //top
   //line(0, 160, 320, 160); //bottom
   line(left, 240, left, 0); //left 
   line(right, 0, right, 240); //right  
   
}
