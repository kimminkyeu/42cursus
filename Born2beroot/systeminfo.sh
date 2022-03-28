#!/bin/bash


#------------------------------------------------#
#	    	shell created by minkyeki42          |
#------------------------------------------------#

echo -e "\n";
echo -e "-----------------------------------------"
echo -e "|           Partition Status            |"
echo -e "-----------------------------------------"
echo -e "\n"
lsblk
echo -e "\n"
echo -e "press enter to continue..."
read

echo -e "\n";
echo -e "-----------------------------------------"
echo -e "|          checking os release          |"
echo -e "-----------------------------------------"
echo -e "\n"
sudo head -n 2 /etc/os-release
echo -e "\n";
echo -e "press enter to continue..."
echo -e "\n";
read


echo -e "-----------------------------------------"
echo -e "|             Network port              |"
echo -e "-----------------------------------------"
echo -e "\n"
ss -tunlp
echo -e "\n"
echo -e "press enter to continue..."
echo -e "\n"
read

echo -e "-----------------------------------------"
echo -e "|             UFW status                |"
echo -e "-----------------------------------------"
echo -e "\n"
sudo systemctl status ufw
echo -e "\n"
sudo ufw status
echo -e "\n"
echo -e "press enter to continue..."
echo -e "\n"
read

echo -e "-----------------------------------------"
echo -e "|             App-Armor status          |"
echo -e "-----------------------------------------"
echo -e "\n";
sudo systemctl status apparmor
echo -e "\n";
echo -e "press enter to continue..."
echo -e "\n";
read
echo -e "-----------------------------------------"
echo -e "|             App-Armor status2         |"
echo -e "-----------------------------------------"

echo -e "\n";
sudo aa-status
echo -e "\n"
echo -e "press enter to continue..."
echo -e "\n";

echo -e "------------- printing done ---------------"
echo -e "\n";
echo -e "\n";
