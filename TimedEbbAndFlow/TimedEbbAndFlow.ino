
#include <time.h>

int pump_fill  = 12; // pump from reservoir to control tank - purple
int pump_drain = 13; // pump from control tank to reservoir - brown

// switches
int switch_full = 7; // Switch engages when control tank is filled   
int switch_empty = 8; // Switch disengages when control tank is empty

// int mTime, mInc, iLoopCount, iLastTime, ;
unsigned long iStartMin = 300; 
unsigned long iSubMin = .25;

unsigned long iStartUp = 0;
unsigned long iLoopCount = 0;
unsigned long iCycleCount = 0;

unsigned long iCurrentMillis = 0;
unsigned long iNext = 0;
unsigned long iDelay = 50000L;
unsigned long mUntil = 0;

unsigned long iMinute = 60000L;

enum eStatus {
  Drain, Empty, Fill, Full, Off
};

eStatus currentStatus = Off;

void setup() {
  Serial.begin(9600); 
  pinMode( pump_drain, OUTPUT );
  pinMode( pump_fill, OUTPUT );
  pinMode( switch_empty, INPUT_PULLUP );
  pinMode( switch_full, INPUT_PULLUP );
  digitalWrite(pump_drain, LOW);
  digitalWrite(pump_fill, LOW);
  iDelay = 5000L;
}

void floop() {
  iCurrentMillis = millis();
  Serial.println( "iCurrentMillis: " + String(iCurrentMillis));
  Serial.println( "currentStatus: " + String(currentStatus));
  if( iNext == 0 || iNext >= iCurrentMillis ) {
    Serial.println( "iNext: " + String( iNext ) );
  }
}

void loop() {
  iCurrentMillis = millis();
  Serial.println( "loop: " + String(iCurrentMillis));
  Serial.println( "currentStatus: " + String(currentStatus));
  bool ba = iNext == 0;
  Serial.println( "iNext == 0: " + String(ba));
  bool bb = iNext >= iCurrentMillis;
  Serial.println( "iNext >= iCurrentMillis: " + String(bb));
  // bool bc = currentStatus == Off;
  // Serial.println( "currentStatus == Off: " + String(bc));
  
  Serial.println( "iNext: " + String(iNext));
  if( iNext == 0 || iNext <= iCurrentMillis ) {
    if( currentStatus == Off ) {
      Serial.println( "Start DoFill: " + String(iCurrentMillis));
      // start everyting
      iLoopCount++;
      DoFill();
    }
  }

  if( currentStatus == Fill ) {
    Serial.println( "Check Fill: " + String(iCurrentMillis));
    // if currently filling, check switch_full 
    if(digitalRead(switch_full) == LOW ) { // if switch_full is ON
      // Turn off pump_fill
      digitalWrite( pump_fill, LOW );
      // fill_time = time(0);
      DoDrain();    
    }
  }
  if( currentStatus == Drain ) {
    Serial.println( "Check Drain: " + String(millis()));
    // if draining, check switch_empty
    if( digitalRead(switch_empty) == HIGH ) { // if switch_empty is OFF
      // control tank is empty, turn pump off
      digitalWrite(pump_drain, LOW );
      currentStatus = Off;
      iNext = iCurrentMillis + ( ( iStartMin - iLoopCount ) * iMinute ) ;
      Serial.println("iCurrentMillis: " + String( iCurrentMillis ) + " || iNext: " + String(iNext));
  // bool bca = currentStatus == Off;
  // Serial.println( "currentStatus == Off: " + String(bca));
  //     int iAddMinutes = iStartMin - iLoopCount;
  //     int mills = millis();
  //     Serial.println("Current mills: " + String(mills));
  //     Serial.println("iAddMinutes: " + String(iAddMinutes));
  //     if( iAddMinutes < 0 ) iAddMinutes = iAddMinutes * -1;
  //     long iAddMinInSecs = iAddMinutes * 60;
  //     Serial.println("iAddMinInSecs: " + String(iAddMinInSecs));
  //     long iAddMsSecs = iAddMinInSecs * 1000;
  //     Serial.println("iAddMsSecs: " + String(iAddMsSecs));
  //     iNext = mills + iAddMsSecs;
  //     Serial.println("SET iNext: " + String(iNext));
      iDelay = 30000L;//( ( iStartMin - iLoopCount ) * iMinute );
      // if( iStartMin > 100) {
      //   if( iDelay < (2L * 60L * iMinute)) {
      //     iDelay = 2L * 60L * iMinute;
      //   }
      // }
    }
  }
  // mUntil = iNext - iCurrentMillis;
  // if( mUntil < 60000 ) {
  //   iNext = 0;
  //   iDelay = 0;
  // }
  Serial.println( "Time: " + String(iCurrentMillis) + " || iDelay: " + String(iDelay) );
  delay(iDelay);
}

void DoFill() {
  Serial.println( "DoFill" );
  if( currentStatus == Off ) {
    // If the current status is off, turn pump_fill ON
    digitalWrite( pump_fill, HIGH );
    currentStatus = Fill;
    iDelay = 1000L; // while filling, check switch every second
  }
}

void DoDrain() {
  Serial.println( "DoDrain" );
  //delay( (60 * HANGTIME) * 1000 );
  // start draining
  digitalWrite(pump_drain, HIGH);
  currentStatus = Drain;
  iDelay = 1000L; // while draining, check switch every second
}