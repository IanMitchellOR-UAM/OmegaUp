// https://omegaup.com/arena/problem/Cadenas-de-digitos-y-coincidenci/#problems

#include <iostream>
#include <string>
#include <vector>

// Se define un vector global con los números primos de un dígito
std::vector<int> primes = {2, 3, 5, 7};

// Función que verifica si un dígito es un número primo de un dígito
bool is_valid_prime(int digit) {
    // Se recorre el vector de números primos
    for (int prime : primes) {
        // Si el dígito es igual a alguno de los primos, se retorna true
        if (digit == prime) {
            return true;
        }
    }
    // Si no se encuentra coincidencia, se retorna false
    return false;
}

// Función recursiva para generar números que cumplen con el patrón
void generate_numbers(const std::string& pattern, int idx, std::vector<bool>& used, int& count) {
    // Caso base: si se ha completado todo el patrón
    if (idx == pattern.size()) {
        // Se incrementa el contador de números válidos
        ++count;
        return;
    }
    
    // Se recorren los dígitos del 0 al 9
    for (int i = 0; i < 10; ++i) {
        // Si el dígito ya ha sido utilizado, se omite
        if (used[i]) continue;
        
        // Si el patrón en la posición actual requiere un primo ('p')
        // y el dígito actual no es primo, se omite
        if (pattern[idx] == 'p' && !is_valid_prime(i)) continue;

        // Se marca el dígito como utilizado
        used[i] = true;
        // Se realiza la llamada recursiva para el siguiente dígito del patrón
        generate_numbers(pattern, idx + 1, used, count);
        // Se desmarca el dígito para permitir su uso en otras combinaciones
        used[i] = false;
    }
}

// Función que cuenta cuántos números cumplen con el patrón dado
int count_valid_patterns(const std::string& pattern) {
    int count = 0; // Se inicializa el contador de números válidos
    std::vector<bool> used(10, false); // Vector para marcar los dígitos utilizados
    // Se realiza la llamada inicial a la función recursiva para generar números
    generate_numbers(pattern, 0, used, count);
    return count; // Se retorna el conteo total
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; // Variable para almacenar la longitud del patrón
    std::string pattern; // Variable para almacenar el patrón de dígitos
    std::cin >> N >> pattern; // Se lee la longitud del patrón y el patrón en sí

    // Se imprime el número de patrones válidos que cumplen con las restricciones
    std::cout << count_valid_patterns(pattern) << std::endl;

    return 0;
}
