CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS =		PasswordCrackwithMake.o

LIBS =		-lcrypto -pthread wordGenerator.cpp keyboardPattern.cpp HashTry.cpp

TARGET =	PasswordCrackwithMake

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
