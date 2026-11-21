// C++ code
//
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(10, HIGH);// green on while waiting

  if (digitalRead(2) == LOW)       // button pressed?
  {
    digitalWrite(10, LOW);         // green off
    digitalWrite(9, HIGH);          // yellow on
    delay(2000);                    // 2 seconds

    digitalWrite(9, LOW);          // yellow off
    digitalWrite(8, HIGH);          // red on
    delay(5000);                    // 5 seconds

    digitalWrite(8, LOW);          // red off
    digitalWrite(10, HIGH);       //green on
    delay(5000);                 // 5 seconds
  }
}
 