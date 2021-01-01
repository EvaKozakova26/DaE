# DaE - Developed with Unreal Engine 4
 
## Aktuální podoba
 1.1.2021<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/now.PNG "Now")

 
## Menu
 ## Unreal Engine
 - [Navigace po mapě](#navigation-around-map)
 - [Přepínání kamery](#switching-cameras)
 - [Pohyb WSAD](#pohyb-wsad)
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
Nastavení ovládání postavy pomocí WSAD lze jednoduše udělat přes blueprinty a nastavení inputů.</b>
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

  



 



 
