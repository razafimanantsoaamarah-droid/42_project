#include "soraty.h"

int main(void)
{
    char *name = "Rakoto";
    int age = 30;
    unsigned int score = 100;
    void *ptr = &age;
    
    // Test avec template literals ${}
    soraty("Salama ${name}, manana ${age} taona ianao!\n", name, age);
    soraty("Ny isa: ${age}, ny anarana: ${name}\n", age, name);
    soraty("Score: ${score}, Pointeur: ${ptr}\n", score, ptr);
    
    // Test avec format classique % (pour compatibilité)
    soraty_classic("Version classique: %s a %d ans\n", "Rabe", 25);
    
    // Test mixte (mais attention: ${} et % ne sont pas compatibles dans la même fonction)
    // soraty("Mixte: ${name} a %d ans\n", name, 25); // Ça ne marchera pas correctement
    
    return (0);
}