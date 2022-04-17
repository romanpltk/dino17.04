#include "player.h"
#include "settings.h"
Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sprite.setScale(0.5f, 0.28f);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 13, WINDOW_HEIGHT / 1.3 - g_bounds.height);
}
void Player::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!isJump) {
			isJump = true;
			speed = -14.f;
		}
	}
	if (isJump) {
		speed += 0.5f;
		if (speed > 13.5f) {
			isJump = false;
			speed = 0;
		}
	}
	sprite.move(0, speed);
}
void Player::draw(sf::RenderWindow & window) { window.draw(sprite); }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }