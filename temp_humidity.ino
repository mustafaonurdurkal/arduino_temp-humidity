#include <dht11.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int dht = 7;
dht11 sensor;
int button = 4;
int button_state = 0;
boolean flag = false;
boolean buttonPress = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button, INPUT);
  
}

void loop() {
  
  button_state = digitalRead(button);

  if(button_state == HIGH && buttonPress==false)
  {
    if(flag == false)
    {
      flag = true;
    }
    else
    {
      flag = false;
    }
    buttonPress = true;
    //Serial.print(flag);
  }
  else {
    buttonPress=false;
  
  }
 
  if(flag == true)
  {
    lcd.setCursor(0,0);
    int dht_value = sensor.read(dht);
    
    if((int)sensor.temperature < 10)
    {
      lcd.print("SIC(C):  ");
      lcd.print((int)sensor.temperature);
    }

    else if((int)sensor.temperature > 10 && (int)sensor.temperature < 100)
    {
      lcd.print("SIC(C): ");
      lcd.print((int)sensor.temperature);
    }
    else
    {
      lcd.print("SIC(C):");
      lcd.print((int)sensor.temperature);
    }
    
    lcd.print(",00 TR");
    lcd.setCursor(0,1);
    if((int)sensor.humidity < 10)
    {
      lcd.print("NEM(%):  ");
      lcd.print((int)sensor.humidity);
    }

    else if((int)sensor.humidity > 10 && (int)sensor.humidity < 100)
    {
      lcd.print("NEM(%): ");
      lcd.print((int)sensor.humidity);
    }
    else
    {
      lcd.print("NEM(%):");
      lcd.print((int)sensor.humidity);
    }
    
    lcd.print(",00");
  }
  else
  {
    lcd.setCursor(0,0);
    int dht_value = sensor.read(dht);
    //float fh = sensor.fahrenheit();
    if(sensor.fahrenheit() < 10)
    {
      lcd.print("TEM(F):  ");
      lcd.print(sensor.fahrenheit(),2);
    }

    else if(sensor.fahrenheit() > 10 && sensor.fahrenheit() < 100)
    {
      lcd.print("TEM(F): ");
      lcd.print(sensor.fahrenheit(),2);
    }
    else
    {
      lcd.print("TEM(F):");
      lcd.print(sensor.fahrenheit(),2);
    }
    
    lcd.print(" EN");
    lcd.setCursor(0,1);
    if((float)sensor.humidity < 10)
    {
      lcd.print("HUM(%):  ");
      lcd.print((float)sensor.humidity,2);
    }

    else if((float)sensor.humidity > 10 && (float)sensor.humidity < 100)
    {
      lcd.print("HUM(%): ");
      lcd.print((float)sensor.humidity,2);
    }
    else
    {
      lcd.print("HUM(%):");
      lcd.print((float)sensor.humidity,2);
    }
    
  }
  
}
