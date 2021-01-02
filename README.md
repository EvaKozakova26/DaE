# DaE
Developed with Unreal Engine and Blender
 
## Aktuální podoba
 1.1.2021<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/now.PNG "Now")

 
## Menu
 ## Unreal Engine
 - [Navigace po mapě](#navigation-around-map)
 - [Přepínání kamery](#switching-cameras)
 - [Pohyb WSAD](#pohyb-wsad)
 - [Interakce](#interakce)
 - [Rotace kamery](#rotace-kamery)
 ## Blender


---
## Navigation around map

V UE můžeme použít statickou nebo dynamickou navigaci. My používáme dynamickou. To znamená, že výpočet polí, na které může postava vstoupit se provádí dynamicky a relativně k pohybu postavy, takže postava dokáže reagovat na neočekáváné překážky.
### Konfigurace navigace
Pohyb, animace, collidery atd. jsou již nastavené v základním templatu od UE.<br/>
Přes landscape (mapu), po které se postava pohybuje, je nastavena komponenta **NavigationMeshBoundsVolume**.</br>
Nastavení v editoru:
  * Edit -> Project Settings -> Engine -> Navigation System
    * Povolit (check) Navigation Enforcing -> Generate Navigation Only Around navigation Invokers
    
  * Edit -> Project Settings -> Engine -> Navigation Mesh
    * Nastavit Runtime -> Runtime Generation na *dynamic*
    * V Generate se pak nastavují parametry podle výšky agenta (postavy), terénu, sklonu apod...
    
Nakonec se na asset postavy přidá komponenta **Navigation Invokers** a poté se automaticky vygenerují pole. </b>    
Přepínání viditelnosti zelené plochy (navigace) je pomocí klávesy **P**</b>

![navigace](https://github.com/EvaKozakova26/DaE/blob/dev/resources/ue_nav.PNG "Vygenerovaná Navigace")

## Switching cameras
V projektu máme 2 kamery. Hlavní je tzv. Top Down view, tedy pohled ze shora a druhá kamera je klasický pohled z první osoby.

![top down](https://github.com/EvaKozakova26/DaE/blob/dev/resources/top_down_view.PNG "Top Down View")
![fp](https://github.com/EvaKozakova26/DaE/blob/dev/resources/fp_view.PNG "First Person View")

### Jak nastavit kamery
Je potřeba jít do editačního módu naší postavy (TopDownCharacter), tedy WorldOutliner -> TopDownCharacter -> Edit TopDownCharacter</b>
![fp viewport](https://github.com/EvaKozakova26/DaE/blob/dev/resources/fps_viewport.PNG "Edit camera")

Tady jsou důležité 3 kroky pro nastvení First Person Camery:
 * Přidat novou komponentu kamery a vložit ji do Meshe
 * V Socket -> Parent Socket nastavit *head* (kamera je teď podřízená hlavě)
 * Pomocí translace a rotace umístit kameru jako z pohledu první osoby
 
Top Down View Camera je defaultně nastavená v šabloně, ale není problém ji podobných způsobem změnit
![fp viewport](https://github.com/EvaKozakova26/DaE/blob/dev/resources/all_cameras.PNG "Edit camera")

### Přepínání mezi kamerami
Typicky se přepínání kamery realizuje pomocí tlačítka, je tedy potřeba nastavit reakci na stisk tlačítka:
 * Edit -> Project Settings -> Editor -> Input
![fp viewport](https://github.com/EvaKozakova26/DaE/blob/dev/resources/inputs.PNG "Toggle camera inputs")
 * Vstup pojmenujeme tak, aby bylo jasné, k čemu slouží, tedy *Toggle_Perspective*
 * A nastavíme tlačítko **V** (typické pro změnu kamery)
 
Teď stačí pomocí blueprintů "naprogramovat" samotné přepínání:
![fp viewport](https://github.com/EvaKozakova26/DaE/blob/dev/resources/switch_cameras_bp.PNG "Switching cameras blueprints")
Trocha vysvětlení:</b>
 * **InputAction Toggle_Perspective** je reference na input, který jsme definovali v předchozím kroku
 * **First Person Camera, Camera 1** jsou reference na kamery ze scény
 * **FlipFlop** je funkce, která reaguje na opakované přepínání tlačítka (definované v *Toggle_Perspective*)
 * **SetActive** nastavuje danou komponentu (kameru) jako aktivní v reakci na stisk tlačítka přes *FlipFlop* funkci 

## Pohyb WSAD
Nastavení ovládání postavy pomocí WSAD lze jednoduše udělat přes blueprinty a nastavení inputů.
* Nastavení **AXIS** inputů na tlačítka WSAD
  * W pohyb dopředu - hodnota 1 a S - pohyb dozadu - (inverzní) hodnota -1
  * D pohyb doprava - hodnota 1 a A - pohyb doleva - (inverzní) hodnota -1
 ![input](https://github.com/EvaKozakova26/DaE/blob/dev/resources/inputs.PNG "inputs")

* Graf v Blueprintu
  * **InputAction MoveForward/MoveRight** je reference na input, který jsme definovali v předchozím kroku
  * **Add Movement Input** Metoda, která realizuje pohyb daným směrem
    * **World Direction** - směr pohybu, hodnota z *Get Forward/Right Vector*
    * **Scale Value** - hodnota, kterou se daný směrový vektor vynásobí a tím se určí směr dopředu/dozadu, popř. doleva/doprava. Viz obrázek inputů.
  * **Get Forward/Right Vector** Metoda, která získá hodnotu vektoru (pro daný směr) relativně k současné pozici postavy
   ![wsad](https://github.com/EvaKozakova26/DaE/blob/dev/resources/wasd.PNG "wsad blueprints")
   
## Interakce
V této dokumentaci je popsána interakce hráče a vstupní brány: Na stisk tlačítka E se brána otervře a následně se po menší prodlevě sama zavře.<br/>
Je potřeba vytvořit novou *Blueprint Class* - náš název je DOORS_Gate. Zde nás zajímají 2 sekce - *Viewport* a *EventGraph*.
#### Viewport
![gate](https://github.com/EvaKozakova26/DaE/blob/dev/resources/gate_viewport.PNG "gate viewport") <br/>
Do Viewportu je potřeba přetáhnou objekt, se kterým chceme provádět interakci, tedy v našem případě bránu (pravá i levá vrata).<br/>
Pivot (bod počátku) musí být nastaven tak, aby se dalo dvěřmi rotovat (otevírat je) po ose Z.<br/>

#### Event Graph (Blueprint)
Je potřeba definovat vlastní proměnné
* *IsTrigger* - boolean, kolize je/není triggrovaná
* *Open* - boolean, brána je/není otevřena
* *Angle_Left/Right* - float, úhel, do kterého se dveře mají otevřít
![graph](https://github.com/EvaKozakova26/DaE/blob/dev/resources/gate_bp.PNG "gate viewport") <br/>
Co znamenají jednotlivé nody a jak to spolu funguje: <br/>
* **Gate Interaction** - skupina nodů, která detekuje interakci a  provádí základní nastavení proměnných
  * **Get Player Controller** - Getter pro získání Player Controlleru
    * *PlayerController* - rozhraní mezi *Pawn* a fyzickým hráčem, řídí, co chci s postavou dělat
    * *Pawn* - základní třída Actora, fyzická reprezentace (AI, fyzická lokace, interakce, kolize, rotace,...) to vše detekuje právě *Pawn*
  * **On Component Begin Overlap (Box)** - Událost, která detekuje začátek "kolize" s boxem (colliderem)
  * **On Component End Overlap (Box)** - Událost, která detekuje opuštění kolize
  * **Enable Input** - povoluje, že Actor (gate) může přijímat inputy od *PlayerController*
  * **Disable Input** - zakazuje Actorovi přijímat inputy od *PlayerController*
  * **Set IsTrigger** - nastavuje hodnotu proměnné *IsTrigger* <br/>
*Při opuštění kolize proběhne invertovaná rotace*
  * **Branch** - rozhodovací větev, v tomto případě: Pokud *Open* je *true*, prověď další akci
  * **Delay** - Následující akce se zavolá až po určité prodlevě
  * **Sequence** - Vykoná se *n* akcí za sebou
    * V tomto případě se volá parametr *Reverse* u timeliny obou vrat *doors* - animace otevírání tedy proběhne obráceně - brána se zavře
* **Gate Right** - skupina nodů, která provádí otevírání pravých dveří
  * **InputAction Interact** - Detekce input akce definované v Project Settings (v tomto případě stisk tlačítka **E**)
  * **Branch** - rozhodovací větev, v tomto případě: až se stiskne tlačítko a *IsTrigger* je *true*, tak proveď další akci
  * **doors_r (timeline)** - popisuje vývoj proměnné v čase
    * realizace animace
    * v tomto případě: *Angle* se posune z 0 na 130 za 1s po ose Z (viz *SetRelativeRotation*)
  * **SetRelativeRotation** - funkce, která danou rotaci vykonává
* **Gate Left** - skupina nodů, která provádí otevírání levých dveří
  * stejný princip jako u *Gate Right*

## Rotace kamery
V projektu lze při stisku středního tlačítka myši rotovat kamerou jak je libo.<br/>
Základní nastavení kamery je popsáno v kapitole [Přepínání kamery](#switching-cameras).<br/>
Zbyek se nastavuje v blueprintech. Nejprve je se detekuje stisk tlačítka: <br/>
![trigger](https://github.com/EvaKozakova26/DaE/blob/dev/resources/trigger_camera_move.PNG "trigger camera move") <br/>
* **EventTick** - nejzákladnější událost při běhu hry, volá se každý frame
* **Gate** - začíná/ukončuje stream událostí<br/>
*Tedy každý frame se dostaneme do proudu událostí, které jsou otevřeny, tedy v tomto případě se stream otevře při stisku středního tlačítka myši*
* **CameraMovement** - naše custom funkce, kde definujeme samotný pohyb kamery
  * ![cam_move](https://github.com/EvaKozakova26/DaE/blob/dev/resources/camera_move.PNG "camera move") <br/>
  * **GetWorldRotation** - Vrátí aktuální rotaci targetu, tedy kamery (Spring Arm 1)
    * *Rotator* - 3 floaty repreyentující rotaci v 3D prostoru (Roll - X, Pitch - Y, Yaw - Z)
  * **BreakRotator** - "rozbije" Rotator na úhly a stupně (Roll, Pitch, Yaw)
  * **Clamp (float)** - nastaví hranice (min/max), kterých může daní hodnota dosáhnout
  * **MakeRotator** - sestaví Rotator z dodaných hodnot
  * **SetWorldRotation** - provede rotaci objektu podle vstupního Rotatoru<br/>
 *Tedy nejprve získáme aktuální hodnoty rotace z kamery, ponecháme hodnoty na ose X, osy Y a Z dopočítáme podle pohybu myši a následně z hodnot vytvoříme novou rotaci.*<br/>
 *To vše pokud držíme střední tlačítko myši. Po povolení se Gate uzavře.*








  



 



 
