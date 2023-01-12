char command;

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    Serial.begin(9600); // Set the baud rate to your Bluetooth module.
}

void loop()
{

    if (Serial.available() > 0)
    {
        command = Serial.read();
        // Stop(); //initialize with motors stoped
        // Change pin mode only if new command is different from previous.
        // Serial.println(command);
        switch (command)
        {
        case 'F':
            forward();

            break;
        case 'B':
            back();
            break;
        case 'L':
            left();
            break;
        case 'R':
            right();
            break;

        case 'X':
            Stop();
            break;

        case 'M':
            roundL();
            break;
        case 'N':
            roundR();
            break;
        }
    }
}

void forward()
{
    Stop();
    digitalWrite(8, HIGH);
    digitalWrite(10, HIGH);
}

void back()
{
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
}

void left()
{
    Stop();
    delay(100);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    delay(300);
    Stop();
}

void right()
{
    Stop();
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(300);
    Stop();
}

void Stop()
{
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    digitalWrite(10, 0);
    digitalWrite(11, 0);
}
void roundL()
{
    Stop();
    delay(100);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
}
void roundR()
{
    Stop();
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
}