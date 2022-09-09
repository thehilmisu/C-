
	#Compiling in Linux
	#~~~~~~~~~~~~~~~~~~
	#You will need a modern C++ compiler, so update yours!
	#To compile use the command:
	#g++ -o YourProgName YourSource.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17
	#On some Linux configurations, the frame rate is locked to the refresh
	#rate of the monitor. This engine tries to unlock it but may not be
	#able to, in which case try launching your program like this:
	#vblank_mode=0 ./YourProgName

    g++ -o YourProgName $1 -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17

    #vblank_mode=0 ./YourProgName

    ./YourProgName

