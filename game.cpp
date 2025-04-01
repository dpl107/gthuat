#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
TTF_Font* font = nullptr;

struct Player {
    int hearts = 5;
    int points = 0;
};

struct Monster {
    int health;
    bool isBoss;
};

vector<pair<string, string>> loadQuestions(const string& filename) {
    vector<pair<string, string>> questions;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        size_t delimiter = line.find('|');
        if (delimiter != string::npos) {
            string question = line.substr(0, delimiter);
            string answer = line.substr(delimiter + 1);
            questions.push_back({question, answer});
        }
    }
    file.close();
    return questions;
}

bool askQuestion(const vector<pair<string, string>>& questions, const string& type) {
    vector<pair<string, string>> filtered;
    for (const auto& q : questions) {
        if (q.first.find(type) == 0) {
            filtered.push_back({q.first.substr(3), q.second});
        }
    }
    if (!filtered.empty()) {
        auto q = filtered[rand() % filtered.size()];
        string question = q.first;
        string correctAnswer = q.second;
        cout << "Question: " << question << "\nEnter your answer: ";
        string answer;
        cin.ignore();
        getline(cin, answer);
        if (answer == correctAnswer) {
            cout << "Correct! Reward granted!\n";
            return true;
        } else {
            cout << "Wrong answer! No reward.\n";
            return false;
        }
    }
    return false;
}

void renderText(const string& text, int x, int y) {
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void gameLoop(Player& player, vector<pair<string, string>>& questions) {
    bool running = true;
    SDL_Event e;
    while (running && player.hearts > 0) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        renderText("Player Hearts: " + to_string(player.hearts), 50, 50);
        renderText("Points: " + to_string(player.points), 50, 100);
        SDL_RenderPresent(renderer);
    }
}

int main() {
    srand(time(0));
    if (SDL_Init(SDL_INIT_VIDEO) < 0 || TTF_Init() == -1) {
        cout << "SDL Initialization Failed!\n";
        return 1;
    }
    window = SDL_CreateWindow("Adventure Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("arial.ttf", 24);
    if (!font) {
        cout << "Failed to load font!\n";
        return 1;
    }
    Player player;
    vector<pair<string, string>> questions = loadQuestions("questions.txt");
    gameLoop(player, questions);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
