OBJS:
	g++ *.cc -o main.exe -std=c++11 -llog4cpp -lpthread
	echo "#!/bin/bash" > main.sh
	echo "./main.exe" > main.sh
	chmod +x main.sh
	./main.sh
clean:
	rm main.exe
