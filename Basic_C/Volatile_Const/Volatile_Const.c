#include <stdio.h>

// Global variable declared as volatile
volatile int sensorValue = 0;

// Function that simulates hardware updating a volatile variable
void updateSensorValue() {
    // Imagine this value comes from a hardware register
    sensorValue = 42;
}

// Function using a const parameter
void printMessage(const char *msg) {
    // msg[0] = 'H';  // ❌ This would be an error because msg is const
    printf("Message: %s\n", msg);
}

int main() {
    // --- const example ---
    const int maxValue = 100;
    printf("Constant maxValue: %d\n", maxValue);
    // maxValue = 120; // ❌ This would be an error because maxValue is const

    printMessage("Hello from const!");

    // --- volatile example ---
    printf("Reading sensorValue (before update): %d\n", sensorValue);
    
    updateSensorValue();  // Simulate hardware changing the value
    
    printf("Reading sensorValue (after update): %d\n", sensorValue);

    return 0;
}
