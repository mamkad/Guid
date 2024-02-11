Guid:
	g++ -c Src/Guid.cpp
	ar rvs Guid.a Guid.o
	del Guid.o
	move Guid.a Bin/
	copy Src\Guid.hpp Bin\

GuidTest:
	g++ -o Guid Test/Main.cpp Bin/Guid.a ../../Algs/Hash/Md5/Bin/Md5.a
	move Guid.exe Test/Bin/
	Test/Bin/Guid.exe