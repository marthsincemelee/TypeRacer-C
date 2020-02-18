# TypeRacer-C
Programmierprojekt an der DHBW Stuttgart 2020 - 
TypeRacer-C
TINF19D Teilnehmer: 

- Elvira Kraft [3653393]
- Finn Markwitz [7770624]
- Leon Unbehaun [9905042]

### Entwickler Dokumentation

#### 1. Konzept

Das Projekt TypeRacer-C wird verschiedene Algorithmen beinhalten, welche vor allem zur Textverarbeitung genutzt werden. Das Spiel soll helfen, die Tippgeschwindigkeit zu ermitteln und eventuell zu verbessern. Folgende Features gehören zu den Grundkomponenten, die implementiert werden sollen:

-	Anzeigen eines Menüs, in dem der Anwender eine Wahlmöglichkeit hat, das Spiel zu beginnen, sich die Liste mit Highscores anzeigen zu lassen oder das Spiel zu verlassen;
-	Spielen des Spiels, indem man die angezeigten Wörter möglichst schnell abtippen soll;
-	Anzeigen von geschaffter Geschwindigkeit, diese wird gemessen und in die Highscores Liste eingetragen;
-	Highscores anzeigen 

#### 2. Programmaufbau

TypeRacer-C wird in C umgesetzt und besteht ausfolgenden Dateien: 
-	main.c mit dem Quellcode;
-	highscores.txt, die Datei mit den 10 gespeicherten Geschwindigkeiten der Anwender.

#### 3. Quellcodestruktur

Für die Erstellung des Quellcodes wurden in main.c folgende Standardbibliotheken benutzt: 
- #include <stdio.h>
- #include <stdlib.h>
- #include <time.h>
- #include <string.h>
- #include <unistd.h>

Zum Speichern der Daten werden die Arrays definiert:

1.  wordsToWrite: enthält die Wortauswahl die das Spiel verwendet.
2.	highscores: hier werden die von Anwendern erreichten Highscores temporär gespeichert.

##### Methoden
- showMenue() - zeigt das Hauptmenü an und wartet bis der Anwender seine Wahl eingibt
- checkInput() - wird innerhalb der showMenue()-Methode verwendet um die Eingabe des Anwenders zu verifizieren und die daraus folgende Funktion auszuführen
- startGame() - eine der Hauptfunktionen des Spiels, diese Funktion startet eine neue Spielrunde und führt den Anwender durch den Spielprozess
- backToMenue() - leitet den Benutzer zum Hauptmenü zurück
- createNewHighscore() - ein neue Highscore wird erstellt und in dem Array an passender Position eingeordnet
- showHighscores() - Wird im Hauptmenü aufgerufen und führt dazu, dass der Anwender die zehn besten bis her erreichten Zeiten mit den dazugehörigen Nutzernamen angezeigt bekommt
- initHighscore() - Für den Fall, dass das Spiel das erste Mal ausgeführt wird, wird mithilfer dieser Methode das Highscore Array spielbereit gemacht
- importHighscore() - importiert die Highscores von vorherigen Spielen aus der highscores.txt Datei, bzw. erstellt diese wenn sie noch nicht existiert
- exportHighscore() - exportiert das Array in die highscores.txt Datei
- bubblesort() - sortiert das Highscore Array anhand von den Zeiten der Anwender
- compareHighscores() - wird verwendet um die klarzustellen wann ein Highscore besser als ein andere ist und somit einen höhren Platz im Array bekommen sollte

Innerhalb der main Methode wird zuerst die importHighscore() Methode und danach showMenue() und exportHighscore() gerufen.



