#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <PubSubClient.h>

const char* mqtt_server = "your_ip_or_host"; 
const int mqtt_port = 1883;
const char* mqtt_user = "/your_virtual_host:your_username"; 
const char* mqtt_pass = "your_pass";
const char* mqtt_topic = "your_routing_key";

#define SOIL_PIN A0

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

void reconnect() {
  while (!client.connected()) {
    Serial.print("Menghubungkan ke MQTT...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_pass)) {
      Serial.println("Terhubung ke RabbitMQ");
    } else {
      Serial.print("Gagal, rc=");
      Serial.print(client.state());
      Serial.println(" -> coba lagi dalam 5 detik");
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
    reconnect();
  }
  client.loop();

  int soilRaw = analogRead(SOIL_PIN);
  float soilValue = (float)soilRaw;

  if (!isnan(soilValue)) {
    if (client.publish(mqtt_topic, String(soilValue, 2).c_str())) {
      Serial.println("Data soil moisture terkirim ke MQTT:");
      Serial.println(soilValue);
    } else {
      Serial.println("Gagal mengirim data ke MQTT");
    }
  }

  delay(2000);
}
