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

void loop()
{
  digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW);
  digitalWrite(column1, LOW);
  digitalWrite(column2, HIGH);
  delay(1000);
  digitalWrite(row1, HIGH);
  digitalWrite(row2, LOW);
  digitalWrite(column1, HIGH);
  digitalWrite(column2, LOW);
  delay(1000);
  digitalWrite(row1, LOW);
  digitalWrite(row2, HIGH);
  digitalWrite(column1, LOW);
  digitalWrite(column2, HIGH);
  delay(1000);
  digitalWrite(row1, LOW);
  digitalWrite(row2, HIGH);
  digitalWrite(column1, HIGH);
  digitalWrite(column2, LOW);
  delay(1000);
}

