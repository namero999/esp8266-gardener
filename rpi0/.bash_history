passwd
sudo apt update
sudo apt upgrade

sudo dphys-swapfile swapoff
sudo vim /etc/dphys-swapfile
sudo dphys-swapfile setup
sudo dphys-swapfile swapon

wget -qO- https://repos.influxdata.com/influxdb.key | sudo apt-key add -
echo "deb https://repos.influxdata.com/debian buster stable" | sudo tee /etc/apt/sources.list.d/influxdb.list
sudo apt-get update && sudo apt-get install influxdb
sudo systemctl enable influxdb
sudo systemctl start influxdb

sudo apt-get install -y adduser libfontconfig1
wget https://dl.grafana.com/oss/release/grafana-rpi_6.2.5_armhf.deb
sudo dpkg -i grafana-rpi_6.2.5_armhf.deb
sudo systemctl enable grafana-server
sudo systemctl start grafana-server

sudo apt install htop ncdu vim autossh tmux

https://docs.influxdata.com/influxdb/v1.7/supported_protocols/udp/
sudo vim /etc/sysctl.conf
sudo vim /etc/influxdb/influxdb.conf
reboot
sudo vim /etc/motd
vim .bashrc
ssh-keygen -t rsa
sudo vim /boot/config.txt -> append dtoverlay=pi3-disable-bt
sudo systemctl stop avahi-daemon
sudo systemctl disable avahi-daemon
sudo systemctl stop bluetooth
sudo systemctl disable bluetooth

on server
sshd_config
ClientAliveInterval 120
ClientAliveCountMax 1
GatewayPorts yes
