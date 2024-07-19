#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

// Определяем константы
const int MAX_SCORE = 21;
const int DEALER_STAND = 17;

// Структура для карты
struct Card {
    int value; // Значение карты: 1 для туза, 2-10 для карт с номерами, 10 для картинок (валет, дама, король)
};

// Функция для создания и перетасовки колоды
std::vector<Card> createDeck() {
    std::vector<Card> deck;
    for (int i = 1; i <= 13; ++i) {
        int value = (i > 10) ? 10 : i;
        for (int j = 0; j < 4; ++j) {
            deck.push_back({ value });
        }
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    return deck;
}

// Функция для получения карты из колоды
Card drawCard(std::vector<Card>& deck) {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Функция для игры в блэкджек
bool playBlackjack(std::vector<Card>& deck) {
    int playerScore = 0;
    int dealerScore = 0;

    // Дилер получает одну карту
    dealerScore += drawCard(deck).value;

    // Игрок получает две карты
    playerScore += drawCard(deck).value;
    playerScore += drawCard(deck).value;

    std::cout << "Your initial score: " << playerScore << "\n";

    // Ход игрока
    char choice;
    do {
        std::cout << "Do you want to hit (h) or stand (s)? ";
        std::cin >> choice;
        if (choice == 'h') {
            playerScore += drawCard(deck).value;
            std::cout << "Your score: " << playerScore << "\n";
            if (playerScore > MAX_SCORE) {
                std::cout << "You busted! Your score: " << playerScore << "\n";
                return false;
            }
        }
    } while (choice != 's');

    // Ход дилера
    while (dealerScore < DEALER_STAND) {
        dealerScore += drawCard(deck).value;
    }

    std::cout << "Dealer's score: " << dealerScore << "\n";

    // Определяем победителя
    if (dealerScore > MAX_SCORE || playerScore > dealerScore) {
        std::cout << "You win!\n";
        return true;
    }
    else {
        std::cout << "Dealer wins!\n";
        return false;
    }
}

int main() {
    std::vector<Card> deck = createDeck();
    playBlackjack(deck);
    return 0;
}
