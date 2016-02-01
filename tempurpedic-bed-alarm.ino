// This #include statement was automatically added by the Particle IDE.
#include "NCD16Relay/NCD16Relay.h"

NCD16Relay relayController;

int activateAlarm(String command);

void setup() {
    // Set up the Relays
    relayController.setAddress(0, 0, 0);
    relayController.turnOffAllRelays();
    
    // register the cloud functions
    Particle.function("alarm", activateAlarm);
}

void loop() {
}

/*******************************************************************************
 * Function Name  : activateAlarm
 * Description    : Vibrates the foot and head for a specified amount of time, then stops
 * Input          : Alarm duration (1-30) in seconds (String to Int)
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int activateAlarm(String command) {
    // Convert command to int
    int duration = command.toInt();
    int durationMilliseconds = duration * 1000;
    
    // Sanity check to see if the duration is within limits
    if (duration< 1 || duration >30) return -1;

    // Turn on the foot vibration
    relayController.turnOnRelay(1);
    delay(800);
    relayController.turnOffRelay(1);

    // Wait for remote
    delay(1000);
    
    // Turn on the head vibration
    relayController.turnOnRelay(2);
    delay(800);
    relayController.turnOffRelay(2);
    
    // Wait for the specified amount of time
    delay(durationMilliseconds);
    
    // Turn off all vibration
    relayController.turnOnRelay(3);
    delay(1000);
    relayController.turnOffRelay(3);

    return 1;
}
