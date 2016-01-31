// This #include statement was automatically added by the Particle IDE.
#include "NCD16Relay/NCD16Relay.h"
NCD16Relay relayController;

int turnOnRelay(String command);
int turnOffRelay(String command);

void setup() {
    // Set up the Relays
    relayController.setAddress(0, 0, 0);
    relayController.turnOffAllRelays();
    
    // register the cloud functions
    Particle.function("turnOnRelay", turnOnRelay);
    Particle.function("turnOffRelay", turnOffRelay);
}

void loop() {
}

/*******************************************************************************
 * Function Name  : turnOnRelay
 * Description    : Turns the specified relay on
 * Input          : Relay Number (1-16)
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int turnOnRelay(String command) {
    // Convert command to int
    int relayNumber = command.toInt();
    
    // Sanity check to see if the relay number is within limits
    if (relayNumber< 1 || relayNumber >16) return -1;

    // Turn on the relay
    relayController.turnOnRelay(relayNumber);

    return 1;
}

/*******************************************************************************
 * Function Name  : turnOffRelay
 * Description    : Turns the specified relay off
 * Input          : Relay Number (1-16)
 * Output         : None.
 * Return         : 1 on success and a negative number on failure
 *******************************************************************************/
int turnOffRelay(String command) {
    // Convert command to int
    int relayNumber = command.toInt();
    
    // Sanity check to see if the relay number is within limits
    if (relayNumber< 1 || relayNumber >16) return -1;
    
    // Turn on the relay
    relayController.turnOffRelay(relayNumber);

    return 1;
}
