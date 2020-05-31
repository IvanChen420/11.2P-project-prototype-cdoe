int led = D6;
int photosensor = A0;
bool moveoutwarning = false;
bool moveinwarning = false;
String plant = "flower";
int maxlightlevel = 200;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(photosensor, INPUT);
}

void loop() {
    // assume we are feed a flower that require max sun light strenth within 400
    int LightData = analogRead (photosensor);
    Particle.publish("LIGHT", String(LightData));
    if(plant == "flower")
    {
        if(LightData > maxlightlevel){
            if(!moveoutwarning){
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                digitalWrite(led,HIGH);
                delay(1000);
                digitalWrite(led,LOW);
                delay(1000);
                moveoutwarning = true;
                Particle.publish("SUN_LIGHT_ON", "Move plant out from the sun light asap, sun light srength is too high could kill plant");
                moveinwarning = false;
            }
        }
        else{
            if(!moveinwarning)
            {
                moveinwarning = true;
                moveoutwarning = false;
                Particle.publish("SUN_LIGHT_OFF", "Sun light strength is good for plant now, try move them to a place that can receive sunlight");
            }
            
        }
    }
    
        
    delay(30000); //wait for 30 seconds
}

int planttype(String type,int lightlevel)
{
    plant = type;
    maxlightlevel = lightlevel;
    return -1;
}