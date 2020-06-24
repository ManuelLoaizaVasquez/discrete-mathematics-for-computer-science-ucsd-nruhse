#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

// n x n grid, k diagonals
Long n, k;
Long cnt = 0;// Cantidad total de soluciones
Long cur = 0;// Cantidad actual de diagonales utilizadas
bool done = false;// Encontramos una solucion por primera vez
vector<vector<Long>> grid;

// Chequea si una posicion es valida
bool ok(int row, int col) {
    if (0 <= row and row < n and 0 <= col and col < n) return true;
    return false;
}

bool check(int row, int col, int val) {
    // Si en la casilla no coloque nada, esto siempre es valido
    if (val == 0) return true;
    // Si coloco un '/'
    if (val == 1) {
        if (ok(row, col - 1) and grid[row][col - 1] == 2) return false;
        if (ok(row - 1, col - 1) and grid[row - 1][col - 1] == 1) return false;
        if (ok(row - 1, col) and grid[row - 1][col] == 2) return false;
        return true;
    }
    // Si coloco un '\'
    if (val == 2) {
        if (ok(row, col - 1) and grid[row][col - 1] == 1) return false;
        if (ok(row - 1, col) and grid[row - 1][col] == 1) return false;
        if (ok(row - 1, col + 1) and grid[row - 1][col + 1] == 2) return false;
        return true;
    }
}

void find_solution(Long row, Long col) {
    // Si encuentro la cantidad de diagonales solicitada
    if (cur == k) {
        done = true;
        return;
    }
    // Si ya me pase de las n columnas
    if (row == n) return;
    // Pruebo los 3 posibles valores que puede tener una casilla
    // 0: ' '
    // 1: '/'
    // 2: '\'
    for (Long val = 0; val < 3; val++) {
        if (check(row, col, val)) {
            grid[row][col] = val;
            // si es una diagonal, acumulo
            if (val > 0) cur++;
            // Si me encuentro en al ultima columna de la fila actual, paso a la siguiente fila
            // sino continuo analizando esta fila
            if (col + 1 == n) find_solution(row + 1, 0);
            else find_solution(row, col + 1);
            // Cuando retiro el valor que coloque, tengo que tener cuidado que haya sido una diagonal
            if (val > 0) cur--;
            if (done) return;
        }
    }
}

/*
Long count_solutions(int row, int col) {
    if (cur == k) return 1LL;
    if (row == n) return 0LL;
    for (Long tipo = 0; tipo < 3; tipo++) {

    }
}
*/

int main() {
    cin >> n >> k;
    // Construyo la matriz
    for (int i = 0; i < n; i++) {
        vector<Long> temp;
        for (int j = 0; j < n; j++) temp.push_back(0);
        grid.push_back(temp);
    }
    find_solution(0, 0);
    for (int row = n - 1; row >= 0; row--) {
        for (int col = 0; col < n; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    //cout << count_solutions(0, 0) << endl;
    return 0;
}