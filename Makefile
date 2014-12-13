SOURCES=Player.cpp cards/ShieldBlast.cpp cards/MachineGun.cpp cards/HireScientist.cpp cards/ScienceTheft.cpp cards/ProjectOmega.cpp cards/Plague.cpp cards/MakeWar.cpp cards/Briefing.cpp cards/DamageCard.cpp cards/AssassinsTeleport.cpp cards/Technocracy.cpp cards/PowerPlant.cpp main.cpp InputHandler.cpp Human.cpp Texture.cpp AI.cpp Renderer.cpp Card.cpp
OBJECTS=$(addprefix obj/,$(SOURCES:.cpp=.o))
EXECUTABLE=MakeWarNotScience

ifeq ($(target),windows)
	CFLAGS=-c -std=c++11 -Wall -pedantic -g -Wl,subsystem,windows -ISDL2-2.0.3/i686-w64-mingw32/include/
	LDFLAGS= -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -LSDL2-2.0.3/i686-w64-mingw32/lib/

else
	CFLAGS=-c -std=c++11 -Wall -pedantic -g
	LDFLAGS= -lSDL2 -lSDL2_image -lSDL2_ttf
endif

all: create_dir $(SOURCES) $(EXECUTABLE)

create_dir:
	mkdir -p obj/cards
$(EXECUTABLE): $(OBJECTS) 
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

#.cpp.o:
$(OBJECTS): obj/%.o : %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -rf obj

# falešné cíle
.PHONY:
