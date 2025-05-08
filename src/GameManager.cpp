#include "GameManager.h"
#include <iostream>
#include <glad/glad.h>

GameManager::GameManager() : window(nullptr), health(3), scoreSystem(), ui(), sound() {}

GameManager::~GameManager() {}

bool GameManager::init() {
    // Inisialisasi GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Konfigurasi GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Membuat window
    window = glfwCreateWindow(800, 600, "Game Manager", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    // Inisialisasi GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Set viewport
    glViewport(0, 0, 800, 600);

    // Callback untuk resize window
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    return true;
}

void GameManager::run() {
    while (!glfwWindowShouldClose(window)) {
        // Hanya jalankan game jika ada input
        if (processInput()) {
            update();
            render();

            glfwSwapBuffers(window);
        }

        glfwPollEvents();
    }
}

void GameManager::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool GameManager::processInput() {
    bool inputDetected = false;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
        inputDetected = true;
    }

    // Simulasi event "attack" saat tombol A ditekan
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        inputDetected = true;

        if (health > 0) {
            health--; // Kurangi health
            sound.playAttackSound();
        }

        if (health == 0) {
            scoreSystem.addScore(100); // Tambah skor
            health = 3;               // Reset health
        }
    }

    return inputDetected;
}

void GameManager::update() {
    // Update game state di sini
}

void GameManager::render() {
    std::cout << "Rendering frame...\n";
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar kotak musuh
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    glVertex2f(-0.8f, -0.5f);    // Kiri bawah
    glVertex2f(-0.6f, -0.5f);    // Kanan bawah
    glVertex2f(-0.6f,  0.5f);    // Kanan atas
    glVertex2f(-0.8f,  0.5f);    // Kiri atas
    glEnd();

    // Gambar bar darah
    ui.drawHealthBar(health);

    // Tampilkan skor di console
    scoreSystem.displayScore();
}