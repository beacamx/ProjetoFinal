TARGET=exec
CXX=g++
DEBUG=-g
WARN=-Wall
OBJDIR=obj
SRCDIR=src
INCDIR=include
SFML_DIR_BUILD=libs/SFML-2.6.1/build
SFML_INCLUDE_DIR=libs/SFML-2.6.1/include/SFML
SFML_LIB_DIR=$(SFML_DIR_BUILD)/lib
FREE_TYPE_DIR=libs/SFML-2.6.1/extlibs/headers/freetype2
OGG_DIR=libs/SFML-2.6.1/extlibs/headers/ogg
VORBIS_DIR=libs/SFML-2.6.1/extlibs/headers/vorbis
STB_IMAGE_DIR=libs/SFML-2.6.1/extlibs/headers/stb_image
CXXFLAGS=$(DEBUG) $(WARN) -Iinclude -Iinclude/Interface -I$(SFML_INCLUDE_DIR) -I$(FREE_TYPE_DIR) -I$(OGG_DIR) -I$(VORBIS_DIR) -I$(STB_IMAGE_DIR)
LDFLAGS=-L$(SFML_LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lfreetype -logg -lvorbis -lvorbisfile

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    OS = linux
    RM = rm -f
    MKDIR = mkdir -p
    RUN = ./$(TARGET)
    EXT =
else
    OS = windows
    RM = del /Q
    MKDIR = mkdir
    RUN = .\$(TARGET).exe
    EXT = .exe
endif

OBJS=$(OBJDIR)/main.o $(OBJDIR)/Interface_Lig4.o \
	$(OBJDIR)/Interface_Reversi.o $(OBJDIR)/Interface_Jogo.o \
	$(OBJDIR)/Interface_Define_Jogo.o $(OBJDIR)/Interface_Menu.o \
	$(OBJDIR)/Interface_Define_Dimensao.o $(OBJDIR)/Caixa_de_texto.o \
	$(OBJDIR)/Interface_Login_Jogador1.o $(OBJDIR)/Interface_Login_Jogador2.o \
	$(OBJDIR)/Interface_Definicao_Entrada_Jogador1.o $(OBJDIR)/Interface_Definicao_Entrada_Jogador2.o \
	$(OBJDIR)/Interface_Cadastro_Jogador1.o $(OBJDIR)/Interface_Cadastro_Jogador2.o \
	$(OBJDIR)/Interface_Tela_Inicial.o $(OBJDIR)/Troca_Definicao_Entrada_Jogador.o \
	$(OBJDIR)/jogador.o $(OBJDIR)/Cadastro_Jogadores.o 

all: $(OBJDIR) $(TARGET)$(EXT)

$(TARGET)$(EXT): $(OBJS)
	$(CXX) -o $(TARGET)$(EXT) $(OBJS) $(LDFLAGS)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/jogador.o: $(SRCDIR)/jogador.cpp $(INCDIR)/jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/jogador.cpp -o $(OBJDIR)/jogador.o	

$(OBJDIR)/Cadastro_Jogadores.o: $(SRCDIR)/Cadastro_Jogadores.cpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Cadastro_Jogadores.cpp -o $(OBJDIR)/Cadastro_Jogadores.o	

$(OBJDIR)/Interface_Login_Jogador1.o: $(SRCDIR)/Interface/Interface_Login_Jogador1.cpp $(INCDIR)/Interface/Interface_Login_Jogador1.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Caixa_de_texto.hpp $(INCDIR)/Interface/Troca_Definicao_Entrada_Jogador.hpp $(INCDIR)/Cadastro_Jogadores.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Login_Jogador1.cpp -o $(OBJDIR)/Interface_Login_Jogador1.o

$(OBJDIR)/Interface_Login_Jogador2.o: $(SRCDIR)/Interface/Interface_Login_Jogador2.cpp $(INCDIR)/Interface/Interface_Login_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Login_Jogador2.cpp -o $(OBJDIR)/Interface_Login_Jogador2.o	

$(OBJDIR)/Interface_Cadastro_Jogador1.o: $(SRCDIR)/Interface/Interface_Cadastro_Jogador1.cpp $(INCDIR)/Interface/Interface_Cadastro_Jogador1.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Cadastro_Jogador1.cpp -o $(OBJDIR)/Interface_Cadastro_Jogador1.o

$(OBJDIR)/Interface_Cadastro_Jogador2.o: $(SRCDIR)/Interface/Interface_Cadastro_Jogador2.cpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Cadastro_Jogador2.cpp -o $(OBJDIR)/Interface_Cadastro_Jogador2.o

$(OBJDIR)/Interface_Definicao_Entrada_Jogador1.o: $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.cpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Login_Jogador1.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador1.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.cpp -o $(OBJDIR)/Interface_Definicao_Entrada_Jogador1.o

$(OBJDIR)/Interface_Definicao_Entrada_Jogador2.o: $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.cpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Login_Jogador2.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.cpp -o $(OBJDIR)/Interface_Definicao_Entrada_Jogador2.o

$(OBJDIR)/Interface_Tela_Inicial.o: $(SRCDIR)/Interface/Interface_Tela_Inicial.cpp $(INCDIR)/Interface/Interface_Tela_Inicial.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Tela_Inicial.cpp -o $(OBJDIR)/Interface_Tela_Inicial.o

$(OBJDIR)/Troca_Definicao_Entrada_Jogador.o: $(SRCDIR)/Interface/Troca_Definicao_Entrada_Jogador.cpp $(INCDIR)/Interface/Troca_Definicao_Entrada_Jogador.hpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Troca_Definicao_Entrada_Jogador.cpp -o $(OBJDIR)/Troca_Definicao_Entrada_Jogador.o

$(OBJDIR)/Caixa_de_texto.o: $(SRCDIR)/Interface/Caixa_de_texto.cpp $(INCDIR)/Interface/Caixa_de_texto.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Caixa_de_texto.cpp -o $(OBJDIR)/Caixa_de_texto.o

$(OBJDIR)/Interface_Lig4.o: $(SRCDIR)/Interface/Interface_Lig4.cpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Lig4.cpp -o $(OBJDIR)/Interface_Lig4.o

$(OBJDIR)/Interface_Define_Jogo.o: $(SRCDIR)/Interface/Interface_Define_Jogo.cpp $(INCDIR)/Interface/Interface_Define_Jogo.hpp $(INCDIR)/Interface/Interface_Jogo.hpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Jogo.cpp -o $(OBJDIR)/Interface_Define_Jogo.o

$(OBJDIR)/Interface_Reversi.o: $(SRCDIR)/Interface/Interface_Reversi.cpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Reversi.cpp -o $(OBJDIR)/Interface_Reversi.o

$(OBJDIR)/Interface_Define_Dimensao.o: $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp $(INCDIR)/Interface/Interface_Define_Dimensao.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp -o $(OBJDIR)/Interface_Define_Dimensao.o

$(OBJDIR)/Interface_Jogo.o: $(SRCDIR)/Interface/Interface_Jogo.cpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Jogo.cpp -o $(OBJDIR)/Interface_Jogo.o

$(OBJDIR)/Interface_Menu.o: $(SRCDIR)/Interface/Interface_Menu.cpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Menu.cpp -o $(OBJDIR)/Interface_Menu.o

clean:
	$(RM) $(OBJDIR)/*.o $(TARGET)$(EXT)

run: all
	$(RUN)