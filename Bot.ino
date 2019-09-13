int led = 2;
int l1 = 6;
int r1 = 5;
int l2 = 4;
int r2 = 3;

char cmd[100];
int cmdIndex;

void movement() {

  if(strcmp(cmd, "f")==0) {
    digitalWrite(l1, HIGH);
    digitalWrite(r1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(r2, LOW);
  }
  if(strcmp(cmd, "b")==0) {
    digitalWrite(l1, LOW);
    digitalWrite(r1, LOW);
    digitalWrite(l2, HIGH);
    digitalWrite(r2, HIGH);
  }
  if(strcmp(cmd, "l")==0) {
    digitalWrite(l1, LOW);
    digitalWrite(r1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(r2, LOW);
  }
  if(strcmp(cmd, "r")==0) {
    digitalWrite(l1, HIGH);
    digitalWrite(r1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(r2, HIGH);
  }
  if((cmdIndex==0)||(strcmp(cmd,"s")==0)) {
   digitalWrite(l1, LOW);
   digitalWrite(r1, LOW);
   digitalWrite(l2, LOW);
   digitalWrite(r2, LOW);
  }
}

void setup() {
  
  delay(500);
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  cmdIndex=0;
}

void loop() {
  if(Serial.available()) {
    char c = (char)Serial.read();

    if(c=='\n') {
          cmd[cmdIndex] = 0;
      //exeCmd();
      movement();
      cmdIndex=0;
    }
    else {
      cmd[cmdIndex]=c;
      if(cmdIndex<99) cmdIndex++;
      
    }
  }
}
