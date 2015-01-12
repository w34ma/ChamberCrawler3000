CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3k
OBJECTS = main.o object.o character.o player.o human.o elves.o orc.o dwarf.o enemy.o dragon.o merchant.o generalenemy.o phoenix.o vampire.o goblin.o werewolf.o troll.o potion.o treasure.o floor.o factory.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
