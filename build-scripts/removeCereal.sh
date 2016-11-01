##BEFORE USING PLEASE MAKE SURE TO USE THIS AS A SUPER USER
# sudo sh removeCereal.sh or sudo ./removeCereal.sh



# Change to the cereal include directory
cd /usr/include/cereal

#recursively delete everything in THAT DIRECTORY ONLY
rm * -r -f
#switch back up to /usr/include
cd ../

#delete the cereal directory
rmdir cereal/

