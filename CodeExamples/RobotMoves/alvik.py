from arduino_alvik import ArduinoAlvik
from time import sleep_ms

def init():
  alvik.left_led.set_color(0, 0, 1)
  while(not alvik.get_touch_ok()):
    sleep_ms(50);
  alvik.left_led.set_color(0, 1, 0)

######################################################

alvik = ArduinoAlvik()
alvik.begin()

# Keine Ahnung was das soll, machen alle so
init()

for i in range(3):
  # Pruefe auf Hindernisse
  L, CL, C, CR, R = alvik.get_distance()
  if C>50:  # cm
    # Gradeausfahrt
    alvik.drive(15, 0, 'cm/s', 'deg/s')
    sleep_ms(5000)
    # Kurvenfahrt / Drehung um 180 Grad
    if i%2 == 0:
      alvik.drive(5, 30, 'cm/s', 'deg/s') 
    else:
      alvik.drive(5, -30, 'cm/s', 'deg/s') 
    sleep_ms(6000) # Habe ich gestoppt, klappt gut

# Aus die Maus
alvik.left_led.set_color(0, 0, 1)
alvik.stop()