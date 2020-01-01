C_SRC = $(wildcard *.cpp)
C_OBJ = $(patsubst %cpp, %o, $(C_SRC))
# 目标文件也是多个
TARGETLIST = $(patsubst %.cpp, %, $(C_SRC))

.PHONY:all clean
# 这句不写规则的语句可以自动把相应的a.c b.c编译成a b，神奇~
all:${TARGETLIST}

clean:  
	rm -f ${TARGETLIST} *.o 

