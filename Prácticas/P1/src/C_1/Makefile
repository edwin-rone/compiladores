# Variables
CXX = g++
FLEX = flex++
TARGET = compiler

# Regla principal
all: $(TARGET)

# Compilacion del programa final
$(TARGET): Lexer.cpp main.cpp
	$(CXX) Lexer.cpp main.cpp -o $(TARGET)

# Generacion del escaner con Flex
Lexer.cpp: lexer.ll
	$(FLEX) lexer.ll

# Limpiar archivos generados
clean:
	rm -f $(TARGET) Lexer.cpp