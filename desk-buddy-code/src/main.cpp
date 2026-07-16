#include "M5Unified.h"

void setup()
{
  auto cfg = M5.config();
  M5.begin(cfg);
  M5.Display.setTextDatum(middle_center);
  M5.Display.setTextColor(TFT_BLACK);
  M5.Display.setTextFont(&fonts::Orbitron_Light_24);
  M5.Display.setTextSize(1);
  M5.Display.setBrightness(5);

}

void loop()
{
  M5.Display.clear(TFT_WHITE);

  bool isCharging = M5.Power.isCharging();
  int vol_per = M5.Power.getBatteryLevel();

  M5.Display.setCursor(0, 30);
  M5.Display.printf("Charging: %s \n\n", isCharging ? "Yes" : "No");
  M5.Display.setCursor(0, 60);
  M5.Display.printf("BAT: %d%%", vol_per);
  delay(5000);
}
