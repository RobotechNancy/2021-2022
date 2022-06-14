# Le code permet de réaliser :

- la communication entre l'écran STM32F7G-DISCO et la RaspberryPi (envoi/réception de trames)

> *Remarque :* Tous les codes sont écrits en style **C/C++**

# Format de la trame des messages envoyés à l'écran :

| Mode        | Catégorie          | Sous-Catégorie       | Data        | Fin de trame  |
| ----------- | ------------------- | --------------------- | ----------- | ------------- |
| *1 octet* | *1 octet*         | *1 octet*           | *X octet* | *2 octets*  |
| `C`       | `I`               | `O/B/X/C`           | `<value>` | `0x0A 0x0D` |
| `M`       | `T/X/P/S/C/L/M/G` | `<selon categorie>` | `<value>` | `0x0A 0x0D` |

**Descriptions :**

- *[mode]*            :     `M (maintenance)` / `C (compétition)`
- *[catégorie]*      :

  {maintenance}

  - `C (bus CAN)` - `L (Lidar)` - `M (moteurs PAP)` - `G (gyroscope/capt. optique)`
  - `T (capteurs ToF)` - `X (xbee)` - `P (pompe à vide)` - `S (servomoteur)`

  {compétition} -> `I (initialisation)` - `S (score)` - `E (choix equipe)`
- *[sous-catégorie]* :

  {maintenance} -> `numéro du capteur ou de la carte`

  {initialisation} -> `O (odométrie)` - `B (base roulante)` - `X (xbee)` - `C (bus CAN)`

  {score} -> `P (score petit robot)` - `G (score grand robot)` - `T (score total)`

# Installation du code (sous Linux x86-64) :

```bash
git clone https://github.com/RobotechNancy/2021-2022.git
```

[**Username** : votre nom d'utilisateur GitHub]

[**Password** : vous devez générer un personal access token dans `Github -> Settings -> Developer Settings -> Personal Access Token -> Generate new token`]

```bash
cd 2021-2022/Pôle\ informatique/Communication/Communication\ inter-robots/xbee/  

g++ *.cpp -std=c++17 -o output

./output
```

# Publication d'une nouvelle version du code :

```bash
git pull && git add * && git commit -m "Version XX.XXR" && git push
```

[**Username** : votre nom d'utilisateur GitHub]

[**Password** : vous devez générer un personal access token dans `Github -> Settings -> Developer Settings -> Personal Access Token -> Generate new token`]
