TARGET=exec
CXX=g++
DEBUG=-g
WARN=-Wall
SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=$(DEBUG) $(WARN) $(SFML) -Iinclude -Iinclude/Interface
LD=g++
OBJDIR=obj
SRCDIR=src
INCDIR=include
OBJS=$(OBJDIR)/main.o $(OBJDIR)/Interface_Lig4.o $(OBJDIR)/Interface_Reversi.o $(OBJDIR)/Interface_Jogo.o

all: $(OBJDIR) $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm -f $(OBJS)
	@./$(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Interface_Lig4.o: $(SRCDIR)/Interface/Interface_Lig4.cpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Lig4.cpp -o $(OBJDIR)/Interface_Lig4.o

$(OBJDIR)/Interface_Reversi.o: $(SRCDIR)/Interface/Interface_Reversi.cpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Reversi.cpp -o $(OBJDIR)/Interface_Reversi.o

$(OBJDIR)/Interface_Jogo.o: $(SRCDIR)/Interface/Interface_Jogo.cpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Jogo.cpp -o $(OBJDIR)/Interface_Jogo.o

clean:
	@rm -f $(OBJS) $(TARGET)