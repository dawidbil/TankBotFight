#include "KeyboardPlayer.hpp"

#include "SFML/Graphics.hpp"

KeyboardPlayer::KeyboardPlayer(Board& board, std::unique_ptr<Tank>&& tank)
    : mBoard(board),
      mTank(std::move(tank)),
      mController(std::make_unique<KeyboardController>(*mTank, mBoard)) {}

void KeyboardPlayer::draw(sf::RenderWindow& window) { mTank->draw(window); }

void KeyboardPlayer::handle_events(const sf::Event& event) { mController->update(event); }

void KeyboardPlayer::update() { mTank->update(); }

bool KeyboardPlayer::take_hit(unsigned int damage) {
  return mTank->take_hit(damage);
}

const Tank& KeyboardPlayer::get_tank() const { return *mTank; }
