#!/bin/bash

########################################
# Example: ./setAccount.sh 1 or 2      #
########################################

#Check git status
git status
echo ""
echo "----------------t(*^*t)------------------" 

#Check Account Information
echo "Checking Account"
git config --list | grep user.*
echo ""
echo "----------------t(*^*t)------------------" 

#Enter your option
#INPUT=${1}
echo "Please choose the optionn to mofidy account information."
echo "[0] Do nothing"
echo "[1] Before commiting the changes"
echo "[2] After commiting the changes"
read -p "Enter your option: " option
INPUT=${option}

f_check(){
    if [[ ! ${1} ]];
    then
        echo "Wrong format. Please choose the option: Mofidy account information 1(before) or 2(after) commiting the changes"
        #exit -1
    else
        if [[ ${1} -eq 0 ]];
        then
            echo "Bye, dude. See you again ~~~~"
        elif [[ ${1} -eq 1 ]];
        then
            echo "You chosed 1: Let's start"
            git config --global user.name "SilverBoom"
            git config --global user.email dduynam.vt@gmail.com
        elif [[ ${1} -eq 2 ]];
        then
            echo "You chosed 2: The changes were already committed and you want to modify"
            git config --global user.name "SilverBoom"
            git config --global user.email dduynam.vt@gmail.com
            git commit --amend --reset-author
        else
            echo "Please choose the option: Mofidy account information 1(before) or 2(after) commiting the changes"
        fi
    fi
}

f_check ${INPUT}

echo "Done <3 <3 <3 <3 <3 <3 <3 "
echo "----------------t(*^*t)------------------" 
