# ESP8266-NodeMCU
Su questo repositori sulla pagina della wiki farò una piccola guida basilaree su come utilizzare la Board sopra citata.
Se non vi bastano le informazioni qui scritte si può far riferimento alla documentazione [NodeMCU](http://nodemcu.readthedocs.io/en/master/).

# Installare i Driver
Potrebbe non essere necessario installare il driver, il vostro pc potrebbe riconosce la Board automaticamente.
Se ciò non accade, è necessario installare i driver. Se avete un NodeMCU v0.9 o un chip per il seriale-USB chx i driver sono scaricabili in versione aggiornata su [questo sito](http://www.wch.cn/download/CH341SER_LINUX_ZIP.html) (per windows è il file .zip senza esplicitamente scritto windows).
Per installare i driver su linux è necessario 
* compilare, quindi dopo essersi posizionati col terminale nella cartella contenente il driver eseguire il comando:
`sudo make`
* caricarlo:
`sudo make load`
* se si se si desidera eliminarlo
`sudo make unload`

# Programming Mode
Per andare in programming mode sulla Board si devono configurare i seguenti pin:
* GPIO 0: LOW (D3)
* GPIO 2: HIGH (D4)
* GPIO 15: LOW (D8)
(tra parentesi nomi sulla Board Nodemcu StarterKit v0.9)
Ora è possibile connettere la bord al PC

# Flashing Firmware
Si può fare da windows con tool grafici scaricabili a [questo link](https://github.com/nodemcu/nodemcu-flasher). Oppure su tutte le piattaforme con [esptool](https://github.com/espressif/esptool).
Dobbiamo anche scaricare il firmware NodeMCU che possiamo trovare [qui](https://github.com/nodemcu/nodemcu-firmware/releases) (a noi serve il .bin).
Si può utilizzare esptool da linux nel seguente modo:
* Per cancellare qualsiasi cosa sia presente sulla Board
`sudo python esptool.py --port /dev/ttyUSB0 --baud 115200  erase_flash`
* Per caricare il firmware
`sudo python esptool.py --port /dev/ttyUSB0  write_flash -fm dio -fs 32m 0x00000 The_Path_To_The_NodeMCU_Firmware.bin`

# Prorgramming
Si può programmare con:
* Arduino Ide: 
 * necessario installare le Board ESP 
 * linguaggio C like
 * sconsigliato per il poco controllo 

* ESPlorer: utilizzabile direttamente
 * nessuna aggiunta necessaria
 * linguaggio Python like
 * consigliato
