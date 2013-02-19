const int yellow = 2;
const int white = 3;
const int black = 4;
const int red = 5;
const int green = 6;
const int blue = 7;
const int purple = 8;

const int numRows = 4;
const int numColumns = 3;
bool lights[numRows][numColumns];
int rowPins[numRows];
int columnPins[numColumns];
unsigned long lastTime = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // Go from row number to pin number
  rowPins[0] = yellow;
  rowPins[1] = white;
  rowPins[2] = black;
  rowPins[3] = red;

  // Go from column number to pin number
  columnPins[0] = green;
  columnPins[1] = blue;
  columnPins[2] = purple;
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


  for(int r=0;r<numRows;r++)
  {
    if(r==row && lights[row][column])
      digitalWrite(rowPins[r], HIGH);
    else
      digitalWrite(rowPins[r], LOW);
  }

  for(int c=0;c<numColumns;c++)
  {
    if(c==column && lights[row][column])
      digitalWrite(columnPins[c], LOW);
    else
      digitalWrite(columnPins[c], HIGH);
  }

  // If there isn't some sort of rest time, then they all
  // look like they're on but just a little.
  delayMicroseconds(100);
}

void showRandomLights()
{
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
    showRandomLights();
  }
}


