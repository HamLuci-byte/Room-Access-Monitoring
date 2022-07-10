

int L1 = 2; //laser1
int L2 = 4; //laser2

int buzzer = 5;

int LDR1 = 0; //sensor1
int LDR2 = 0; //sensor2

int people = 6; //max limit
int _time = 0;

int count = 0;
int prevC = 0;
int max_time = 10*1000; 

int i = 0;


// the setup routine runs once when you press reset:


void setup() {
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  
  // initialization serial communication
  Serial.begin(9600);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
}


void loop() {

  while(LDR1<200 && LDR2<200 && _time < max_time){
    if(count > people){
      delay(1);
      _time++;
      if(_time%1000 == 0){
      }
    }
    if(analogRead(A1)<250){
      LDR1 = analogRead(A0);
    }
    if(LDR1 < 250){
      LDR2 = analogRead(A1);
    }
  }

  // for reset, to evoid error
  if(LDR2 > 250){
    if(i==0){i++;} 
    else{count++;}
  }
  else if(LDR1 > 250){
    if (count>0){
      count--;
    }
  }

  // print data on serial screen
  if(count != prevC){
  Serial.print("LDR1: ");
  Serial.print(LDR1);
  Serial.print("; LDR2: ");
  Serial.print(LDR2);
  Serial.print("; count: ");
  Serial.println(count);
  prevC = count;
  }
       
  if((count > people) && (count <= (people + 3)) && (_time < max_time) ){
    analogWrite(buzzer, 10);
  }
  else if((count > (people + 3)) || (_time >= max_time)){
    analogWrite(buzzer, 100);
    _time = 0;
  }
  else if(count <= 6){
    analogWrite(buzzer, 0);
    _time = 0;
  }
  // print out the value you read:


  delay(2000);

  LDR1 = 0;
  LDR2 = 0;
}
