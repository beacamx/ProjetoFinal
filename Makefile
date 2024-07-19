TARGET=exec
CXX=g++
DEBUG=-g
WARN=-Wall
SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=$(DEBUG) $(WARN) $(SFML) -Iinclude
LD=g++
OBJDIR=obj
SRCDIR=src
INCDIR=include
OBJS=$(OBJDIR)/main.o $(OBJDIR)/Interface_Lig4.o

all: $(OBJDIR) $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm -f $(OBJS)
	@./$(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Interface_Lig4.o: $(SRCDIR)/Interface_Lig4.cpp $(INCDIR)/Interface_Lig4.hpp
	$(CXX) -c $(CXXFLAGS) $(SRCDIR)/Interface_Lig4.cpp -o $(OBJDIR)/Interface_Lig4.o

clean:
	@rm -f $(OBJS) $(TARGET)