# DaE - Developed with Unreal Engine 4
 
 ## Menu
 - [Navigace po mapě](#navigation-around-map)
   
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
 
