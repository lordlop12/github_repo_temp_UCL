## Opgave 3 - Joystick og fjernstyring - Milepælsopgave

:::: Komponentliste ::::

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

_____________

:::: Beskrivelse af joystick samt hvordan fjernstyring virker ::::

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



:::: Specifike spørgsmål ::::

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

_________

- setup()
- Initialiserer joystick-pins, ESP-NOW og registrerer modtagerens MAC-adresse.

_________

- loop()
- Læser joystick-data og sender dem til modtageren via ESP-NOW.

_________

- onDataReceived
- Formål: Callback-funktion, der aktiveres, når ESP32 modtager data.
- Brug: Opdaterer joystick-værdier og styrer motorerne.

_____________

Motorstyringsfunktioner:

- moveForward()
- moveBackward()
- turnLeft()
- turnRight()
- stopMotors()
- Formål: Hver funktion styrer specifikke motorer baseret på joystick-input.

__________

Classes:
- Der er ingen klasser i vores kode.
- Funktionaliteten er implementeret gennem strukturer og funktioner-
____________

2. Hvilke libraries er blevet brugt og til hvad? (#include statements)

#include <WiFi.h>
- Formål: Bruges til at konfigurere ESP32 i Wi-Fi Station Mode for ESP-NOW-kommunikation.

#include <esp_now.h>
- Formål: Muliggør direkte kommunikation mellem ESP32-enheder uden Wi-Fi-netværk.

Vigtigste funktioner:
- esp_now_init() → Initialiserer ESP-NOW.
- esp_now_add_peer() → Tilføjer en peer-enhed til netværket.
- esp_now_send() → Sender data.
- esp_now_register_send_cb() → Registrerer callback for sendestatus.
- esp_now_register_recv_cb() → Registrerer callback for modtagelse af data.

__________

3. Hvordan har I anvendt metoder I har lært i undervisningen?

ESP-NOW Kommunikation:
- Callback-funktionerne (send og modtag) er korrekt brugt til at sikre stabil datatransmission.

Brug af Structs til Dataoverførsel:
- Samlet joystick-data i en struktur og sendt hele strukturen i én ESP-NOW-pakke.

Motorstyring:
- Motorfunktionerne er opdelt i små moduler (moveForward, turnLeft osv.), hvilket gør koden mere overskuelig og nem at fejlsøge.

Serial Debugging:
- Anvendelse af Serial Monitor til fejlfinding og overvågning af joystick- og motorværdier.

________

:::: Udfordringer undervejs ::::
1. Hvilke udfordringer mødte I undervejs?
- Kommunikationsproblemer mellem ESP32-enheder i starten.
- Ustabil strømforsyning til motorer og ESP32.
- Kalibrering af motorer og hjul for korrekt retningskontrol.
- Forkert målt 3D-printede dele.

2. Hvordan løste I dem?
- Brug af ESP-NOW's callback-funktioner til fejlfinding af sendestatus.
- Tilføjelse af buck converters for stabil strømforsyning.
- Korrekt mål af 3D-pintede dele.

3. Hvorfor tror I, de opstod?
- Begrænset erfaring med trådløs kommunikation (ESP-NOW).
- Fejlmarginer i 3D-printning.
- Variabel spænding og strømforbrug fra motorer og ESP32
