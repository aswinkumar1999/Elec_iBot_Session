# Elec_iBot_Session

Have a Problem/ Resource that's not listed , Submit an Issue ( https://help.github.com/en/articles/creating-an-issue ) 

Make sure you include all proper details and the solutions you have tried before you have created an issue.

# Troubleshooting 

Remember the Sequence it works ?? ( NO ? Check the Document )

Bluetooth --> Arduino --> Motor Driver 

So , If you've Built a circuit and it doesn't work , then the issue is probably with any of the Above three. 

How to Start Testing  / Find which one is causing the Error ??

Does all three Modules ( Bluetooth , Arduino , Motor Driver ) light up ? 

If Yes go with the Below ones on testing everything individually.

If NO ? the Module which does not glow have been shorted and will not work anymore, Don't worry you can always order one online / go to a Shop outside Insti to get it  ( Check the Resources Section Below ).

Found Some Module / IC to be hot ? 

Not so Great news !! You would have burnt it , Check out the Resources Section on where to buy a new one.

### Bluetooth 

```
char Incoming_value = 0;                //Variable for storing Incoming_value
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
}
void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
  }                            
} 
```
Put this code into your Arduino IDE and Upload the code. ( !! REMEMBER to Unplug the TX , RX from Arduino always when you upload code ) 

Now , Open your Robo Remo App and The Serial Monitor of Arduino and see if you can 'f' ,'b'  when you press the up key and back key respectively. 

If you can , then Great , your Bluetooth Module is Working Properly. Move on to the Next Step. 

#### Only Detects Sometimes / Automatically Disconnects after one or two clicks ? 

So , Your Input power to the Bluetooth is not sufficient for it to Work properly. Power the Arduino using a Power bank to get it working on the bot or Follow the Hack Below.

Remove Vcc of Bluetooth Module and Connect it to Pin 2 of Arduino and Add the below lines to the Code.

Add the Follow lines to void setup() function of the bot.ino code 

```
void setup(){
.
.
pinMode(2, OUTPUT);           // Add these two lines at the end of the function.
digitalWrite(2, HIGH);
}

```

What does it do ?  It tried to Provide 5V to the Bluetooth which was initially provided with 3.3V. 

#### Cannot go into AT Mode ? 

Is the Circuit Proper ? 

Are there any loose connections? 

Remember you need to press the button while uploading the code to switch it to AT Mode  ? 

After you upload the Code , you need to Close and open your Serial Monitor for it to work. 

### Motor Driver 

Ever Found your Board to be hot ? Get a New One.

Try writting Code setting l1 HIGH and l2 LOW and check if the motors rotate. Because if it doesn't then the problem is usually with the Motor driver and a motor driver can be destroyed easily. So , Make sure you don't short it / Power it on before checking your circuit twice.


### Arduino 

If Bluetooth and Motor Driver Lights up , but you cannot upload code to Arduino and if the IC is hot , you would have probably burnt it , *but shorting an Arduino isn't easy , they have inbuilt mechanisms to prevent it* so see if there are other issues as mentioned above before assuming that you have burnt your Arduino.



## What Next ? 

## Resources 

Motor Driver -> https://www.amazon.in/Adraxx-L293D-Motor-Driver/dp/B01NAJHRJ0/ref=sr_1_10?keywords=L293d&qid=1568454815&s=gateway&sr=8-10 

Arduino -> https://www.amazon.in/Uno-ATmega328P-Compatible-ATMEGA16U2-Arduino/dp/B015C7SC5U/ref=sr_1_2?crid=3NM0XG50EOCYF&keywords=arduino+uno+r3+board&qid=1568454839&s=gateway&sprefix=Arduino%2Caps%2C739&sr=8-2 

Bluetooth Module -> https://www.amazon.in/HC-05-Bluetooth-Module-10g/dp/B00X86U4RW/ref=sr_1_3?keywords=Hc+-+05&qid=1568454849&s=gateway&sr=8-3 

Other Sites where you can get electronic components from : 

https://robu.in/ 

https://robokits.co.in/robot-kits

https://www.amazon.in/

Offline ? 

Mercy Electronics ->https://maps.app.goo.gl/YxBv7Rd5VP1V8WXV9
