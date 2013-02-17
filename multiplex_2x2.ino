const int row1 = 5;
const int row2 = 4;
const int column1 = 3;
const int column2 = 2;

const int numRows = 2;
const int numColumns = 2;
bool lights[numRows][numColumns];
int rowPins[numRows];
int columnPins[numRows];
unsigned long lastTime = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  // Go from row number to pin number
  rowPins[0] = row1;
  rowPins[1] = row2;
  
  // Go from column number to pin number
  columnPins[0] = column1;
  columnPins[1] = column2;

  // This is to make an L from the lights.
  lights[0][0] = true;  
  lights[0][1] = false;  
  lights[1][0] = true;  
  lights[1][1] = true;  
}

// row and column are not like in math where the index number 
// starts with 1, but they  start with 0.
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
  
  
  // Turn everything else off first, then turn it on.
  for(int r=0;r<numRows;r++)
  {
    digitalWrite(rowPins[r], LOW);
  }
  for(int c=0;c<numColumns;c++)
  {
    digitalWrite(columnPins[c], HIGH);
  }
  
  // Now show the light.
  digitalWrite(rowPins[row], HIGH);
  digitalWrite(columnPins[column], LOW);
  
  // If there isn't some sort of rest time, then they all
  // look like they're on but just a little.
  delay(1);
}

void loop()
{
  for(int i=0;i<numRows;i++)
  {
    for(int j=0;j<numColumns;j++)
    {
      if(lights[i][j])
        showLight(i, j);
    }
  }
  
  // One time every second change the lights.
  unsigned long now = millis() / 1000;
  if(now!= lastTime)
  {
    lastTime = now;
    for(int i=0;i<numRows;i++)
    {
      for(int j=0;j<numColumns;j++)
      {
        if(random(2))
          lights[i][j] = false;
        else
          lights[i][j] = true;
      }
    }
  }
}

