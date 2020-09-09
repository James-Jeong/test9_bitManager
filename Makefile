include makefile.conf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(WOPTION) -c $(SRCS)
#	$(CC) -o $@ $^
	g++ -o mainTest mainTest.cc main.c -isystem ${GTEST_SRC_HOME}/include -L${GTEST_SRC_HOME}/build -pthread -lgtest

clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)
	$(RM) mainTest

