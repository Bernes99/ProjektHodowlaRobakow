#include "Worm.h"

void Worm::loadSprite(std::string path)
{
	if (!texture.loadFromFile(path))
	{
		std::cout << "blad zaladowaia tekstury robaka";
		system("pause");
	}
	sprite.setTexture(texture);

}

void Worm::checkerFixPosition()
{
	checker.setPosition(sprite.getPosition().x + sprite.getScale().x * sprite.getTexture()->getSize().x / 2,
		checker.getPosition().y);
}

void Worm::setWormPosition(int positionX, int positionY)
{
	sprite.setPosition(positionX, positionY);
	checker.setPosition(sprite.getPosition().x - sprite.getTexture()->getSize().x / 2,
		sprite.getPosition().y + 4 * sprite.getTexture()->getSize().y / 5);

}

void Worm::movment(int worldSizeX, int worldSizeY,float dt)
{
	
	if (allowMove)
	{
		/*Losowanie kierunku poruszania sie robaka i zmiana kierunku chodzenia */
		if (allowRandom)
		{
			prevX = xMove;
			prevY = yMove;
			xMove = 0;
			yMove = 0;

			xMove = rand() % (worldSizeX  - sprite.getTexture()->getSize().x/2 );
			while (prevX == xMove)
			{
				xMove = rand() % (worldSizeX  - sprite.getTexture()->getSize().x / 2  );
			}

			yMove = rand() % (worldSizeY  );
			while (prevY == yMove)
			{
				yMove = rand() % (worldSizeY   );
			}
			//std::cout << yMove;

			allowRandom = false;
			/* obs�uga zmiany kierunku robaka*/
			if (checker.getPosition().x < xMove)
			{
				int x= sprite.getPosition().x;
				sprite.setScale(-abs(sprite.getScale().x), sprite.getScale().y);
				if (!isPrevRight)
				{
					sprite.setPosition(x + abs(sprite.getScale().x)*sprite.getTexture()->getSize().x,
						sprite.getPosition().y);
					
				}
				//checkerFixPosition();
				isPrevRight = true;
			}
			else
			{
				int x = sprite.getPosition().x;
				sprite.setScale(abs(sprite.getScale().x), sprite.getScale().y);
				if (isPrevRight)
				{
					sprite.setPosition(x - abs(sprite.getScale().x) * sprite.getTexture()->getSize().x,
						sprite.getPosition().y);
					
				}
				//checkerFixPosition();
				isPrevRight = false;
			}
			//std::cout << yMove << "aaaaaa" << xMove;
		}

		/*zabezpieczenie wyjscia poza plansze z prawej*/
		if (checker.getPosition().x > worldSizeX )
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(-2, 0);
			checker.move(-2, 0);
			allowRandom = true;
			//sprite.move(0, 0);
		}

		/*zabezpieczenie wyjscia poza plansze z dolu*/
		else if (checker.getPosition().y > worldSizeY )
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(0, -2);
			checker.move(0, -2);
			allowRandom = true;
			//sprite.move(0, 0);
		}

		/*zabezpieczenie wyjscia poza plansze z gory*/
		else if (checker.getPosition().y <0)
		{
			//std::cout << sprite.getPosition().x;
			sprite.move(0, 2);
			checker.move(0, 2);
			allowRandom = true;
			//sprite.move(0, 0);
		}
		
		/*zabezpieczenie wyjscia poza plansze z lewej*/
		else if (checker.getPosition().x < 0)
		{
			std::cout << sprite.getPosition().x;
			sprite.move(2, 0);
			checker.move(2, 0);
			allowRandom = true;
			//sprite.move(0, 0);
		}
		
		/*gdy robak jest poza zakresem wylosowanego x i y z dopuszczalnym b��dem*/
		else if (checker.getPosition().x > xMove+0.5f || checker.getPosition().x < xMove - 0.5f||
			checker.getPosition().y > yMove + 0.5f || checker.getPosition().y < yMove - 0.5f)
		{
			if (checker.getPosition().x < xMove)
			{
				sprite.move(speed * dt, 0);
				checker.move(speed * dt, 0);
			}
			else
			{
				sprite.move(-speed * dt, 0);
				checker.move(-speed * dt, 0);
			}
			if (checker.getPosition().y < yMove)
			{
				sprite.move(0,speed * dt);
				checker.move(0, speed * dt);
			}
			else
			{
				sprite.move(0, -speed * dt);
				checker.move(0, -speed * dt);
			}
			
			//std::cout << dt << std::endl;
		}
		/* gdy robak jest juz w przedziale to sie zatrzymuje*/
		else
		{
			sprite.move(0, 0);
			allowMove = false;
			timer.restart();	
			allowRandom = true;
			
		}
	}
	else if (timer.getElapsedTime().asSeconds() > howLongStay)
	{
		allowMove = true;
	}
	
}

Worm::Worm(int wormPosX, int wormPosY)
{

	loadSprite("../Resources/Textures/worm.png");

	srand(time(NULL));
	allowRandom = true;
	sprite.setPosition(wormPosX, wormPosY);
	

	xMove = sprite.getPosition().x;
	yMove = sprite.getPosition().y;

	checker.setSize(sf::Vector2f(1,1));
	checker.setPosition(sprite.getPosition().x - sprite.getTexture()->getSize().x / 2,
						sprite.getPosition().y + 4*sprite.getTexture()->getSize().y/5);
	
	timer.restart();
	
	checker.setFillColor(sf::Color::Blue);
}

sf::Sprite Worm::getWorm()
{
	return sprite;
}

sf::RectangleShape Worm::getChecker()
{
	return checker;
}

void Worm::reScale()
{
	if (sprite.getScale().x>0)
	{
		if (eaten >= 10 && maxScale > abs(sprite.getScale().x))
		{
			sprite.setScale(sprite.getScale().x + 0.25f, sprite.getScale().y + 0.25f);
			sprite.setPosition(sprite.getPosition().x,
				sprite.getPosition().y - sprite.getTexture()->getSize().y / 4);

			checkerFixPosition();

			eaten = 0;
		}
	}
	else // gdzy robak bedzie w lewo trzeba skalowanie robic dla ujemnych
	{
		if (eaten >= 10 && maxScale > abs(sprite.getScale().x))
		{
			sprite.setScale(sprite.getScale().x - 0.25f, sprite.getScale().y + 0.25f);
			sprite.setPosition(sprite.getPosition().x,
				sprite.getPosition().y - sprite.getTexture()->getSize().y / 4);

			checkerFixPosition();

			eaten = 0;
		}
	}
	

}

void Worm::setMaxScale(int maxScale)
{
	this->maxScale = maxScale;
}

bool Worm::wormDeath()
{
	if (deathTime.getElapsedTime().asSeconds() >=maxLifeTime)
	{
		return true;
	}
	else if(deathTime.getElapsedTime().asSeconds() > maxLifeTime*0.90f)
	{
		sprite.setColor(sf::Color::Red);
	}
	return false;
}

bool Worm::isMature()
{
	if (deathTime.getElapsedTime().asSeconds() >= maxLifeTime * 0.1f)
	{
		return true;
	}
	return false;
}




