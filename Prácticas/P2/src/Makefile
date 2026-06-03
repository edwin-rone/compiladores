# Variables de compilacion
CXX = g++
FLEX = flex++
TARGET = analyzer

# Regla principal
all: $(TARGET)

# Vinculacion y generacion del ejecutable final
$(TARGET): Lexer.cpp Parser.cpp main.cpp
	$(CXX) Lexer.cpp Parser.cpp main.cpp -o $(TARGET)

# Generacion del codigo C++ del analizador lexico
Lexer.cpp: lexer.ll
	$(FLEX) lexer.ll

# Limpieza de archivos autogenerados y binarios
clean:
	rm -f $(TARGET) Lexer.cpp