## Opgave 3 - Joystick og fjernstyring - Milepælsopgave

### Komponentliste

**Transmitter (Joystick-controller, ESP32):

Joystick (VRX_PIN og VRY_PIN): Analoge pins til at aflæse joystickets position.
ESP32 mikrocontroller: Sender joystick-data via ESP-NOW til modtageren.
Receiver (Rover, ESP32):

ESP32 mikrocontroller: Modtager joystick-data og styrer motorerne.
4 DC-motorer: Styret via H-broer til uafhængig kontrol af hvert hjul.
VL53L0X sensor (ikke færdigintegreret): Måler afstand til forhindringer.
2 Buck Convertere: For stabil strømforsyning.
Strømforsyning: 2x1800mAh 3.7V Li-ion batterier i serie med spændingsregulator.
Andet: MDF-chassis designet og skåret med lasermaskine.
### Beskrivelse af joystick samt fjernstyrings
