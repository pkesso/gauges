// Pinout of arduino nano PWM
short int pwm_pins[] = {3, 5, 6, 9, 10, 11};
// Size in symbols
short int incoming_line[sizeof(pwm_pins) / sizeof(int)];
// Space as delimeter
//const short int incoming_delimeter = 32;
const char incoming_delimeter = " ";
// \n as End Of Line
//const short int incoming_eol = 10;
const char incoming_eol = "\n";
// Init some vars...
short int gauge_counter = 0;
String incoming_str = "";
short int incoming_int = 0;
char incoming_bytes[10];
String response = ""; //TODO size?
char buff[300] = "";



void setup() {
  // Setting pwm pins mode to output
  for (int pwm_pin = 0; pwm_pin < sizeof(pwm_pins) / sizeof(int); pwm_pin++)
  {
    pinMode(pwm_pins[pwm_pin], OUTPUT);
  }
  // Starting serial port
  Serial.begin(115200);
  Serial.setTimeout(1);
}

// Main loop
void loop() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    delay(1);
    //Serial.readBytesUntil(incoming_delimeter, incoming_bytes, 100);
    Serial.readBytesUntil(incoming_eol, incoming_bytes, 100);
    for (short int counter = 0; counter < sizeof(incoming_bytes) / sizeof(char); counter++) {
      Serial.write(incoming_bytes[counter]);
      if (isDigit(incoming_bytes[counter])) {
        Serial.write("digit \n");
      } else {
        Serial.write("not a digit \n");
        if (incoming_bytes[counter] == incoming_eol) {
          Serial.write("EOL \n");
          break;
        }
      }
    }
    memset(incoming_bytes, 0, sizeof incoming_bytes);
    //incoming_int = incoming_str.toInt();
    //analogWrite(pwm_pins[0], incoming_int);
    //Serial.print(incoming_bytes[0]);

    
    //response.concat(incoming_str);
    //Serial.print(response);
    //response = "";
/*    
    switch (incoming_str) {
      case incoming_delimeter:
        // if delimeter found, just incriment gauge_counter
        gauge_counter++;
        break;
      case incoming_eol:
        // if eol found, it's time to send results to the gauges
        for (int pwm_pin = 0; pwm_pin < sizeof(pwm_pins) / sizeof(int); pwm_pin++)
        {
          analogWrite(pwm_pins[pwm_pin], incoming_line[pwm_pin]);
          incoming_line[pwm_pin] = 0;
        }
        gauge_counter = 0;
        //sprintf(buff, "%s \n", response);
        //Serial.print("Roger! \n");
        Serial.print(response);
        response[0] = 0;
        //*buff = 0;
        break;
      default:
        // in general case, we just collecting digits and concatenating them
        // if it is really a digit
        //if (incoming_str >= '0' && incoming_str <= '9') {
        if (isDigit(incoming_str)) {
          // converting ascii code to int digit
          //int incoming_digit = incoming_str - '0';
          // if it is first digit in line - no need to concatenate
          if (incoming_line[gauge_counter] == 0) {
            incoming_line[gauge_counter] = incoming_digit;
            // else - concatenaing to the digits we already have in this slot (gauge).
          } else {
            incoming_line[gauge_counter] = concat(incoming_line[gauge_counter], incoming_digit);
          }
          // if it is not a [0-9] digit
        } else {
          Serial.print("Not a digit \n");
        }
        break;
    }
*/
  }
}
