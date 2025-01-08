## Opgave 3 - Joystick og fjernstyring - Milepælsopgave

::::Komponentliste::::

Transmitter (Joystick-controller, ESP32):

- Joystick (VRX_PIN og VRY_PIN): Analoge pins til at aflæse joystickets position.
- ESP32 mikrocontroller: Sender joystick-data via ESP-NOW til modtageren.

Receiver (Rover, ESP32):

- ESP32 mikrocontroller: Modtager joystick-data og styrer motorerne.
- 4 DC-motorer: Styret via H-broer til uafhængig kontrol af hvert hjul.
- VL53L0X sensor: Måler afstand til forhindringer.
- 2 Buck Convertere: For stabil strømforsyning.
- Strømforsyning: 2x1800mAh 3.7V Li-ion batterier i serie med spændingsregulator.
- Basen (Chassis): Basen fungerer som fundamentet for roveren og giver en robust platform til montering af alle andre komponenter.
- Stærk lim: Til fastgørelse af motorer
- Dobbeltklæbende tape: Til h broerne hvor vi kan fjerne dem let hvis vi vil gerne reorganisere komponenter  på basen


::::Beskrivelse af joystick samt hvordan fjernstyring virker::::

Joysticket er tilsluttet ESP32-transmitteren, som bruger ESP-NOW-protokollen til at sende data til ESP32 på roveren.

Transmitter:

- Læser X- og Y-værdier fra joystick.
- Sender værdierne trådløst til modtageren med ESP-NOW.
  
Receiver:

- Modtager joystick-data og fortolker X- og Y-aksens værdier.
- Styrer motorerne baseret på disse værdier:
- Y-akse: Frem og tilbage.
- X-akse: Drejning til højre eller venstre.
  
Kommunikation via ESP-NOW:

- Effektiv og hurtig trådløs dataoverførsel mellem to ESP32-enheder uden brug af Wi-Fi-netværk.

::::Specifike spørgsmål::::

  1. Er der blevet brugt structs, funktioner, classes, og til hvad?
     
Structs:

- struct_message (Defineret i både Transmitter.cpp og Receiver.cpp):
- Formål: Bruges til at organisere og overføre joystick-data mellem ESP32-transmitteren og modtageren.
- Indhold: To variabler, xValue og yValue, som gemmer henholdsvis X- og Y-aksens værdier fra joysticket.
- Hvorfor? Strukturer gør det nemt at samle relaterede data i én pakke, som derefter kan sendes effektivt via ESP-NOW.

Funktioner:

- OnDataSent
- Formål: Callback-funktion, der giver feedback om, hvorvidt dataene blev sendt succesfuldt.
- Brug: Hjælper med fejlfinding og sikrer, at forbindelsen fungerer korrekt.

- setup()
- Initialiserer joystick-pins, ESP-NOW og registrerer modtagerens MAC-adresse.

- loop()
- Læser joystick-data og sender dem til modtageren via ESP-NOW.
