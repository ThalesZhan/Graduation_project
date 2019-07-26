#!/bin/bash
# Compile all source file and build the executable file
# execute all program 

#Get file name from files of samples
./Pre_Process/File_Name/Read_Filename.sh ./samples/Test_Chalky ./Pre_Process/File_Name/Test_Chalky_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/Test_Shape ./Pre_Process/File_Name/Test_Shape_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/Train_Shape ./Pre_Process/File_Name/Train_Shape_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/Train_Chalky ./Pre_Process/File_Name/Train_Chalky_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/Test_Normal ./Pre_Process/File_Name/Test_Normal_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/Train_Normal ./Pre_Process/File_Name/Train_Normal_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/reg_Chalky ./Pre_Process/File_Name/reg_Chalky_Name
./Pre_Process/File_Name/Read_Filename.sh ./samples/reg_Shape ./Pre_Process/File_Name/reg_Shape_Name

#make some files
mkdir ./Pre_Process/yml
mkdir ./Shape/Parameters
mkdir ./Chalky/Parameters
mkdir ./Classifier/Simple/Data

#compile source code
make