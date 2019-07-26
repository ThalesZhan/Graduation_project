main: main.cpp    
	g++  -o main main.cpp ./Pre_Process/pre_process.cpp ./Shape/Img_Pro/Shape_Process.cpp ./Chalky/Img_Pro/Chalky_Process.cpp ./Classifier/Simple/Char_Rec.cpp `pkg-config opencv --cflags --libs `  

clean:
	rm main
	rm -rf ./Chalky/Parameters
	rm -rf ./Shape/Parameters
	rm -rf ./Classifier/Simple/Data
	rm -rf ./Pre_Process/yml
	rm ./Pre_Process/File_Name/*.txt