const int row1 = 5;
const int row2 = 4;
const int column1 = 3;
const int column2 = 2;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void showLight(int row, int column)
{
  // Electricity goes from the row pin to all the LEDs on 
  // that row, through a resistor, and then to the column
  // pins. 
  //
  // So to show a light, the row has to be on and the 
  // column has to be off. So the electricity goes from the 
  // row pin as the source, through the LED and resistor and 
  // then to the column pin as the sink. 
  //
  // All the other rows are off so they don't supply electricity.
  //
  // All the other columns are on so no electricity goes from
  // the row to the column. 
  
  
  // Now show the light.
  // Turn everything else off first, then turn it on.
  if(row == 1)
  {
    digitalWrite(row2, LOW);
    digitalWrite(row1, HIGH);
  }
  if(row == 2)
  {
    digitalWrite(row1, LOW);
    digitalWrite(row2, HIGH);
  }
  if(column == 1)
  {
    digitalWrite(column2, HIGH);
    digitalWrite(column1, LOW);
  }
  if(column == 2)
  {
    digitalWrite(column1, HIGH);
    digitalWrite(column2, LOW);
  }
  
  // If there isn't some sort of rest time, then they all
  // look like they're on but just a little.
  delay(1);
}

void loop()
{
  showLight(1, 1);
  showLight(2, 1);
  showLight(2, 2);
}

