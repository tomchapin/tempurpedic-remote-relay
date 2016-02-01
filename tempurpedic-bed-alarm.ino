// This #include statement was automatically added by the Particle IDE.
#include "NCD16Relay/NCD16Relay.h"

NCD16Relay relayController;

int startAlarm(String command);
int stopAlarm(String command);
bool alarmRunning = false;


void setup() {
    // Set up the Relays
    relayController.setAddress(0, 0, 0);
    relayController.turnOffAllRelays();
    
    // register the cloud functions
    Particle.function("startAlarm", startAlarm);
    Particle.function("stopAlarm", stopAlarm);
}


void loop() {
    // Once every 15 minutes (900,000 ms), ensure that no relays were left on
    // This is a safety feature to ensure none of the relays ever overheat
    // Note: This is most likely completely unnecessary, but I'm doing it anyway!
    delay(900000);
    if (!alarmRunning) {
        relayController.turnOffAllRelays();
    }
    
}


/*******************************************************************************
 * Function Name  : startAlarm
 * Description    : Vibrates the foot and head
 * Input          : command (String) - ignored
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int startAlarm(String command) {
    alarmRunning = true;

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

    return 1;
}


/*******************************************************************************
 * Function Name  : stopAlarm
 * Description    : Stops the vibration
 * Input          : command (String) - ignored
 * Output         : None.
 * Return         : 1
 *******************************************************************************/
int stopAlarm(String command) {
    
    // Ensure buttons are not being pressed
    relayController.turnOffRelay(1);
    relayController.turnOffRelay(2);
    
    // Turn off all vibration
    relayController.turnOnRelay(3);
    delay(1000);
    relayController.turnOffRelay(3);
    
    alarmRunning = false;
    
    return 1;
}
