TARGET=exec
CXX=g++
DEBUG=-g
WARN=-Wall
OBJDIR=obj
SRCDIR=src
INCDIR=include
SFML_DIR_BUILD=libs/SFML-2.6.1/build
SFML_INCLUDE_DIR=libs/SFML-2.6.1/include/SFML
SFML_INCLUDE_DIR1=libs/SFML-2.6.1/include
SFML_LIB_DIR=$(SFML_DIR_BUILD)/lib
CXXFLAGS=$(DEBUG) $(WARN) -Iinclude -Iinclude/Interface -Iinclude/Interface/Classes_auxiliares -I$(SFML_INCLUDE_DIR1)
LDFLAGS=-L$(SFML_LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

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
	$(OBJDIR)/Jogador.o $(OBJDIR)/Cadastro_Jogadores.o \
	$(OBJDIR)/Textos.o $(OBJDIR)/Interface_Base.o \
	$(OBJDIR)/Avisos.o $(OBJDIR)/Interface_Cadastro_Base.o \
	$(OBJDIR)/Lig4.o $(OBJDIR)/Jogo.o \
	$(OBJDIR)/Interface_Login_Base.o $(OBJDIR)/Reversi.o \
	$(OBJDIR)/Interface_Define_Tipo_Operacao_Dados.o $(OBJDIR)/Interface_Remove_Jogador.o

export LD_LIBRARY_PATH := libs/SFML-2.6.1/build/lib:$(LD_LIBRARY_PATH)


all: $(OBJDIR) $(TARGET)$(EXT)

$(TARGET)$(EXT): $(OBJS)
	$(CXX) -o $(TARGET)$(EXT) $(OBJS) $(LDFLAGS)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Interface_Remove_Jogador.o: $(SRCDIR)/Interface/Interface_Remove_Jogador.cpp $(INCDIR)/Interface/Interface_Remove_Jogador.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Remove_Jogador.cpp -o $(OBJDIR)/Interface_Remove_Jogador.o

$(OBJDIR)/Reversi.o: $(SRCDIR)/Reversi.cpp $(INCDIR)/Reversi.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Reversi.cpp -o $(OBJDIR)/Reversi.o

$(OBJDIR)/Interface_Define_Tipo_Operacao_Dados.o: $(SRCDIR)/Interface/Interface_Define_Tipo_Operacao_Dados.cpp $(INCDIR)/Interface/Interface_Define_Tipo_Operacao_Dados.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Remove_Jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Tipo_Operacao_Dados.cpp -o $(OBJDIR)/Interface_Define_Tipo_Operacao_Dados.o

$(OBJDIR)/Jogador.o: $(SRCDIR)/Jogador.cpp $(INCDIR)/Jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Jogador.cpp -o $(OBJDIR)/Jogador.o	

$(OBJDIR)/Lig4.o: $(SRCDIR)/Lig4.cpp $(INCDIR)/Lig4.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Lig4.cpp -o $(OBJDIR)/Lig4.o

$(OBJDIR)/Jogo.o: $(SRCDIR)/Jogo.cpp $(INCDIR)/Jogo.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp $(INCDIR)/Jogo.hpp $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Jogo.cpp -o $(OBJDIR)/Jogo.o	

$(OBJDIR)/Interface_Cadastro_Base.o: $(SRCDIR)/Interface/Interface_Cadastro_Base.cpp $(INCDIR)/Interface/Interface_Cadastro_Base.hpp $(INCDIR)/Interface/Interface_Menu.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Cadastro_Base.cpp -o $(OBJDIR)/Interface_Cadastro_Base.o

$(OBJDIR)/Interface_Login_Base.o: $(SRCDIR)/Interface/Interface_Login_Base.cpp $(INCDIR)/Interface/Interface_Login_Base.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp 
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Login_Base.cpp -o $(OBJDIR)/Interface_Login_Base.o

$(OBJDIR)/Interface_Base.o: $(SRCDIR)/Interface/Interface_Base.cpp $(INCDIR)/Interface/Interface_Base.hpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp 
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Base.cpp -o $(OBJDIR)/Interface_Base.o

$(OBJDIR)/Textos.o: $(SRCDIR)/Interface/Classes_auxiliares/Textos.cpp $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Classes_auxiliares/Textos.cpp -o $(OBJDIR)/Textos.o

$(OBJDIR)/Avisos.o: $(SRCDIR)/Interface/Classes_auxiliares/Avisos.cpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Classes_auxiliares/Avisos.cpp -o $(OBJDIR)/Avisos.o

$(OBJDIR)/Cadastro_Jogadores.o: $(SRCDIR)/Cadastro_Jogadores.cpp $(INCDIR)/Cadastro_Jogadores.hpp $(INCDIR)/Jogador.hpp 
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Cadastro_Jogadores.cpp -o $(OBJDIR)/Cadastro_Jogadores.o	

$(OBJDIR)/Interface_Login_Jogador1.o: $(SRCDIR)/Interface/Interface_Login_Jogador1.cpp $(INCDIR)/Interface/Interface_Login_Jogador1.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.hpp $(INCDIR)/Interface/Classes_auxiliares/Troca_Definicao_Entrada_Jogador.hpp $(INCDIR)/Cadastro_Jogadores.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp $(INCDIR)/Interface/Interface_Define_Jogo.hpp $(INCDIR)/Interface/Interface_Login_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Login_Jogador1.cpp -o $(OBJDIR)/Interface_Login_Jogador1.o

$(OBJDIR)/Interface_Login_Jogador2.o: $(SRCDIR)/Interface/Interface_Login_Jogador2.cpp $(INCDIR)/Interface/Interface_Login_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp $(INCDIR)/Interface/Interface_Login_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Login_Jogador2.cpp -o $(OBJDIR)/Interface_Login_Jogador2.o	

$(OBJDIR)/Interface_Cadastro_Jogador1.o: $(SRCDIR)/Interface/Interface_Cadastro_Jogador1.cpp $(INCDIR)/Interface/Interface_Cadastro_Jogador1.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp   $(INCDIR)/Interface/Classes_auxiliares/Troca_Definicao_Entrada_Jogador.hpp $(INCDIR)/Interface/Interface_Cadastro_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Cadastro_Jogador1.cpp -o $(OBJDIR)/Interface_Cadastro_Jogador1.o

$(OBJDIR)/Interface_Cadastro_Jogador2.o: $(SRCDIR)/Interface/Interface_Cadastro_Jogador2.cpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.hpp $(INCDIR)/Cadastro_Jogadores.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Classes_auxiliares/Avisos.hpp  $(INCDIR)/Interface/Interface_Cadastro_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Cadastro_Jogador2.cpp -o $(OBJDIR)/Interface_Cadastro_Jogador2.o

$(OBJDIR)/Interface_Definicao_Entrada_Jogador1.o: $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.cpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Login_Jogador1.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador1.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.cpp -o $(OBJDIR)/Interface_Definicao_Entrada_Jogador1.o

$(OBJDIR)/Interface_Definicao_Entrada_Jogador2.o: $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.cpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Login_Jogador2.hpp $(INCDIR)/Interface/Interface_Cadastro_Jogador2.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.cpp -o $(OBJDIR)/Interface_Definicao_Entrada_Jogador2.o

$(OBJDIR)/Interface_Tela_Inicial.o: $(SRCDIR)/Interface/Interface_Tela_Inicial.cpp $(INCDIR)/Interface/Interface_Tela_Inicial.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador1.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Interface_Define_Tipo_Operacao_Dados.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Tela_Inicial.cpp -o $(OBJDIR)/Interface_Tela_Inicial.o

$(OBJDIR)/Troca_Definicao_Entrada_Jogador.o: $(SRCDIR)/Interface/Classes_auxiliares/Troca_Definicao_Entrada_Jogador.cpp $(INCDIR)/Interface/Classes_auxiliares/Troca_Definicao_Entrada_Jogador.hpp $(INCDIR)/Interface/Interface_Definicao_Entrada_Jogador2.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Classes_auxiliares/Troca_Definicao_Entrada_Jogador.cpp -o $(OBJDIR)/Troca_Definicao_Entrada_Jogador.o

$(OBJDIR)/Caixa_de_texto.o: $(SRCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.cpp $(INCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Classes_auxiliares/Caixa_de_texto.cpp -o $(OBJDIR)/Caixa_de_texto.o

$(OBJDIR)/Interface_Lig4.o: $(SRCDIR)/Interface/Interface_Lig4.cpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Jogo.hpp $(INCDIR)/Lig4.hpp $(INCDIR)/Interface/Interface_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Lig4.cpp -o $(OBJDIR)/Interface_Lig4.o

$(OBJDIR)/Interface_Define_Jogo.o: $(SRCDIR)/Interface/Interface_Define_Jogo.cpp $(INCDIR)/Interface/Interface_Define_Jogo.hpp $(INCDIR)/Interface/Interface_Jogo.hpp $(INCDIR)/Interface/Interface_Lig4.hpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Menu.hpp $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Jogo.cpp -o $(OBJDIR)/Interface_Define_Jogo.o

$(OBJDIR)/Interface_Reversi.o: $(SRCDIR)/Interface/Interface_Reversi.cpp $(INCDIR)/Interface/Interface_Reversi.hpp $(INCDIR)/Interface/Interface_Jogo.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Reversi.cpp -o $(OBJDIR)/Interface_Reversi.o

$(OBJDIR)/Interface_Define_Dimensao.o: $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp $(INCDIR)/Interface/Interface_Define_Dimensao.hpp $(INCDIR)/Interface/Interface_Menu.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Define_Dimensao.cpp -o $(OBJDIR)/Interface_Define_Dimensao.o

$(OBJDIR)/Interface_Jogo.o: $(SRCDIR)/Interface/Interface_Jogo.cpp $(INCDIR)/Interface/Interface_Jogo.hpp $(INCDIR)/Interface/Interface_Base.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Jogo.cpp -o $(OBJDIR)/Interface_Jogo.o

$(OBJDIR)/Interface_Menu.o: $(SRCDIR)/Interface/Interface_Menu.cpp $(INCDIR)/Interface/Interface_Menu.hpp  $(INCDIR)/Interface/Classes_auxiliares/Textos.hpp $(INCDIR)/Interface/Interface_Base.hpp  
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface/Interface_Menu.cpp -o $(OBJDIR)/Interface_Menu.o

clean:
	$(RM) $(OBJDIR)/*.o $(TARGET)$(EXT)

run: all
	$(RUN)
