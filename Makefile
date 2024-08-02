TARGET=exec
CXX=g++
DEBUG=-g
WARN=-Wall
SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=$(DEBUG) $(WARN) $(SFML) -Iinclude -Iinclude/Interface
OBJDIR=obj
SRCDIR=src
INCDIR=include

OBJS=$(OBJDIR)/main.o $(OBJDIR)/Interface_Lig4.o $(OBJDIR)/Interface_Reversi.o $(OBJDIR)/Interface_Jogo.o $(OBJDIR)/Interface_Define_Jogo.o $(OBJDIR)/Botao.o $(OBJDIR)/Interface_Menu.o $(OBJDIR)/Interface_Define_Dimensao.o

all: $(OBJDIR) $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm -f $(OBJS)
	@./$(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Interface_Lig4.o: $(SRCDIR)/Interface/Interface_Lig4.cpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Lig4.cpp -o $(OBJDIR)/Interface_Lig4.o

$(OBJDIR)/Interface_Define_Jogo.o: $(SRCDIR)/Interface/Interface_Define_Jogo.cpp $(INCDIR)/Interface/Interface_Define_Jogo.hpp $(INCDIR)/Interface/Interface_Jogo.hpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Botao.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Jogo.cpp -o $(OBJDIR)/Interface_Define_Jogo.o

$(OBJDIR)/Interface_Reversi.o: $(SRCDIR)/Interface/Interface_Reversi.cpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Reversi.cpp -o $(OBJDIR)/Interface_Reversi.o

$(OBJDIR)/Interface_Define_Dimensao.o: $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp $(INCDIR)/Interface/Interface_Define_Dimensao.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp -o $(OBJDIR)/Interface_Define_Dimensao.o

$(OBJDIR)/Interface_Jogo.o: $(SRCDIR)/Interface/Interface_Jogo.cpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Jogo.cpp -o $(OBJDIR)/Interface_Jogo.o

$(OBJDIR)/Botao.o: $(SRCDIR)/Interface/Botao.cpp $(INCDIR)/Interface/Botao.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Botao.cpp -o $(OBJDIR)/Botao.o

$(OBJDIR)/Interface_Menu.o: $(SRCDIR)/Interface/Interface_Menu.cpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Menu.cpp -o $(OBJDIR)/Interface_Menu.o

clean:
	@rm -f $(OBJS) $(TARGET)

.PHONY: all test clean

