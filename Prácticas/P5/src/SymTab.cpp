#include "headers/SymTab.hpp"

SymTab::SymTab() {}

// ============================================================
// EJERCICIO 2: Implementar addSym
// ============================================================
// Agrega un símbolo a la tabla de símbolos
// Parámetros:
//   id:   nombre del identificador
//   dir:  dirección de memoria asignada
//   tipo: ID del tipo (referencia a TypeTab)
//   cat:  categoría ("var", "func", "param")
// Retorna: true si se agregó, false si ya existía
//
// Hint: Verificar primero con existe(id), si no existe, insertar en el mapa
bool SymTab::addSym(string id, int dir, int tipo, string cat) {
    // TODO: Implementar
    // 1. Verificar si el id ya existe con existe(id)
    // 2. Si ya existe, retornar false
    // 3. Si no existe, crear un Sym(dir, tipo, cat) e insertarlo en syms[id]
    // 4. Retornar true
    
    // 1 y 2. Si ya existe en la tabla, no lo agregamos y regresamos false
    if (existe(id)) {
        return false; 
    }
    
    // 3. Si no existe, lo creamos y lo guardamos en el mapa
    syms[id] = Sym(dir, tipo, cat);
    
    // 4. Retornamos true porque se guardó bien
    return true;
}

// Versión para funciones (incluye lista de parámetros)
bool SymTab::addSym(string id, int dir, int tipo, string cat, vector<int> params) {
    // TODO: Implementar (similar al anterior pero usando el constructor con params)
    
    // Hacemos la misma validación que arriba
    if (existe(id)) {
        return false;
    }
    
    // Lo guardamos usando el constructor que acepta los parámetros
    syms[id] = Sym(dir, tipo, cat, params);
    
    return true;
}

// ============================================================
// EJERCICIO 2: Implementar existe
// ============================================================
// Verifica si un identificador ya existe en esta tabla de símbolos
// Parámetros:
//   id: nombre del identificador a buscar
// Retorna: true si existe, false si no
//
// Hint: Usar find() del map y comparar con syms.end()
bool SymTab::existe(string id) {
    // TODO: Implementar
    // Usar: syms.find(id) != syms.end()
    
    // Usamos find() para buscar en el mapa. Si no llega al final (end), es que sí lo encontró.
    return syms.find(id) != syms.end();
}

// Obtiene la dirección de un símbolo
int SymTab::getDir(string id) {
    if (existe(id)) {
        return syms[id].dir;
    }
    cerr << "Error: símbolo '" << id << "' no encontrado." << endl;
    return -1;
}

// Obtiene el tipo de un símbolo
int SymTab::getType(string id) {
    if (existe(id)) {
        return syms[id].tipo;
    }
    cerr << "Error: símbolo '" << id << "' no encontrado." << endl;
    return -1;
}

// Obtiene la categoría de un símbolo
string SymTab::getCat(string id) {
    if (existe(id)) {
        return syms[id].cat;
    }
    return "";
}

// Retorna el mapa completo
map<string, Sym> SymTab::getSyms() {
    return syms;
}

// Imprime la tabla de símbolos
void SymTab::print() {
    cout << "========== TABLA DE SIMBOLOS ==========" << endl;
    cout << "Nombre\t\tDir\tTipo\tCat" << endl;
    cout << "------\t\t---\t----\t---" << endl;
    for (auto& par : syms) {
        cout << par.first << "\t\t"
             << par.second.dir << "\t"
             << par.second.tipo << "\t"
             << par.second.cat << endl;
    }
    cout << "========================================" << endl;
}
