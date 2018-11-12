int sensorin = A5;
int sensorin2 = A4; 
int gatecontrol = 3;
int gate, value, roof, ground, cali, cali2, track, value2, roof2;
int speaker = 8; 
unsigned long cmilis, pmilis, c2milis, p2milis;
long interval = 3000;
long interval2 = 100;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
//sensor input
pinMode (sensorin, INPUT);
pinMode (sensorin2, INPUT); 
//gate control output
pinMode (gatecontrol, OUTPUT);
analogWrite (gatecontrol, 0);
gate = analogRead (gatecontrol);

   value = analogRead (A5);
//initial calibrations 
    while (roof != value) {
      value = analogRead (A5);
     delay (100);
      roof = analogRead (A5);
    }

    pmilis = 0; 
    p2milis = 0;
    digitalWrite (9, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
   
    value = analogRead (A5);
    ground = 0;

    time3 ();

   if (value < 5) {
      value2 = analogRead (A4);
      //while (value2 < 125) {
       
    time2 (); 
    
      Serial.print ("one is taken \n" );
      taken();
      //}
    }
    
  value = analogRead (A5);
  value2 = analogRead (A4);
    if (value >= roof + 2){
      Serial.print ("signal out \n"); 
      opengate ();
      time3 (); 
    }

    Serial.print("Sensor reading: ");
    Serial.println(value);
   // Serial.print("Sensor2 reading: ");
   // Serial.println(value2);
    Serial.print("Roof reading: ");
    Serial.println(roof);
    //Serial.print("Roof2 reading: ");
    //Serial.println(roof2);
    //Serial.print("Ground reading: ");
    //Serial.println(ground);
     /*
   if (value > 45) {
      Serial.print ("gate is open!! You have ten seconds. \n"); 
      opengate (); 
   }
   */
   digitalWrite (gatecontrol, LOW); 
   delay (1000); 
}

void opengate () {
      tone(speaker, 1000, 500);
    
    
}

void taken () {
  
     value = analogRead (A5);
     //calibrations 
    while (roof != value) {
      value = analogRead (A5);
  delay (100);
      roof = analogRead (A5);
    }
  
}

void time2 () {

    

    while (cmilis - pmilis < interval) {
      cmilis = millis();
      
    }
    pmilis = cmilis; 
}

void time3 () {

    

    while (c2milis - p2milis < interval2) {
      c2milis = millis();
      
    }
    p2milis = c2milis; 
}

