#include <WiFi.h>
#include <WiFiManager.h>
#include <PubSubClient.h>

const char* mqtt_server = "195.35.23.135"; // masukkan ip/url host server kalian
const int mqtt_port = 1883;
const char* mqtt_user = "/virtual_host_anda:user_anda"; // isikan virtual host dengan / sebelumnya
const char* mqtt_pass = "password_kalian";
const char* mqtt_topic = "routing_key_kalian";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  WiFiManager wifiManager;
  if (!wifiManager.autoConnect("????")) { // ganti ???? menjadi nama SSID yang bisa kalian bebas tentukan sendiri
    Serial.println("Gagal terhubung, mereset...");
    delay(3000);
    ESP.restart();
  }
  Serial.println("Terhubung ke Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void reconnectMQTT() {
  while (!client.connected()) {
    if (client.connect("ESP32_ACT_Client", mqtt_user, mqtt_pass)) {
      client.subscribe(mqtt_topic);
    } else {
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();
}