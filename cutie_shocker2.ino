int sensorin = A5;
int gatecontrol = 3;
int gate, value, roof, ground, cali, cali2, track; 
unsigned long cmilis, pmilis, c2milis, p2milis;
long interval = 90000;
long interval2 = 10000000;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
//sensor input
pinMode (sensorin, INPUT);

//gate control output
pinMode (gatecontrol, OUTPUT);
analogWrite (gatecontrol, 0);
gate = analogRead (gatecontrol);

   value = analogRead (A5);
//initial calibrations 
    while (roof != value) {
      value = analogRead (A5);
      delay (1000);
      roof = analogRead (A5);
    }

    pmilis = 0; 
}

void loop() {
  // put your main code here, to run repeatedly:
   
    value = analogRead (A5);
    ground = 0;

    time ();

   if (value < 5) {

    time (); 
    
      Serial.print ("one is taken \n" );
      taken();
      
    }
    

    
    if (value > roof + 2){
      Serial.print ("signal out \n"); 
      opengate ();
      
    }

    Serial.print("Sensor reading: ");
    Serial.println(value);
    
    Serial.print("Roof reading: ");
    Serial.println(roof);
   
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
    digitalWrite (gatecontrol, HIGH);  
    delay (1000); 
    digitalWrite (gatecontrol, LOW);
    
    
}

void taken () {
  
     value = analogRead (A5);
     //calibrations 
    while (roof != value) {
      value = analogRead (A5);
      delay (1000);
      roof = analogRead (A5);
    }
  
}

void time () {

      cmilis = millis();

    if (cmilis - pmilis > interval2) {

      pmilis = cmilis; 
    }

}

