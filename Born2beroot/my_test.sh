#!/bin/bash

echo -e "\032[31mSystem Partion\032[0m"
lsblk
echo -e "\n"
echo -e "press enter to continue..."
read

echo -e "checking os release"
sudo head -n 2 /etc/os-release
echo -e "\n";
echo -e "press -eter to continue..."
read

echo -e "System status"
sudo aa-status
echo -e "\n"
echo -e "press enter to continue..."
read

echo -e "Network port"
ss -tunlp
echo -e "\n"
echo -e "press enter to continue..."
read

echo -e "UFW status"
sudo /usr/sbin/ufw status
echo -e "\n"
echo -e "printing done"

