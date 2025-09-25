## 42 Project to set up virtual machine in virtualbox

## notes for evaluation:

Questions:
How does vm work:
- self contained env that runs its own OS

Diff between rocky and dabien
- Rocky alot newer
- Rocky smaller repo 
- Dabien more general, can run on more devices, and more packages
- Dabien more user frenly

Diff between aptitude and apt
- apt easier and simpler, and can ensure all required packages are installed
- apt is a command line only tool
- aptitude allows more control and interactions, users can choose and manage packages based on their pref

Wats AppArmor
- A security module that prevents application actions that access unauthorized resources or perform stupid shit
- When app is executed, AppArmor confines the app so that it can only access wat its allowed to
- Common uses include in webservers and database servers
- Example, for an app thats supposed to sort data, AppArmor allows the app to only have access to specific files that contains data only.

How to check gi used ornot:
ls /user/bin/session, shud display /usr/bin/dbus-run-session

Simple setup:

Check for UFW status:
sudo service ufw status

Check for SSH status:
sudo service ssh status

Check for Dabien:
uname -v

User
Check for groups:
groups cheelim / getent group <group>

How to setup pw requirements:
-vim /etc/login.defs (check for day requirements)
-vim /etc/pam.d/common-password (for other specifics)
   
ucredit / dcredit / lcredit -1, negative means minimum, therefore min 1 char
difok = different chars,
enforce for root = implement policy to root,
,

Adduser:
sudo adduser newuser

Addgroup:
sudo addgroup evaluating

Add user to group:
sudo adduser <name> evaluating

Verify group:
getent group <group>

Hostname and partitions:***

Check for hostname:
hostname

Change hostname:
sudo vim /etc/hostname
sudo vim /etc/hosts

Reboot: 
sudo reboot

Login:
cheelim, same pw

Check hostname 
Change hostname back

Check partitions:
lsblk
Wats LVM:
- logical volume manager
- provides layers of abstraction between storage devices 
- for example, have a small box of alot of stuff ( physical vol / ur hardware), which is stored in a big boxes ( volume groups), inside each group got files for ur stuff (logical volumes)
- volume groups ( cabinet ), physical vol ( drawer ), logical vol ( stuff inside drawer )

Sudo:

check sudo:
which sudo

adduser:
sudo adduser <name> sudo

show rules:
vim /etc/sudoers.d/sudo_config

verify sudo_config file:
cd /var/log/sudo/
vim sudo_config

UFW:

check for usw:
sudo service ufw status / dpkg -s ufw

wat is UFW (uncomplicated firewall) :
simple firewall in Linux,
controls in and out network traffic, prevents malicious activities,

list rules:
sudo ufw status numbered

add rule:
sudo ufw allow 8080
then list rule again

detele port:
sudo ufw delete
SSH:

check ssh:
sudo service ssh status

wats ssh (secure script) :
-ssh is a secure protocol that allows u to connect to a remote system and do stuff
-over an encrypted condition (sercure)
just like ssh-keygen in intra,
-allows u to connect wif intra and access the stuff there privately.

login using ssh:
- ssh root@localhost -p 4242 (show error)
- ssh newuser@localhost -p 4242 

SCRIPT:

check script:
vim /home/cheelim/monitoring.sh
*awk is to manage text data
- phy core and v core: grep to look inside the file to find "phyiscal id" tag, and (wc -l) count the num of lines there, same for v core
- RAM: free --mega to view info abt ram, checks if the first word is mem, then print the corresponding word ($2 is secord word)
- DISK: df -m check disk info ( grep is to take the value wif the tag "dev" smth liddat, grep -v is the inverse ( search all without the tag) ), so basically takes the values which include the tag dev and excludes the tag boot, then sum the value of the third word of each line( $2 means second line).
- CPU: vmstat to check stats, vmstat 1 2 shows tells the comp to print 2 arguments, which another being the stat for 1 second later, then take the 15th value of the second row, and calc the percentage using expr, then print.
- last reboot: cmd who -b to check stats, then look for line wif first word "system" and print the ($3) and ($4) word
- LVM: lsblk check LVM stats, filter for LVM, wc -l count line, -gt 0 checks if line count is bigger than 0, if true then print yes
- TCP: ss -ta to show TCP connections, then count how many lines wif tag ESTAB
- num of users: users to get user list, then count num of words
- network: hostname -I to get MAC, ip link to get link 
- sudo comms: journalctl _COMM=sudo, to get stats with 'sudo' in the comm field, then filter command and count lines

modify time:
sudo crontab -u root -e, then change 10 to 1

stop script:
sudo /etc/init.d/cron stop

to check status:
sudo service cron status

run again:
sudo /etc/init.d/cron start
