#BEFORE USING PLEASE MAKE SURE TO USE THIS AS A SUPER USER
# sudo sh getCereal.sh or sudo ./getCereal.sh



#cloning into cereal
git clone https://github.com/USCiLab/cereal.git 

#enter the cereal git clone
cd cereal/include  
#Make the Includes folder
mkdir /usr/include/cereal
mv cereal/* /usr/include/cereal -v

echo "Deleting cloned folder"
cd ../../
rm -r -f -d -v 

#Now it is installed on your system :) inside your include folder
