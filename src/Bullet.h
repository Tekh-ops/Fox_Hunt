#pragma once

#include "Actor.h"

class Bullet: public Actor
{
private:
  class AnimSpriteComponent* m_AnimSpriteComponent;
  class CircleComponent* m_Circle;
public:
  Bullet(class Game* game, Vector2 forwardVector);

  void UpdateActor(float deltaTime) override;
  void HandleDeath() override;
};
