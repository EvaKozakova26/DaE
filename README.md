# DaE
Developed with Unreal Engine and Blender
 
## Aktuální podoba
 1.1.2021<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/1.png "Now")<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/2.png "Now")<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/3.png "Now")<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/4.png "Now")<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/5.png "Now")<br/>
 ![now](https://github.com/EvaKozakova26/DaE/blob/dev/resources/dae/6.png "Now")<br/>
 
 
## High Level Game Design
autor: DavidBarak1</br>
___
Jedná se o RPG realtime low poly hru ze středověku s prvky budování. Skupina 5 osadníků se pokouší vybudovat novou vesnici ve velice nehostinmém, avšak úrodném kraji. První děj hry obsahuej zákaldní 3 suroviny.Jídlo, kámen a dřevo. Vedlejší suroviny budou např. kůže, voda.  Nástroje budou z těchto surovin. Pouze zbraně si osadníci vezou železné od kováře. Jejich síla a životnost  bude 2x vyšší než dřevěné a kamenné. Všechna NPC zvládají pouze útočit na nepřátelé ve svém dosahu. Nemouhou však chodit na lov, nebo něco vyrábět. Druhá  fáze hry bude obsahovat první souboj s vlky. Třetí fáze již vyžaduje funkci pro následování naší postavy pro potřebné výpravy. Zde však stále útočí NPC pouze tehdy, pokud se nepřítel dostane do vzdálenosti 6 metrů.  Čtvrtá fáze hry bude již vyžadovat další možnost vedení. Např. nejslabší postava bude mít na starost sklízet obilí. Silnější postavy budou chodit pro suroviny.<br/>

#### Rozložení postav bez banditů bude:
  * 1 slabá postava (farmář)
  * 2 silné postavy (dělníci)
  * 1 stavitel
  * naše hlavní postava. Zde budou možné 3 profese, které změní základní atributy: 
    * **válečník**, který bude silný, ale slabší na výdrž a nižší rychlost pohybu.  
    * **bandita**, který má velkou výdrž a rychlost, avšak není silný.
    * **měšťan**, který je pomalý a slabý, ale má větší inventář a 1.15x rychlejší získávání zkušeností.  
#### Zde je základní popis pro prví kapitolu, která má 5 částí
  1. Hlavní postava bude jeden z původních obyvatel (prvních 5) nově vznikající osady. Jako první úkol bude vybudováno ohniště a stany (suroviny jsou již naložené ve vozíku, který osadníci vezou. Vůž bude mít pouze 2 kola a obsahovat základní materiál (klády, dřeva, maso a kámen) *--- Cca 5-10 minut---*
  2. Po zajištění dostatečného množství surovin bude vybudován první srub a základní opevnění (plot z větví a kůly s hroty). Osadu v tuto chvíli napadne směčka 3-4 vlků, která však nebude žádný problém, protože skupina má ve vozíku zbraně (bez zbroje). Vlci poskytnou na dalších 30-40 minut jídlo. *----- cca 15 minut----*
  3. Další fáze bude o průzkumu okolí. V severní části lesní lokace bude stará pila. Zde budou 2-3 nepřátelé (bandité), kteří zabijí 1 člena skupiny. Po krátké bitvě však přijdou další 2-3 bandité, kteří se ke skupině přidají. Následuje shromaždování materiálu a výroba nástrojů na těžbu materiálu + vozík na jeho dopravu do osady. *---cca 30 minut---*
  4. Následuje fáze, během které budou vybudovány další 2-3 sruby a vylepšené opevnění (palisádové). Bude následovat lov zvěře pro získání jídla a kůží. Následuje příprava pole a zasazení pšenice, která bude růst cca 15 minut. Její sklizení bude probíhat pomocí přiblížení se k poli se správným nástrojem
  5. Osada potřebuje více jídla. Je tedy potřeba postavit ohrady pro zvířata (krávu, koně a králíky). Zvířata nebudou vázána na 1 pozici a pokud nejsou v ohradě, tak mohou chodit po celém světě bez možnosti jejich nuceného návratu. Vlci v okolí je také mohou napadnout a zabít. Krávy i koně vyžadují krmení a vodu. Pro tyto účely budou již dostupné další stavby jako je sklad pšenice, trávy a výstavba studny. Studna bude vyžadovat 10 kusu dřeva a 30 kusu kamení, nástroje kladivo a pila. 
