#include "player.h"

int Player::addScore(int scoreToAdd) {
    this->score += scoreToAdd;
    return this->score;
}

int Player::getScore() const {
    return this->score;
}