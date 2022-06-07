# Tutoriel pour implémenter un point d'accès sans fil sur une RaspberryPi

##### Utilité du point d'accès :

Le point d'accès d'une RaspberryPi permet de pouvoir créer un réseau sans fil directement sur la carte sans avoir besoin qu'elle se connecte à un partage de connexion distant pour y accéder.

Cette fonction est particulièrement utile lorsqu'on a besoin de se connecter à plusieurs à une RaspberryPi ou lorsqu'on se trouve dans un endroit sans possibilité d'effectuer un point d'accès autre.

```
/!\ Attention : Ce tutoriel ne permet pas d'effectuer le routage de la connexion internet via la RaspberryPi. 
Le point d'accès sans fil ainsi créé ne permettra pas d'accéder à internet ! 

Une solution est de mettre en place un partage de connexion via USB en branchant son téléphone à la RaspberryPi 
via USB et en sélectionnant l'option "Modem USB" dans les paramètres de connexion.
```


##### Mise en place du point d'accès :

On vérifie tout d'abord que le système est bien à jour, et on installe les paquets nécessaires :

```bash
sudo apt update -y && sudo apt upgrade -y 
```
```bash
sudo apt install hostapd dnsmasq -y
```

On effectue ensuite les configurations nécessaires :

```bash
sudo systemctl stop hostapd dnsmasq
```

```bash
sudo nano /etc/hostapd/hostapd.conf
```

On ajoute le code suivant à la fin du fichier :
```
interface=wlan0
driver=nl80211
ssid=robotechnancygrand
hw_mode=g
channel=7
wmm_enabled=0
macaddr_acl=0
auth_algs=1
ignore_broadcast_ssid=0
wpa=2
wpa_passphrase=Robotech2022@
wpa_key_mgmt=WPA-PSK
wpa_pairwise=TKIP
rsn_pairwise=CCMP
```

```bash
sudo systemctl unmask hostapd && sudo systemctl enable hostapd
```

```bash
sudo nano /etc/default/hostapd
```

On décommente la ligne et on la complète comme ceci :

```
DAEMON_CONF="/etc/hostapd/hostapd.conf"
```

```bash
sudo nano /etc/dnsmasq.conf
```

On ajoute le code suivant à la fin du fichier :

```
interface=wlan0
domain-needed
bogus-priv
dhcp-range=192.168.50.150,192.168.50.200,255.255.255.0,12h
```

```bash
sudo nano /etc/dhcpcd.conf
```

On ajoute le code suivant à la fin du fichier :

```
interface wlan0
nohook wpa_supplicant
static ip_address=192.168.50.10/24
static routers=192.168.50.1
```

On redémarre la RaspberryPi :

```bash
sudo reboot
```

##### Connexion au point d'accès :

- Connexion au wifi généré par la RaspberryPi **[mot de passe : Robotech2022@]**
- Connexion en ssh
```
ssh pi@192.168.50.10 
```
**[mot de passe : robotech2022]**


##### Désactivation du point d'accès :

```bash
sudo nano /etc/dhcpcd.conf
```

Commenter les lignes suivantes (à la fin du fichier) :

```bash
#interface wlan0
#nohook wpa_supplicant
#static ip_address=192.168.50.10/24
#static routers=192.168.50.1
```

On désactive les services réseaux :

```bash
sudo systemctl disable dnsmasq hostapd
```

On redémarre la RaspberryPi :

```bash
sudo reboot
```

##### Réactivation du point d'accès :

```bash
sudo nano /etc/dhcpcd.conf
```

Décommenter les lignes suivantes (à la fin du fichier) :

```bash
interface wlan0
nohook wpa_supplicant
static ip_address=192.168.50.10/24
static routers=192.168.50.1
```

On réactive les services réseaux :

```bash
sudo systemctl enable dnsmasq hostapd
```

On redémarre la RaspberryPi :

```bash
sudo reboot
```
