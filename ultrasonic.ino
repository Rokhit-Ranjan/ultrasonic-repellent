#include "WiFi.h"
#include "esp_wifi.h"

// Callback function to handle received packets
void promiscuous_callback(void *buf, wifi_promiscuous_pkt_type_t type) {
    wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buf;
    
    // Print the MAC address of the received packet
    Serial.print("Packet received: ");
    for (int i = 0; i < 6; i++) {
        Serial.printf("%02X", pkt->payload[i]);
        if (i < 5) Serial.print(":");
    }
    Serial.println();
}

void setup() {
    Serial.begin(115200);

    // Set WiFi to station mode and disconnect from any AP
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    // Enable promiscuous mode
    esp_wifi_set_promiscuous(true);
    esp_wifi_set_promiscuous_rx_cb(promiscuous_callback);
}

void loop() {
    // No need to do anything here, packets are handled in the callback
}
