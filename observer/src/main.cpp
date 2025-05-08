#include "GameManager.h"

int main() {
    GameManager gameManager;

    // Inisialisasi game
    if (!gameManager.init()) {
        return -1;
    }

    // Jalankan game loop
    gameManager.run();

    // Bersihkan resource
    gameManager.cleanup();

    return 0;
}